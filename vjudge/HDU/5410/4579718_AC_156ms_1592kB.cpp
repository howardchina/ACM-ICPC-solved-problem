#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int dp[2][2010][2];

int main()
{
//    freopen("data.in", "r", stdin);
    int T, M, N, w, a, b, k;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &M, &N);
        memset(dp, 0, sizeof dp);
        k = 0;
        for(int _i = 0; _i < N; _i++){
            scanf("%d%d%d", &w, &a, &b);
            k ^= 1;
            for(int i = 0; i <= M; i++){
                dp[k][i][0] = dp[k^1][i][0];
                if(i >= w){
                    dp[k][i][1] = dp[k^1][i - w][0] + a + b;
                    dp[k][i][1] = max(dp[k][i][1], dp[k][i-w][1] + a);
                }
            }

            for(int i = 0; i <= M; i++){
                dp[k][i][0] = max(dp[k][i][0], dp[k][i][1]);
            }
        }
        printf("%d\n", dp[k][M][0]);
    }
    return 0;
}
