#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int INF = 0x3f3f3f3f;
int dp[33][222];
int a[222];
int dis[222][222];
int N, K, cas = 1;

int DP(int k, int n){
    if(dp[k][n] != -1) return dp[k][n];
    if(k == 1)
        return dp[k][n] = dis[1][n];
    int Min = INF;
    for(int r = k-1; r < n; r++)
        Min = min(Min, DP(k-1, r) + dis[r+1][n]);
    return dp[k][n] = Min;
}

void Output(int k, int n){
    if(k == 1){
        if(1 == n)
            printf("Depot %d at restaurant %d serves restaurant %d\n", k, n, n);
        else
            printf("Depot %d at restaurant %d serves restaurants %d to %d\n", k, (1+n)/2, 1, n);
        return ;
    }
    for(int r = k-1; r < n; r++){
        if(DP(k-1, r) + dis[r+1][n] == DP(k, n)){
            Output(k-1, r);
            if(r+1 == n)
                printf("Depot %d at restaurant %d serves restaurant %d\n", k, n, n);
            else
                printf("Depot %d at restaurant %d serves restaurants %d to %d\n", k, (r+1+n)/2, r+1, n);
            return ;
        }
    }
}

int main()
{
//    freopen("data.in", "r", stdin);
    while(scanf("%d%d", &N, &K) != EOF && N+K){
        for(int i = 1; i <= N; i++)
            scanf("%d", &a[i]);
        for(int i = 1; i <= N; i++)
        for(int j = i; j <= N; j++){
            int m = (i+j)>>1;
            dis[i][j] = 0;
            for(int k = i; k <= j; k++)
                dis[i][j] += abs(a[k]- a[m]);
        }
        memset(dp, -1, sizeof dp);
        int ans = DP(K, N);
        printf("Chain %d\n", cas++);
        Output(K, N);
        printf("Total distance sum = %d\n\n", ans);
    }
    return 0;
}
