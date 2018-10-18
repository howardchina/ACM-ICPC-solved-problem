#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int MAXN=22222, MAXE=44444, INF=1000000007;
struct Edge{
    int from, to, next, cap;
    Edge(){}
    Edge(int f, int t, int n, int c):from(f), to(t), next(n), cap(c){}
}edge[MAXE*2];

int src, snk, tot, head[MAXN], dep[MAXN], q[MAXN];

void Init(int s, int t){
    src = s, snk = t;
    tot = 0;
    memset(head, -1, sizeof head);
}
void Add(int u, int v, int c){
//    printf("%d %d %d\n", u, v, c);
    edge[tot] = Edge(u, v, head[u], c);
    head[u] = tot++;
    edge[tot] = Edge(v, u, head[v], 0);
    head[v] = tot++;
}
bool BFS(){
    memset(dep,-1,sizeof dep);
    int rear = 0;
    dep[src] = 0;
    q[rear++] = src;
    for(int i = 0; i < rear; i++){
        int u = q[i];
        for(int p = head[u]; ~p; p=edge[p].next){
            int v = edge[p].to;
            if(dep[v] == -1 && edge[p].cap>0){
                dep[v] = dep[u] + 1;
                q[rear++] = v;
            }
        }
    }
    return dep[snk] != -1;
}
int DFS(int u, int fl){
    int ret;
    if(u == snk) return fl;
    for(int i = head[u]; ~i; i = edge[i].next){
        int v = edge[i].to;
        if(edge[i].cap > 0 && dep[u] != -1 && dep[v] != -1 && dep[v] == dep[u] + 1 && (ret=DFS(v,min(fl,edge[i].cap)))){
            edge[i].cap-=ret;
            edge[i^1].cap+=ret;
            return ret;
        }
    }
    dep[u] = -1;
    return 0;
}
int Dinic(){
    int ret = 0, delta;
    while(BFS()){
        while(1){
            delta = DFS(src,INF);
            if(delta == 0) break;
            ret += delta;
        }
    }
    return ret;
}

int main()
{
//    freopen("data.in", "r", stdin);
    int n,m;
    while(scanf("%d%d", &n,&m) != EOF){
        int source, sink, S, T, x, y;
        source = 2*n, sink = 2*n+1, S=sink+1, T=sink+2;
        Init(source,sink);
        for(int i=0;i<m;i++){
            scanf("%d%d",&x,&y);
            Add(y,n+x,1);
        }
        for(int i=0;i<n;i++){
            Add(S,i,1);
            Add(n+i,T,1);
        }
        Add(source, S, INF), Add(T, sink, INF);
        int ans = Dinic();
        printf("%s\n", ans==n?"YES":"NO");
    }
    return 0;
}
