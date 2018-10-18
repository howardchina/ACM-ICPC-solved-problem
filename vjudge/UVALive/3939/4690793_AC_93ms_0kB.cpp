#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1000050 ;
struct Node{
    int u , v, d , id ;
    void read() {
        scanf("%d%d%d", &u, &v, &d) ;
    }
    bool operator < (const Node &rhs) const {
        return d < rhs.d ;
    }
}edge[maxn], jour[maxn] ;


int fa[1005], ans[maxn], N , M , R ;
void init() {
    for(int i=0; i<=N; i++) fa[i] = i ;
}
int Find(int x) {
    return fa[x] == x ? x : fa[x] = Find(fa[x]) ;
}
void Union(int u , int v) {
    int fu = Find(u) , fv = Find(v) ;
    if(fu != fv) {
        fa[fv] = fu ;
    }
}

int main()
{
    int cas = 1 ;
    while(scanf("%d%d%d", &N, &M, &R)== 3) {
        init() ;
        for(int i=0; i<M; i++) edge[i].read() ;
        for(int i=0; i<R; i++) jour[i].id = i , jour[i].read() ;
        sort(edge, edge+M) ;
        sort(jour, jour+R) ;
        int e = M - 1 ;
        for(int j=R-1; j>=0; j--) {
            while(e>=0 && edge[e].d >= jour[j].d) {
                Union(edge[e].u , edge[e].v) ;
                e -- ;
            }
            ans[jour[j].id] = ( Find(jour[j].u) == Find(jour[j].v) ) ;
        }
        printf("Case %d:\n", cas++) ;
        for(int i=0; i<R; i++) {
            if(ans[i]) puts("yes") ;
            else puts("no") ;
        }
    }
    return 0;
}
