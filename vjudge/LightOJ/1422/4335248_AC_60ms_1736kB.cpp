#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 110;
int dp[N][N];
int c[N];
int main()
{
//    freopen("data.in","r",stdin);
    int T, n, cas=1;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        for(int i=0;i<n;i++) scanf("%d", &c[i]);
        memset(dp, 0, sizeof dp);
        for(int i=0;i<n;i++) dp[i][i] = 1;
        for(int i=n-2;i>=0;i--){
            for(int j=i;j<n;j++){
                dp[i][j] = dp[i+1][j]+1;
                for(int k=i+1;k<=j;k++){
                    if (c[i]==c[k]){
                        dp[i][j] = min(dp[i][j], dp[i+1][k] + dp[k+1][j]);
                    }
                }
            }
        }
        printf("Case %d: %d\n", cas++, dp[0][n-1]);
    }
    return 0;
}
