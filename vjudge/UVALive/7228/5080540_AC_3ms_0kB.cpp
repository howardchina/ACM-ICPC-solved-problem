#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cassert>
using namespace std;
const int INF = 0x3f3f3f3f ;
const int maxn = 5050 ;
const int maxm = maxn * 10 ;

#define clr(a,b) memset(a,b,sizeof(a))
struct Dinic{
    struct Edge{
        int u,v,f,next ;
        Edge(){} ;
        Edge(int u,int v,int f,int next) :
            u(u),v(v),f(f),next(next){} ;
    }edges[maxm];
    int tot,s,t;
    int head[maxn],cur[maxn],d[maxn],q[maxn] ;

    void init() { tot=0; clr(head ,-1) ;  }

    void add(int u,int v,int c) {  // printf("%d %d %d\n"  , u ,v, c) ;
        edges[tot] = Edge(u,v,c,head[u]) , head[u] = tot++ ;
        edges[tot] = Edge(v,u,0,head[v]) , head[v] = tot++ ;
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
            memcpy(cur , head , sizeof(cur)) ;
            ret += dfs( s , INF) ;
        }
        return ret ;
    }
}sol;

const int dx[] = {0,-1, 0, 1} ;
const int dy[] = {1, 0, -1, 0} ;
int a[55][55], N , M  ;
bool ingrid(int i ,int j){
    return 0<=i && i<N && 0<=j && j<M ;
}

int main()
{
   // freopen("data.in", "r" ,stdin) ;

    int CAS ;
    scanf("%d", &CAS) ;
    while(CAS--) {
        scanf("%d%d", &N, &M);

        int sum = 0 ;
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                scanf("%d", &a[i][j]) , sum += a[i][j];

        int S = N*M*2 , T = N*M*2+1 ;

        sol.init() ;
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                int u = i*M+j;
                u = u*2 ;
                sol.add(u+1 , T , a[i][j]) ;
                sol.add(S, u ,  a[i][j]) ;
                for(int dir=0; dir<4; dir++) {
                    int x = i + dx[dir] ;
                    int y = j + dy[dir] ;
                    int v = x*M + y ;
                    v = v * 2 + 1 ;
                    if(ingrid(x, y))
                        sol.add(u , v , INF) ;
                }
            }
        }

        int tmp = sol.max_flow(S, T) ;

        int ans = sum - tmp / 2 ;
        printf("%d\n" , ans) ;
    }
    return 0 ;
}
