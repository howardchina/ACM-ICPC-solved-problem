#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL ;
const int maxn = (1<<17) + 100;

vector<int>g[maxn],c[maxn] ;
int a[maxn], f[maxn] ;

void dfs(int u, int x){
    a[x] ++ ;
    for(size_t i=0; i<g[u].size(); i++){
        int v = g[u][i] ;
        if(v == f[u]) continue ;
        f[v] = u ;
        dfs(v , x^c[u][i]) ;
    }
}

int main()
{
    int T ;
    scanf("%d", &T) ;
    while(T--) {
        int N ;
        scanf("%d",&N) ;
        for(int i=0; i<=N; i++) g[i].clear() , c[i].clear();
        memset(a, 0 , sizeof(a)) ;

        for(int i=1; i<N; i++) {
            int u ,v , w;
            scanf("%d%d%d", &u, &v, &w) ;
            g[u].push_back(v) , c[u].push_back(w) ;
            g[v].push_back(u),  c[v].push_back(w) ;
        }

        f[1] = -1 ;
        dfs(1, 0) ;

        int Q , s;
        scanf("%d", &Q) ;
        while(Q--) {
            LL ans=0 ;
            scanf("%d", &s) ;
            if(s == 0) ans += N ;
            for(int u=(1<<17)-1; u>=0; u--) if(a[u]) {
                int v = s ^ u;
                if(a[v] == 0) continue ;

                if(v > u) continue ;
                else if(v < u) {
                    ans += (LL)a[u] * a[v] ;
                }
                else if(u == v) {
                    ans += (LL)a[u] * (a[u] - 1) / 2 ;
                }
            }
            printf("%I64d\n", ans) ;
        }

    }
    return 0;
}
