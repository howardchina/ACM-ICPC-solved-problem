#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN=66, MAXE=2222, INF=1000000007;
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
//    freopen("data.in","r",stdin);
    int T,N,M,p,q,u,v,c,sum,rms;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d%d",&N,&M,&p,&q);
        Init(p,q);
        sum=0;
        for(int i=0;i<M;i++){
            scanf("%d%d%d",&u,&v,&c);
            sum+=c;
            Add(u,v,c*1111+1);
            Add(v,u,c*1111+1);
        }
        rms=Dinic();
        if(rms==0)puts("Inf");
        else printf("%.2lf\n",(double)(sum-rms/1111)/(rms%1111));
    }
    return 0;
}
