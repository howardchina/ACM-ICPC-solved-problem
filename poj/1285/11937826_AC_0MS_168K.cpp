#include <stdio.h>
#include <string.h>
typedef unsigned long long ull;
ull dp[55][55];
ull num[55];

int main()
{
//    freopen("test.in","r",stdin);
    int kase=0,n,m,v;
    while(scanf("%d%d",&n,&m)){
        if(n==0 && m==0) break;
        memset(num,0,sizeof(num));
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            scanf("%d",&v);
            num[v]++;
        }
        for(int i=0;i<=n;i++){
            dp[0][i]=0;
            dp[i][0]=1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                for(int k=0;k<=num[i]&&k<=j;k++){
                    dp[i][j]+=dp[i-1][j-k];
                }
            }
        }
        printf("Case %d:\n",++kase);
        while(m--){
            int q;
            scanf("%d",&q);
            printf("%I64u\n",dp[n][q]);
        }
    }
    return 0;
}
