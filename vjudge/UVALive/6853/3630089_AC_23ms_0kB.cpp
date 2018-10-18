#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f ;

int value[105][55] , cost[105][105];
int s , c ;
int dp[55][105] ;

int main()
{
    //freopen("in.txt", "r", stdin);

    int T;
    scanf("%d",&T) ;
    while(T--) {
        scanf("%d%d", &s, &c) ;
        for(int i=1; i<=s; i++) {
            for(int j=1; j<=c; j++) {
                scanf("%d" , &value[i][j]) ;
                dp[j][i] = -INF ;
            }
        }
        for(int i=1; i<=s; i++) {
            for(int j=1; j<=s; j++) scanf("%d", &cost[i][j]) ;
        }

        for(int i=1; i<=s; i++) dp[1][i] = value[i][1];
        for(int mon=1; mon<=c; mon++) {
            for(int u=1 ; u<=s; u++) {
                for(int v=1; v<=s; v++) {
                    dp[mon][v] = max(dp[mon][v] , dp[mon-1][u] + value[v][mon] - cost[u][v]) ;
                }
            }
        }

        int ans = 0 ;
        for(int i=1; i<=s; i++) {
            ans = max(ans , dp[c][i]) ;
        }
        printf("%d\n" , ans) ;

    }
    return 0;
}
