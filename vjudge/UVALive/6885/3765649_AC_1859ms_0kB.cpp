#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int MAXM = 1000050 ;
const int MAXN = 10050;
const int INF = 0x3f3f3f3f ;

int N ,M  ;
int ds[MAXN] , dt[MAXN] , inq[MAXN] ;

struct Edge{
    int from, to, dist , next ;
    Edge(int from=0 ,int to=0, int dist=0 ,int next = 0) :from(from), to(to) , dist(dist) , next(next) {} ;
}edges[MAXM];
int head[MAXN] , sz ;
void init() {
    memset(head , -1, sizeof(head)) ;
    sz = 0 ;
}
void add_edge(int u ,int v , int d) {
    edges[sz] = Edge(u, v , d, head[u]) , head[u] = sz ++ ;
}

void spfa(int s, int t, int *d) {
    memset(inq, 0 , sizeof(inq));
    for(int i=0 ; i<=N; i++) d[i] = INF;
    queue<int>Q;
    inq[s]=1 , d[s] = 0 , Q.push(s) ;
    while(!Q.empty()){
        int u = Q.front(); Q.pop() ; inq[u] = 0 ;
        for(int i=head[u]; ~i ; i=edges[i].next){
            int v = edges[i].to;
            if(d[v] > d[u] + edges[i].dist) {
                d[v] = d[u] + edges[i].dist ;
                if(!inq[v]) {
                    inq[v] = 1 ;
                    Q.push(v) ;
                }
            }
        }
    }
}


int main()
{

   // freopen("in.txt", "r" ,stdin) ;

    while(scanf("%d%d", &N, &M) == 2) {
        init();
        for(int i=0; i<M; i++){
            int u , v , w;
            scanf("%d%d%d", &u, &v, &w);
            add_edge(u, v ,w) ;
            add_edge(v , u, w) ;
        }
        spfa(0 , N-1, ds);
        spfa(N-1 , 0 , dt) ;

        int len  = ds[N-1];
        int ans =  0;
        for(int i=0; i<sz; i++) {
            if(ds[edges[i].from] + dt[edges[i].to] + edges[i].dist == len) ans += edges[i].dist ;
        }

        ans *= 2;

        printf("%d\n" , ans) ;

    }
    return 0;
}
