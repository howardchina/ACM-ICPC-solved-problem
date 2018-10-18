#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 55 ;
const int INF = 0x3f3f3f3f ;

vector<int>g[maxn],f[maxn] ;

int N ,M ,K;
int d1[maxn][1<<5] , d2[maxn][1<<5] , st[10] , ed[10] ;
bool inq[1<<11];

void spfa(int d[maxn][1<<5], int st[10])
{
    memset(d , 0x3f , (maxn<<5) * sizeof(int)) ;

    for(int i=1; i<=N; i++) d[i][0] = 0;
    memset(inq , 0, sizeof(inq)) ;
    queue<int>Q ;
    for(int i=0; i<K; i++) {
        int u = st[i] , s = 1 << i ;
        inq[u<<5|s] = true ;
        d[u][s] = 0 ;
        Q.push(u<<5|s) ;
    }

    while(!Q.empty()) {
        int tmp = Q.front() ;  Q.pop() ;
        inq[tmp] = false ;
        int u = tmp >> 5 ;
        int su = tmp & 31 ;

        for(size_t  i=0 ; i<g[u].size(); i++) {
            int v = g[u][i], w = f[u][i] ;
            for(int sv=(1<<K)-1; sv>=0; sv--) {
                if(d[v][sv|su] > d[v][sv] + d[u][su] + w) {
                    d[v][sv|su] = d[v][sv] + d[u][su] + w ;
                    int tmp = v<<5 | sv | su ;
                    if(!inq[tmp]) {
                        Q.push(tmp) ;
                        inq[tmp] = true ;
                    }
                }
            }
        }

    }

}

int trans[10] ;
int trans_state(int s) {
    int ret = 0;
    for(int i=0; i<K; i++) {
        if(s & (1<<i)) ret |= 1 << trans[i] ;
    }
    return ret ;
}

int dp[1<<5] , mis[1<<5], sta[1<<12] , val[1<<12], n ;


void solve()
{

    int ret = INF ;

    for(int i=0; i<K; i++) trans[i] = i ;
    do{
        n = 0;
        for(int i=1; i<=N; i++) {
            memset(mis, 0x3f , sizeof(mis));
            for(int u=(1<<K)-1; u>0; u--) {
                for(int v=(1<<K)-1; v>0; v--) {
                    int s = u & trans_state(v) ;
                    mis[s] = min(mis[s], d1[i][u] + d2[i][v]) ;
                }
            }
            for(int s=1; s<(1<<K); s++) if(mis[s] < INF) {
                sta[n] = s;
                val[n] = mis[s];
                n ++ ;
            }

        }

        memset(dp, 0x3f, sizeof(dp)) ;
        dp[0] = 0 ;
        for(int i=0; i<n; i++) {
            for(int s=(1<<K)-1; s>=0; s--) {
                if(dp[ s|sta[i] ] > dp[s] + val[i]) {
                    dp[ s|sta[i] ] = dp[s] + val[i] ;
                }
            }
        }
        ret = min(ret , dp[(1<<K)-1]) ;

    }while(next_permutation(trans, trans+K)) ;

    if(ret<INF) printf("%d\n" , ret) ;
    else  printf("No solution\n") ;
}


int main()
{
//    freopen("data.in", "r", stdin) ;

    int T;
    scanf("%d",&T) ;
    while(T--) {
        scanf("%d%d%d", &N, &M, &K) ;
        for(int i=0; i<=N; i++) g[i].clear() , f[i].clear() ;
        for(int i=1; i<=M; i++) {
            int u ,v , w;
            scanf("%d%d%d", &u, &v, &w) ;
            g[u].push_back(v),  f[u].push_back(w) ;
            g[v].push_back(u),  f[v].push_back(w) ;
        }
        for(int i=0; i<K; i++) st[i] = i + 1 , ed[i] = N - i ;
        spfa(d1 , st) ;
        spfa(d2 , ed) ;

        solve() ;

    }
    return 0;
}
