#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL ;
const int maxn = 100050 ;
int e1[maxn] , e2[maxn] , fa[maxn] ;
int val[maxn] ;
LL sum[maxn] ;
vector<int>g[maxn] ;

void dfs(int u) {
    sum[u] = val[u] ;
    for(size_t i=0; i<g[u].size(); i++) {
        int v = g[u][i] ;
        if(v == fa[u]) continue ;
        fa[v] = u;
        dfs(v) ;
        sum[u] += sum[v] ;
    }
}


int main()
{
//    freopen("data.in", "r", stdin) ;

    int cas = 1;
    int N , M ;
    while(scanf("%d%d", &N, &M) ==2 && N+M) {
        for(int i=1; i<=N; i++) {
            g[i].clear() ;
            scanf("%d", &val[i]) ;
        }
        for(int i=1; i<=M; i++) {
            int u ,v;
            scanf("%d%d", &u, &v) ;
            e1[i] = u , e2[i] = v ;
            g[u].push_back(v) ;
            g[v].push_back(u) ;
        }

        if(N==1) {
            printf("Case %d: %d\n", cas++ , val[1]) ;
            continue ;
        }

        fa[1] = -1 ;
        dfs(1) ;
        LL ans = 1e18 ;
        for(int i=1; i<=M; i++) {
            if(fa[e1[i]] == e2[i]) swap(e1[i] , e2[i]) ;
            if(fa[e2[i]] != e1[i]) while(1) ;
            LL tmp = abs( sum[1] - sum[e2[i]] - sum[e2[i]] ) ;
            ans = min(ans , tmp) ;
        }

        printf("Case %d: %lld\n", cas++ , ans) ;

    }
    return 0;
}
