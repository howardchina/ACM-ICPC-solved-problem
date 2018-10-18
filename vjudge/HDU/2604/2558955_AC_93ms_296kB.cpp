#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define Clr(x) memset(x,0,sizeof x)
#define sz 4
int MOD;
int mem[3]={0,2,4};
int m[sz][sz]={{
    1,1,0,0},{//mm
    0,0,1,1},{//mf
    1,0,0,0},{//fm
    0,0,1,0}//ff
};
struct Mat{
    int x[sz][sz];
    Mat(){Clr(x);}
    Mat(int n){
        Clr(x);
        for(int i=0;i<sz;i++)x[i][i]=n;
    }
    void init(){
        memcpy(x,m,sizeof m);
    }
    int getAns(){
        int ans=0;
        for(int i=0;i<sz;i++)
        for(int j=0;j<sz;j++)
            ans+=x[i][j];
        return ans%MOD;
    }
    void print(){
        for(int i=0;i<sz;i++){
            for(int j=0;j<sz;j++)
                printf("%d ",x[i][j]);
            puts("");
        }
        puts("");
    }
};
Mat operator*(Mat a,Mat b){
    Mat s;
    for(int i=0;i<sz;i++)
    for(int j=0;j<sz;j++){
        if(a.x[i][j]==0) continue;
        for(int k=0;k<sz;k++)
            s.x[i][k]=(s.x[i][k]+a.x[i][j]*b.x[j][k])%MOD;
    }
    return s;
}
Mat operator^(Mat a,int b){
    Mat s(1);
    for(;b;b>>=1){
        if(b&1)s=s*a;
        a=a*a;
    }
    return s;
}
int main()
{
    int L,ans;
    while(scanf("%d%d",&L,&MOD)==2){
        if(L<3){
            ans=mem[L]%MOD;
        }else{
            Mat a;
            a.init();
            a=a^(L-2);
            ans=a.getAns();
        }
        printf("%d\n",ans);
    }
    return 0;
}
