#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define typec int
const int inf = 0x3f3f3f3f;
const int maxn = 111;
const int maxm = 11111;
int G[maxn][maxn];
struct Edge{
    int from, to, cap, flow;
    Edge(){}
    Edge(int _from, int _to, int _cap, int _flow)
    :from(_from), to(_to), cap(_cap), flow(_flow){}
};
struct Queue{
    int a[maxn], p, q;
    void init(){p = q = 0;}
    void Push(int x){
        a[q++] = x;
        if(q == maxn) q = 0;
    }
    int Pop(){
        int t = a[p++];
        if(p == maxn) p = 0;
        return t;
    }
    bool Empty(){return p == q;}
}q;
struct Dinic{
    int n, m, s, t;
    Edge edges[maxm*2];
    int head[maxn];
    int next[maxm*2];
    bool inq[maxn];
    int d[maxn];
    int cur[maxn];
    void init(int n){
        this->n = n;
        m = 0;
        memset(head, -1, sizeof(head[0])*(n+1));
        for(int i = 0; i <= n; i++) memset(G[i], -1, sizeof G[i]);
    }
    void AddEdge(int from, int to, int cap){
        if(G[from][to] == -1){
            G[from][to] = m;
            next[m] = head[from];
            edges[m] = Edge(from, to, cap, 0);
            head[from] = m++;

            G[to][from] = m;
            next[m] = head[to];
            edges[m] = Edge(to, from, 0, 0);
            head[to] = m++;
        }else{
            int &id = G[from][to];
            edges[id].cap += cap;
            if(edges[id].cap > inf) edges[id].cap = inf;
        }
    }
    bool BFS(){
        memset(inq, 0, sizeof(inq[0])*(n+1));
        q.init();
        q.Push(s);
        d[s] = 0;inq[s] = true;
        while(!q.Empty()){
            int u = q.Pop();
            for(int i = head[u]; i != -1; i = next[i]){
                Edge &e = edges[i];
                int v = e.to;
                if(!inq[v] && e.cap > e.flow){
                    inq[v] = true;
                    d[v] = d[u] + 1;
                    q.Push(v);
                    if(v == t) return true;
                }
            }
        }
        return false;
    }
    int DFS(int u, int a){
        if(u == t || a == 0) return a;
        int flow = 0, f;
        for(int &i = cur[u]; i != -1; i = next[i]){
            Edge &e = edges[i];
            int v = e.to;
            if(d[u] + 1 == d[v] && (f = DFS(v , min(a,e.cap - e.flow))) > 0){
                e.flow += f;
                edges[i^1].flow -= f;
                flow += f;
                a -= f;
                if(a == 0) break;
            }
        }
        return flow;
    }
    int Maxflow(int s, int t){
        this->s = s; this->t = t;
        int flow = 0;
        while(BFS()){
            memcpy(cur, head, sizeof(head[0])*(n+1));
            flow += DFS(s, inf);
        }
        return flow;
    }
}dinic;
int pig[1111], key[maxn][1111], cap[maxn];
int seq[1111][111];
int main()
{
//    freopen("data.in", "r", stdin);
    int M, N;
    while(scanf("%d%d", &M, &N) != EOF){
        for(int i = 1; i <= M; i++)scanf("%d", &pig[i]);
        for(int i = 1; i <= M; i++) memset(seq[i], 0, sizeof seq[i]);
        dinic.init(N+1);
        for(int i = 1; i <= N; i++){
            int A;
            scanf("%d", &A);
            key[i][0] = A;//第i轮 顾客打开的门的个数A
            for(int j = 1;j <= A; j++){
                int K;
                scanf("%d", &K);//第i轮 顾客打开的门编号Kj
                key[i][j] = K;
                seq[K][0]++;//门Kj 顾客访问次数
                seq[K][seq[K][0]] = i;//顾客i 是门Kj的 第seq[K][0]个访问者
                if(seq[K][0] == 1){//每个猪圈的第一个顾客 从源点向他连一条边 如果有多条边就容量相加
                    dinic.AddEdge(0, i, pig[K]);
                }else{//从该猪圈的第i个顾客向第i+1个顾客连一条容量为无穷的边
                    int former = seq[K][seq[K][0]-1];
                    dinic.AddEdge(former, i, inf);
                }
            }
            scanf("%d", &cap[i]);
            dinic.AddEdge(i, N+1, cap[i]);//每个顾客到汇点各有一条边，容量是各个顾客能买的上限
        }
        int ans = dinic.Maxflow(0, N+1);
        printf("%d\n", ans);
    }
    return 0;
}
