#include <iostream>
#include <cstdio>
using namespace std;
typedef long long LL;
const LL MOD=1000000009;
LL dp[111][111],c[111][111];
char s[111],d[111];

void _init(){
    c[0][0]=1;
    for(int i=1;i<=100;i++){
        c[i][0]=1;
        for(int j=1;j<=i;j++){
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%MOD;
        }
    }
}

int main()
{
//    freopen("data.in","r",stdin);
    int n,k,m, i,j,t,x;
    _init();
    while(scanf("%d%d%d",&n,&k,&m)==3){
        scanf("%s",s);
        scanf("%s",d);
        x=0;
        for(i=0;i<n;i++)
            if(s[i]!=d[i])x++;
        for(i=0;i<=k;i++)
            for(j=0;j<=n;j++)
            dp[i][j]=0;
        dp[0][x]=1;
        for(i=0;i<k;i++)
            for(j=0;j<=n;j++){
                if(dp[i][j]==0)continue;
                for(t=max(0,m-(n-j));t<=j&&t<=m;t++)
                    dp[i+1][j-t+m-t]=(dp[i+1][j-t+m-t]+dp[i][j]*c[j][t]%MOD*c[n-j][m-t]%MOD)%MOD;
            }
        LL ans=dp[k][0];
        printf("%lld\n",ans);
    }
    return 0;
}
