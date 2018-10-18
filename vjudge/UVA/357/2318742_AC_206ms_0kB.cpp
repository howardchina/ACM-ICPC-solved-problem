#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
typedef long long LL;
LL dp[5][30001];
int V[5] = {50, 25, 10, 5, 1};

LL DP(int d, int n){
    if(dp[d][n])
        return dp[d][n];
    if(d == 4)
        return dp[d][n] = 1;
    for(int j = n; j >= 0; j-=V[d])
        dp[d][n] += DP(d+1,j);
    return dp[d][n];
}

int main()
{
    int n;
    LL ans;
    memset(dp, 0, sizeof dp);
    while(scanf("%d", &n) != EOF){
        ans = DP(0, n);
        if(ans == 1)
            printf("There is only 1 way to produce %d cents change.\n", n);
        else
            printf("There are %lld ways to produce %d cents change.\n", ans, n);
    }
    return 0;
}
