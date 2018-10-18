#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int MAXN=500, MAXE=800, INF=1000000007;
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

int w[20], r[20], a[20][20];

int main()
{
//    freopen("data.in" ,"r", stdin);
    int n;
    while(scanf("%d", &n) != EOF){
        for(int i = 0; i < n; i++)
            scanf("%d", &w[i]);
        for(int i = 0; i < n; i++)
            scanf("%d", &r[i]);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                scanf("%d", &a[i][j]);
        w[0] += r[0];
        bool ok = 1;
        for(int i = 1; i < n; i++){
            if(w[i] > w[0]){
                ok = 0;
                break;
            }
        }
        if(!ok){
            puts("NO");
            break;
        }
        int source = n*n + n + 1;
        int sink = source + 1;
        int sum = 0;
        Init(source, sink);
        for(int i = 1; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(a[i][j]){
                    sum += a[i][j];
                    Add(source, i*n+j, a[i][j]);
                    Add(i*n+j, n*n+i, INF);
                    Add(i*n+j, n*n+j, INF);
                }
            }
            Add(n*n+i, sink, w[0] - w[i]);
        }
        if(Dinic() == sum)puts("YES");
        else puts("NO");
    }
    return 0;
}
