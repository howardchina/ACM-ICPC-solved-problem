#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
typedef unsigned long long ULL;
struct Mat{
    ULL x[40][40];
    int n;
    Mat(){}
    Mat(int _n){n=_n;}
    void clear(){
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        x[i][j]=0;
    }
    void one(){
        clear();
        for(int i=0;i<n;i++)
        x[i][i]=1;
    }
    Mat operator*(const Mat&rhs)const{
        Mat s(n);
        s.clear();
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            if(x[i][j]==0)continue;
            for(int k=0;k<n;k++)
            s.x[i][k]+=x[i][j]*rhs.x[j][k];
        }
        return s;
    }
    Mat Pow(int b){
        Mat s(n);
        s.clear();
        s.one();
        Mat tmp=*this;
        for(;b;b>>=1){
            if(b&1)s=s*tmp;
            tmp=tmp*tmp;
        }
        return s;
    }
};
struct AC{
    bool end[40];
    int ch[40][26],f[40],top;
    void clrp(int idx){
        for(int c=0;c<26;c++)
            ch[idx][c]=0;
        f[idx]=0;end[idx]=0;
    }
    void init(){
        top=0;
        clrp(top);
    }
    int newNode(){clrp(++top);return top;}
    void insert(char* s){
        int n=strlen(s),x=0,c;
        for(int i=0;i<n;i++){
            c=s[i]-'a';
            if(!ch[x][c])ch[x][c]=newNode();
            x=ch[x][c];
        }
        end[x]=1;
    }
    void getFail(){
        queue<int>Q;
        for(int c=0;c<26;c++){
            int u=ch[0][c];
            if(u)Q.push(u);
        }
        while(!Q.empty()){
            int r=Q.front();Q.pop();
            if(end[f[r]])end[r]=1;
            for(int c=0;c<26;c++){
                int u=ch[r][c];
                int v=f[r];
                if(!u){ch[r][c]=ch[v][c];continue;}
                Q.push(u);
                while(v && !ch[v][c]) v=f[v];
                f[u]=ch[v][c];
            }
        }
    }
    Mat getMat(){
        Mat s(top+2);
        s.clear();
        for(int i=0;i<=top;i++){
            for(int c=0;c<26;c++)
            if(!end[ch[i][c]])
                s.x[i][ch[i][c]]++;
        }
        for(int i=0;i<s.n;i++){
            s.x[i][s.n-1]=1;
        }
        return s;
    }
};
AC ac;
int main(){
//    freopen("data.in","r",stdin);
    int N,L;
    char s[11];
    while(scanf("%d%d",&N,&L)==2){
        ac.init();
        for(int i=0;i<N;i++){
            scanf("%s",s);
            ac.insert(s);
        }
        ac.getFail();
        Mat a=ac.getMat();
        a=a.Pow(L);
        ULL tmp=0;
        for(int i=0;i<a.n;i++)
            tmp+=a.x[0][i];
        tmp--;
//        printf("%I64u\n",tmp);
        ULL ans=0;
        a=Mat(2);
        a.x[0][0]=26,a.x[0][1]=0;
        a.x[1][0]=a.x[1][1]=1;
        a=a.Pow(L);
        ans=a.x[0][0]+a.x[1][0]-1;
//        printf("%I64u\n",ans);
        printf("%I64u\n",ans-tmp);
    }
    return 0;
}
