#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;

int dp[1<<12][500 + 10], p[12][12];
int fac[14];
int main()
{
//    freopen("data.in", "r", stdin);
//    freopen("data.out", "w", stdout);
    fac[1] = 1;
    for(int i=2;i<=12;i++){
        fac[i] = fac[i-1] * i;
    }
    int T, n, m;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &n, &m);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%d", &p[i][j]);
            }
        }
        memset(dp, 0, sizeof dp);
        dp[0][0] = 1;
        int sz = (1<<n) - 1;
        for(int i = 0; i < sz; i++){
            int k = 0;
            for(int j = 0; j < n; j++){
                if (i & (1<<j)) k++;
            }
            for(int j = 0; j < n; j++){
                if (!(i & (1<<j))) {
                    for(int v = 0; v <= m; v++){
                        if (dp[i][v]){
                            int t = min(m, v + p[j][k]);
                            dp[i | (1<<j)][t] += dp[i][v];
                        }
                    }
                }
            }
        }
        int ans = dp[sz][m];
        if (ans){
            printf("%d/%d\n", fac[n]/__gcd(ans, fac[n]), ans/__gcd(ans, fac[n]));
        }
        else{
            puts("No solution");
        }
    }

    return 0;
}
