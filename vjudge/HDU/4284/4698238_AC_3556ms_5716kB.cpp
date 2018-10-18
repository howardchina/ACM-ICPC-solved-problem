#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int INF= 0x3f3f3f3f ;

const int maxn = 105;
int N,M,Money,H, C[20], D[20], A[20] ;
int dis[maxn][maxn], g[20][20] ;
int dp[1<<16][16];

int main()
{
//    freopen("data.in", "r" ,stdin) ;

    int T ;
    scanf("%d", &T) ;
    while(T--) {
        scanf("%d%d%d", &N, &M, &Money) ;
        for(int i=1; i<=N; i++)
            for(int j=1; j<=N; j++)
                dis[i][j] = (i==j ? 0 : INF) ;
        for(int i=1; i<=M; i++) {
            int u , v, w ;
            scanf("%d%d%d", &u, &v, &w) ;
            dis[u][v] = dis[v][u] = min(dis[u][v] , w) ;
        }

        bool ok = false;
        scanf("%d", &H) ;
        int S = 0 ;

        for(int i=0; i<H; i++) {
            scanf("%d%d%d",&A[i] , &C[i] , &D[i]) ;
            if(A[i] == 1) ok = true , S = i ;
        }
        if(!ok) {
            C[H] = D[H] = 0;
            A[H] = 1 ;
            S = H ;
            H ++ ;
        }

        for(int k=1; k<=N; k++)
            for(int i=1; i<=N; i++)
                for(int j=1; j<=N; j++)
                    dis[i][j] = min(dis[i][j] , dis[i][k] + dis[k][j]);
        for(int i=0; i<H; i++)
            for(int j=0; j<H; j++)
                g[i][j] = dis[A[i]][A[j]] ;

        memset(dp, -1 , sizeof(dp)) ;

        dp[0][S] = Money ;

       for(int s=0; s<(1<<H); s++)  {
            for(int u=0; u<H; u++)
            {
                for(int v=0; v<H; v++) {
                    if(v == u) continue ;
                    if(dp[s][u] >= g[u][v]) {
                        int val = dp[s][u] - g[u][v] ;
                        if(val > dp[s][v]) {
                            dp[s][v] = val ;
                        }
                    }
                }

            }

            for(int u=0; u<H; u++)
            {
                if((s&(1<<u))==0 && dp[s][u] >= D[u]) {
                    int val = dp[s][u] + C[u] - D[u] ;
                    int ns = s | (1<<u) ;
                    if(val > dp[ns][u]) {
                        dp[ns][u] = val ;
                    }
                }
            }

       }

        if(dp[(1<<H)-1][S] >= 0) puts("YES") ;
        else puts("NO") ;

    }

    return 0;
}
