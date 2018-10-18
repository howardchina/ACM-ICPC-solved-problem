#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cassert>
using namespace std;
const int INF = 0x3f3f3f3f ;
const int maxn = 1000 ;
const int maxm = maxn*maxn*2 ;

struct Dinic{
    #define clr(a,b) memset(a,b,sizeof(a))
    struct Edge{
        int u , v , c , f , next ;
        Edge(){} ;
        Edge(int u ,int v ,int c ,int f, int next) : u(u), v(v) ,c(c), f(f), next(next){} ;
    }edges[maxm];
    int tot , s ,t ;
    int head[maxn], cur[maxn], d[maxn], q[maxn], vis[maxn];

    void init() {tot = 0 ; clr(head, -1) ; } ;
    void add(int u , int v , int c) {
        edges[tot] = Edge(u , v , c , 0 , head[u]) , head[u] = tot ++ ;
        edges[tot] = Edge(v, u , 0 , 0 , head[v]) , head[v] = tot ++ ;
    }

    bool bfs() {
        clr(vis , 0) , clr(d , -1) ;
        int rear = 0 ;
        d[s] = 0 , vis[s] = 1 , q[rear++] = s ;
        for(int i=0,u=q[0]; i<rear; u=q[++i]) {
            for(int p=head[u]; ~p ; p=edges[p].next) {
                Edge &e = edges[p] ;
                if(!vis[e.v] && e.c > e.f) {
                    d[e.v] = d[u] + 1 ;
                    vis[e.v] = 1 , q[rear++] = e.v ;
                    if(e.v == t) return true ;
                }
            }
        }
        return vis[t] ;
    }
    int dfs(int u , int a) {
        if(u==t || a==0) return a ;
        int ret = 0 , f ;
        for(int &p=cur[u]; ~p ; p=edges[p].next) {
            Edge &e = edges[p] ;
            if(d[u]+1==d[e.v] && (f=dfs(e.v,min(a,e.c-e.f)))>0) {
                e.f += f , edges[p^1].f-=f;
                ret+=f , a-=f;
                if(a==0) break ;
            }
        }
        return ret ;
    }
    int max_flow(int s , int t) {
        this->s = s , this->t = t ;
        int ret = 0 ;
        while(bfs()) {
            memcpy(cur , head , sizeof(cur)) ;
            ret += dfs(s , INF) ;
        }
        return ret ;
    }
}sol;

int main()
{
   // freopen("in.txt", "r", stdin);

    int T , P , S , C , m ;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d%d%d", &P, &S , &C, &m) ;
        int start = 0 , finish = P+S+1 ;
        sol.init() ;
        for(int i=1; i<=P; i++) {
            sol.add(start , i , 1) ;
        }
        for(int i=1; i<=S; i++) {
            sol.add(P+i , finish , C) ;
        }
        for(int i=1; i<=m; i++) {
            int u , v ;
            scanf("%d%d", &u, &v) ;
            v += P ;
            sol.add(u , v , 1) ;
        }
        int ans = sol.max_flow(start , finish) ;
        printf("%d\n", ans) ;
    }
    return 0;
}
