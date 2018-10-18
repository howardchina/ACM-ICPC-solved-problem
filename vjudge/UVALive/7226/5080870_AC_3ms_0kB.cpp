#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cassert>
using namespace std;
typedef long long LL ;
#define clr(a,b) memset(a , b ,sizeof(a))

const int INF = 0x3f3f3f3f ;
const int maxn = 550 ;
const int maxm = maxn * maxn * 2 ;

int  tot ;
int head[maxn],inq[maxn],d[maxn],pre[maxn],a[maxn];
struct Edge{
    int u,v,f,cost,next;
    Edge(){}
    Edge(int u,int v,int f,int cost,int next):
        u(u),v(v),f(f),cost(cost),next(next){};
}edges[maxm];

void init(){
    tot=0;
    clr(head , -1) ;
}
void add(int u,int v,int f,int cost){
    edges[tot] = Edge(u,v,f,cost,head[u]) , head[u]=tot++ ;
    edges[tot] = Edge(v,u,0,-cost,head[v]) , head[v] = tot++ ;
}

bool spfa(int s,int t,int &flow,int &cost) {
    clr(inq,0) , clr(d , 0x3f) ;
    d[s]=0 , inq[s]=1 , a[s]=INF , pre[s] = 0 ;
    queue<int>Q;
    Q.push(s) ;
    while(!Q.empty()) {
        int u = Q.front(); Q.pop() ;
        inq[u] = 0;
        for(int p=head[u]; ~p ; p=edges[p].next){
            Edge &e =edges[p];
            if(e.f && d[e.v]>d[u]+e.cost) {
                d[e.v] = d[u] + e.cost ;
                pre[e.v] = p ;
                a[e.v] = min(a[u] , e.f);
                if(!inq[e.v]) inq[e.v] = 1 , Q.push(e.v) ;
            }
        }
    }
    if(d[t] == INF) return false ;
    flow += a[t] , cost += a[t] * d[t] ;
    int u = t;
    while(u!=s) {
        edges[pre[u]].f -= a[t] ;
        edges[pre[u]^1].f += a[t];
        u = edges[pre[u]].u ;
    }
    return true;
}
int min_cost(int s,int t) {
    int cost =0 , flow = 0;
    while(spfa(s , t ,flow , cost)) ;
    return cost ;
}


int C[maxn] , D[maxn];

int main()
{
   // freopen("data.in", "r" ,stdin) ;

    int cas;
    scanf("%d", &cas) ;
    while(cas--) {
        int n , m ;
        scanf("%d%d", &n, &m) ;

        int S = 0 , T = n + 1 ;
        init() ;
        for(int i=1; i<=m; i++) {
            int u ,v ;
            scanf("%d%d", &u, &v) ;
            add(u, v , INF , 1) ;
        }

        for(int i=1; i<=n; i++) scanf("%d", &C[i]) ;
        for(int j=1; j<=n; j++) scanf("%d", &D[j]) ;

        for(int i=1; i<=n; i++) {
            if(C[i] == D[i]) continue ;
            else if (C[i] == 1) {
                add(S , i , 1 , 0) ;
            }
            else if(D[i] == 1) {
                add(i , T , 1 , 0) ;
            }
        }

        int ans = min_cost(S , T)  ;
        printf("%d\n" , ans) ;

    }
    return 0;
}
