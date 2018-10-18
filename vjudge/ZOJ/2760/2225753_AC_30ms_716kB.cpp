#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int MAXN=111, MAXE=11111, INF=1000000007;
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

int dis[MAXN][MAXN], dmin[MAXN][MAXN];

int main()
{
//    freopen("data.in", "r", stdin);
    int n;
    while(scanf("%d", &n) != EOF){
        int source, sink, S, T;
        source = n, sink = n+1;
        for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            scanf("%d", &dis[i][j]);
            if(i == j) dis[i][j] = 0;
            dmin[i][j] = dis[i][j] = (dis[i][j] < 0)?INF:dis[i][j];
        }
        scanf("%d%d", &S, &T);
        if(S == T){
            puts("inf");
            continue;
        }
        for(int k = 0; k < n; k++)
            for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
            dmin[i][j] = min(dmin[i][j], dmin[i][k] + dmin[k][j]);
        if(dmin[S][T] == INF){
            puts("0");
            continue;
        }
        Init(source, sink);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                if(dis[i][j] < INF && dmin[S][i] + dis[i][j] + dmin[j][T] == dmin[S][T])
                    Add(i, j, 1);
            }
        Add(source, S, INF), Add(T, sink, INF);
        int ans = Dinic();
        printf("%d\n", ans);
    }
    return 0;
}

/*
Sample Input
4
0 1 1 -1
-1 0 1 1
-1 -1 0 1
-1 -1 -1 0
0 3
5
0 1 1 -1 -1
-1 0 1 1 -1
-1 -1 0 1 -1
-1 -1 -1 0 1
-1 -1 -1 -1 0
0 4
Sample Output
2
1
*/
