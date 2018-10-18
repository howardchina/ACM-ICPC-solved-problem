#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN=444, MAXE=22222, INF=0x3f3f3f3f;
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
    int N, F, D;
    while(scanf("%d%d%d", &N, &F, &D) != EOF){
        int source = F+N+N+D+1, sink = F+N+N+D+2;
        Init(source, sink);
        for(int i = 1; i <= F; i++)
            Add(source, N+N+i, 1);
        for(int i = 1; i <= N; i++)
            Add(i, i + N, 1);
        for(int i = 1; i <= D; i++)
            Add(N+N+F+i, sink, 1);
        for(int i = 1; i <= N; i++){
            int Fi, Di, f, d;
            scanf("%d%d", &Fi, &Di);
            for(int j = 0; j < Fi; j++){
                scanf("%d", &f);
                Add(N+N+f, i, 1);
            }
            for(int j = 0; j < Di; j++){
                scanf("%d", &d);
                Add(i+N, N+N+F+d, 1);
            }
        }
        printf("%d\n", Dinic());
    }
    return 0;
}
