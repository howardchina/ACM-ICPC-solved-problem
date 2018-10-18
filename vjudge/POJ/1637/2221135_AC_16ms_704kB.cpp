#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 222;
const int maxm = 1111;
struct Edge{
    int from, to, cap, flow;
    Edge(){}
    Edge(int _from, int _to, int _cap, int _flow)
    :from(_from), to(_to), cap(_cap), flow(_flow){}
};
struct Queue{
    int a[maxn], p, q;
    void Init(){p = q = 0;}
    void Push(int x){
        a[q++]=x;
        if(q==maxn)q=0;
    }
    int Pop(){
        int t=a[p++];
        if(p==maxn)p=0;
        return t;
    }
    bool Empty(){return p==q;}
}q;
struct Dinic{
    int n, m, s, t ,totin;
    Edge edges[maxm*2];
    int head[maxn];
    int next[maxm*2];
    bool inq[maxn];
    int d[maxn];
    int cur[maxn];
    void Init(int n){
        this->n = n;
        m = 0;
        totin = 0;
        memset(head, -1, sizeof(head[0])*(n+1));
    }
    void AddEdge(int from, int to, int cap){
        next[m]=head[from];
        edges[m]=Edge(from,to,cap,0);
        head[from]=m++;

        next[m]=head[to];
        edges[m]=Edge(to,from,0,0);
        head[to]=m++;

        if(from == s) totin+=cap;
    }
    bool BFS(){
        memset(inq,0,sizeof(inq[0])*(n+1));
        q.Init();
        q.Push(s);
        d[s]=0;inq[s]=true;
        while(!q.Empty()){
            int u=q.Pop();
            for(int i=head[u];i!=-1;i=next[i]){
                Edge &e=edges[i];
                int v=e.to;
                if(!inq[v]&&e.cap>e.flow){
                    inq[v]=true;
                    d[v]=d[u]+1;
                    q.Push(v);
                    if(v==t)return true;
                }
            }
        }
        return false;
    }
    int DFS(int u,int a){
        if(u==t||a==0)return a;
        int flow=0,f;
        for(int &i=cur[u];i!=-1;i=next[i]){
            Edge &e=edges[i];
            int v=e.to;
            if(d[u]+1==d[v]&&(f=DFS(v,min(a,e.cap-e.flow)))>0){
                e.flow+=f;
                edges[i^1].flow-=f;
                flow+=f;
                a-=f;
                if(a==0)break;
            }
        }
        return flow;
    }
    int Maxflow(int s,int t){
        this->s=s; this->t=t;
        int flow=0;
        while(BFS()){
            memcpy(cur,head,sizeof(head[0])*(n+1));
            flow+=DFS(s,inf);
        }
        return flow;
    }
}dinic;
int in[maxn], ou[maxn];
int main(){
//    freopen("data.in","r",stdin);
    int tcas, n, s;
    scanf("%d", &tcas);
    while(tcas--){
        scanf("%d%d", &n, &s);
        dinic.Init(n+1);
        memset(in, 0, sizeof in);
        memset(ou, 0, sizeof ou);
        int xi, yi, di;
        for(int i = 0; i < s; i++){
            scanf("%d%d%d", &xi, &yi, &di);
            ou[xi]++;
            in[yi]++;
            if(di == 0 && xi!=yi){
                dinic.AddEdge(xi,yi,1);
            }
        }
        int ii;
        for(ii = 1; ii <= n; ii++){
            if((in[ii] + ou[ii])&1)
                break;
        }
        if(ii <= n){
            puts("impossible");
            continue;
        }
        for(int i = 1; i <= dinic.n; i++){
            if(in[i]>ou[i]){
                dinic.AddEdge(i, n+1,(in[i]-ou[i])>>1);
            }else if(in[i]<ou[i]){
                dinic.AddEdge(0, i, (ou[i]-in[i])>>1);
            }
        }
        if(dinic.totin == dinic.Maxflow(0,n+1))
            puts("possible");
        else puts("impossible");
    }
    return 0;
}
