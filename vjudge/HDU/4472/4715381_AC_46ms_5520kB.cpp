#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
const int maxn = 1000 + 10;
const int mod = 1000000007;
int dp[maxn][maxn];
int ans[maxn], cas = 1;
int main()
{
//    freopen("data.in", "r", stdin);
    LL t;
    dp[1][1] = 1;
    for(int j = 1; j <= 1000; j++){
        for(int i = 1; i <= 1000; i++){
            for(int k = j; i + k <= 1000; k+=j){
                t = (LL)dp[i+k][k] + dp[i][j];
                if (t >= mod) t -=mod;
                dp[i+k][k] = t;
            }
        }
    }
    for(int i = 1; i <= 1000; i++){
        t = 0;
        for(int j = 1; j <= i; j++){
            t += dp[i][j];
        }
        ans[i] = t%mod;
    }
    int n;
    while(scanf("%d", &n) != EOF){
        printf("Case %d: %d\n", cas++, ans[n]);
    }
    return 0;
}
