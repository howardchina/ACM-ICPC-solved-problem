#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cassert>
using namespace std;
const int INF = 0x3f3f3f3f ;
const int maxn = 100050 ;
const int maxm = maxn * 4 ;



#define clr(a,b) memset(a,b,(N+1)*sizeof(a[0]))
struct Dinic{
    struct Edge{
        int u,v,f,next ;
        Edge(){} ;
        Edge(int u,int v,int f,int next) :
            u(u),v(v),f(f),next(next){} ;
    }edges[maxm];
    int tot,s,t;
    int N ;
    int head[maxn],cur[maxn],d[maxn],q[maxn] ;

    void init(int n) { tot=0;  N = n;  clr(head ,-1) ; }

    void add(int u,int v,int c) {
        edges[tot] = Edge(u,v,c,head[u]) , head[u] = tot++ ;
        edges[tot] = Edge(v,u,c,head[v]) , head[v] = tot++ ;
    }

    bool bfs() {
        clr(d , -1);
        int rear = 0;
        d[s] = 0 , q[rear++] = s ;
        for(int i=0,u=q[i] ; i<rear ; u=q[++i]) {
            for(int p=head[u] ; ~p ; p=edges[p].next) {
                Edge & e = edges[p] ;
                if(d[e.v]==-1 && e.f) {
                    d[e.v] = d[u] + 1 ;
                    q[rear++] = e.v ;
                    if(e.v == t) return true;
                }
            }
        }
        return d[t] >= 0 ;
    }

    int dfs(int u,int a){
        if(u==t || a==0) return a ;
        int ret=0 , f;
        for(int &p = cur[u] ; ~p ; p=edges[p].next){
            Edge &e = edges[p] ;
            if(d[u]+1 == d[e.v] && (f = dfs(e.v , min(a , e.f))) > 0) {
                e.f -= f , edges[p^1].f += f ;
                ret += f , a -= f;
                if(a == 0 ) break ;
            }
        }
        return ret;
    }

    int max_flow(int s,int t) {
        this->s= s , this->t = t ;
        int ret= 0;
        while(bfs() ) {
            memcpy(cur , head , (N+1)*sizeof(cur[0])) ;
            ret += dfs( s , INF) ;
        }
        return ret ;
    }
}sol;





int main()
{
//    freopen("data.in","r" ,stdin) ;

    int T , N ,M ;
    scanf("%d", &T) ;
    while(T--) {
        scanf("%d%d", &N, &M) ;
        sol.init(N+2) ;

        int S=1, mi = INF , sink = 1 , ma = -INF ;
        for(int i=1; i<=N; i++) {
            int x, y ;
            scanf("%d%d", &x, &y) ;
            if(x < mi) mi = x , S = i;
            if(x > ma) ma = x , sink = i;
        }

        for(int i=1; i<=M; i++) {
            int x , y , c;
            scanf("%d%d%d", &x, &y, &c) ;
            sol.add(x , y , c) ;
        }
        int ans = sol.max_flow(S , sink) ;
        printf("%d\n" , ans) ;

    }

    return 0 ;
}
