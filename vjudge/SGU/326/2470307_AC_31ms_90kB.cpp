#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN=500, MAXE=800, INF=1000000007;
struct Edge{
    int from,to,next,cap;
    Edge(){}
    Edge(int f,int t,int n,int c):from(f),to(t),next(n),cap(c){}
}edge[MAXE*2];
int src,snk,tot,head[MAXN],dep[MAXN],q[MAXN];
void Init(int s,int t){
    src=s,snk=t;
    tot=0;
    memset(head,-1,sizeof head);
}
void Add(int u,int v,int c){
    edge[tot]=Edge(u,v,head[u],c);
    head[u]=tot++;
    edge[tot]=Edge(v,u,head[v],0);
    head[v]=tot++;
}
bool BFS(){
    memset(dep,-1,sizeof dep);
    int rear=0;
    dep[src]=0;
    q[rear++]=src;
    for(int i=0;i<rear;i++){
        int u=q[i];
        for(int p=head[u];~p;p=edge[p].next){
            int v=edge[p].to;
            if(dep[v]==-1&&edge[p].cap>0){
                dep[v]=dep[u]+1;
                q[rear++]=v;
            }
        }
    }
    return dep[snk]!=-1;
}
int DFS(int u,int fl){
    int ret;
    if(u==snk)return fl;
    if(dep[u]!=-1){
        for(int i=head[u];~i;i=edge[i].next){
            int v=edge[i].to;
            if(edge[i].cap>0&&dep[v]!=-1&&dep[v]==dep[u]+1&&(ret=DFS(v,min(fl,edge[i].cap)))){
                edge[i].cap-=ret;
                edge[i^1].cap+=ret;
                return ret;
            }
        }
        dep[u]=-1;
    }
    return 0;
}
int Dinic(){
    int ret=0,delta;
    while(BFS()){
        while(1){
            delta=DFS(src,INF);
            if(delta==0) break;
            ret+=delta;
        }
    }
    return ret;
}
int w[22], r[22], a[22][22];
int main()
{
//    freopen("data.in","r",stdin);
    int n,ok=1;
    scanf("%d", &n);
    for(int i=1;i<=n;i++)
        scanf("%d",&w[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&r[i]);
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    scanf("%d",&a[i][j]);
    int win=w[1]+r[1];
    for(int i=2;i<=n;i++)
        if(w[i]>win) {ok=0;break;}
    if(ok){
        int source=n*n+1, sink=n*n+2;
        Init(source,sink);
        int sum=0;
        for(int i=2;i<=n;i++)
        for(int j=i+1;j<=n;j++){
            if(a[i][j]){
                sum+=a[i][j];
                Add(source,i*n+j,a[i][j]);
                Add(i*n+j,i,INF);
                Add(i*n+j,j,INF);
            }
        }
        for(int i=2;i<=n;i++){
            Add(i,sink,win-w[i]);
        }
        int mf=Dinic();
        ok=(mf==sum);
    }
    if(ok)puts("YES");
    else puts("NO");
    return 0;
}
