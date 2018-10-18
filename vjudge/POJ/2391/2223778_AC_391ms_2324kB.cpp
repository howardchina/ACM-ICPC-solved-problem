#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
#define REP(i,n) for(int i=0, _e(n); i<_e; i++)
#define FOR(i,a,b) for(int i(a), _e(b); i<=_e; i++)
typedef long long LL;
typedef pair<int,int> ii;
const int MAX = 222, MAXN = 444, MAXE = 55555;
const int INF = 1000000007;
struct Edge{
    int from, to, next;
    int cap;
    Edge(){}
    Edge(int _from, int _to, int _next, int _cap)
    :from(_from),to(_to),next(_next),cap(_cap){}
}edges[MAXE*2];

int cnt,head[MAXN],dep[MAXN];
int src,snk;
struct Queue{
    int he,re,q[MAXN];
    void Init(){he=re=0;}
    bool Empty(){return he==re;}
    void Push(int x){ q[re++]=x; if(re>=MAXN)re=0; }
    int Pop(){ int x=q[he++]; if(he>=MAXN)he=0; return x; }
}q;
void init(int _src,int _snk){
    cnt=0;
    memset(head,-1, sizeof head);
    src=_src, snk=_snk;
}

void add(int u,int v,int c){
    edges[cnt]=Edge(u,v,head[u],c);
    head[u]=cnt++;
    edges[cnt]=Edge(v,u,head[v],0);
    head[v]=cnt++;
}

bool BFS(){
    q.Init();
    memset(dep,-1,sizeof dep);
    dep[src]=0;
    q.Push(src);
    while(!q.Empty()){
        int u=q.Pop();
        for(int i=head[u]; i!=-1; i=edges[i].next){
            int v=edges[i].to;
            if(edges[i].cap>0 && dep[v]==-1){
                dep[v]=dep[u]+1;
                q.Push(v);
            }
        }
    }
    return dep[snk]!=-1;;
}
int DFS(int u,int fl){
    if(u==snk)return fl;
    int ret;
    for(int i=head[u]; i!=-1; i=edges[i].next){
        int v=edges[i].to;
        if(edges[i].cap>0 && dep[v]==dep[u]+1 && (ret=DFS(v,min(fl,edges[i].cap)))){
            edges[i].cap-=ret;
            edges[i^1].cap+=ret;
            return ret;
        }
    }
    dep[u]=-1;
    return 0;
}
int Dinic(){
    int ret=0,delta;
    while(BFS()){
        while(1){
            delta = DFS(src,INF);
            if(delta==0)break;
            ret+=delta;
        }
    }
    return ret;
}

int F,P;
int SUM;
LL cost[MAX][MAX];
ii flds[MAX];

bool solve(LL maxCost){
    int source = 2*F+1, sink = 2*F+2;
    init(source, sink);
    FOR(i,1,F){
        add(source, i, flds[i].first);
        add(i,i+F,INF);
        add(i+F,sink,flds[i].second);
        FOR(j,1,F){
            if(i==j || cost[i][j] == -1 || cost[i][j] > maxCost) continue;
            add(i, j+F, INF);
        }
    }
    int maxFlow = Dinic();
    return maxFlow == SUM;
}

int main(){
//    freopen("data.in","r",stdin);
    while(scanf("%d%d", &F, &P) != EOF){
        FOR(i,1,F){
            int a, b;
            scanf("%d%d", &a,&b);
            flds[i]=ii(a,b);
        }
        LL _lim=-1;
        memset(cost, -1, sizeof cost);
        REP(i,MAX) cost[i][i]=0;
        REP(i,P){
            int a, b, c;
            scanf("%d%d%d", &a,&b,&c);
            if(cost[a][b]==-1||cost[a][b]>c){
                cost[a][b]=cost[b][a]=c;
                _lim = max(_lim, LL(c));
            }
        }
        FOR(k,1,F)
        FOR(i,1,F)
        FOR(j,1,F){
            if(cost[i][k] == -1 || cost[k][j] == -1) continue;
            if(cost[i][j] == -1 || cost[i][k] + cost[k][j] < cost[i][j]){
                cost[i][j] = cost[i][k] + cost[k][j];
                _lim = max(_lim, cost[i][j]);
            }
        }
        SUM = 0;
        FOR(i,1,F) SUM += flds[i].first;
        LL L=0, R = _lim+1, mid;
        LL ans=-1;
        while(L<R){
            mid=L+(R-L)/2;
            if(solve(mid))R=mid;
            else L=mid+1;
        }
        if(L>_lim)L=-1;
        printf("%lld\n",L);
    }
    return 0;
}
