#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
/**
2 1 0 0 0 0 0 0 0
2 0 1 0 0 0 0 0 0
2 0 0 0 0 0 0 0 0
2 0 0 0 0 0 0 0 0
2 0 0 0 0 0 0 0 0
2 0 0 0 0 0 0 0 0
2 0 0 0 0 0 0 0 0
2 0 0 0 0 0 0 0 0
2 0 0 0 0 0 0 0 0

52 18 6 0 0 0 0 0 0
48 16 6 0 0 0 0 0 0
36 12 4 0 0 0 0 0 0
36 12 4 0 0 0 0 0 0
36 12 4 0 0 0 0 0 0
36 12 4 0 0 0 0 0 0
36 12 4 0 0 0 0 0 0
36 12 4 0 0 0 0 0 0
36 12 4 0 0 0 0 0 0

76
**/
#define Clear(x) memset(x,0,sizeof x)
typedef long long LL;
const int MAXN=108,MAX=4,MOD=100000;
int sz;
struct Mat{
    int m[MAXN][MAXN];
    Mat(){Clear(m);}
    Mat(int x){
        Clear(m);
        for(int i=0;i<sz;i++)
            m[i][i]=x;
    }
};
Mat operator*(Mat a,Mat b){
    Mat ret;
    int i,j,k;
    for(i=0;i<sz;i++)
        for(j=0;j<sz;j++){
            if(a.m[i][j]==0) continue;
            for(k=0;k<sz;k++){
                int tmp=((LL)a.m[i][j]*b.m[j][k])%MOD;
                ret.m[i][k]=(ret.m[i][k]+tmp)%MOD;
            }
        }
    return ret;
}
Mat Pow(Mat a,int b){
    Mat ret(1);
    while(b){
        if(b&1)ret=ret*a;
        a=a*a;
        b>>=1;
    }
    return ret;
}
Mat dp;

int ch[MAXN][MAX],f[MAXN],top;
bool end[MAXN];
int idx(char ch){
    switch(ch){
        case 'A':return 0;
        case 'C':return 1;
        case 'G':return 2;
    }
    return 3;//T
}
void init(){
    top=0;
    Clear(end);
    Clear(f);Clear(ch);
}
int NewNode(){return ++top;}
void insert(char *s,int num){
    int x=0,n=strlen(s);
    for(int i=0;i<n;i++){
        int c=idx(s[i]);
        if(!ch[x][c]) ch[x][c]=NewNode();
        x=ch[x][c];
    }
    end[x]=true;
}
void getFail(){
    queue<int>Q;
    for(int c=0;c<MAX;c++){
        int &u=ch[0][c];
        if(u)Q.push(u);
    }
    while(!Q.empty()){
        int r=Q.front();Q.pop();
        if(end[f[r]])//!!!
            end[r]=true;
        for(int c=0;c<MAX;c++){
            int u=ch[r][c];
            int v=f[r];
            if(!u){ch[r][c]=ch[v][c];continue;}
            Q.push(u);
            while(v && !ch[v][c]) v=f[v];
            f[u]=ch[v][c];//!!
        }
    }
}
void getDP(){
    Clear(dp.m);
    for(int i=0;i<=top;i++){
        for(int j=0;j<MAX;j++){
            if(!end[ch[i][j]]) dp.m[i][ch[i][j]]++;
        }
    }
}
int main()
{
//    freopen("data.in","r",stdin);
    int n,m;
    char P[20];
    while(scanf("%d%d",&n,&m)==2){
        init();
        for(int i=1;i<=n;i++){
            scanf("%s",P);
            insert(P,i);
        }
        getFail();
        sz=top+1;
        getDP();
        dp=Pow(dp,m);
        int ans=0;
        for(int i=0;i<sz;i++){
            ans+=dp.m[0][i];
            ans%=MOD;
        }
        printf("%d\n",ans);
    }
    return 0;
}
