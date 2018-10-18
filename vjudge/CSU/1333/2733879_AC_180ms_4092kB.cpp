#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
typedef long long LL;
const int maxn=333,maxm=111111;
const LL INF=0x3f3f3f3f3f3fLL;
struct Edge{
    int from,to,at,bt,dist,next;
    Edge(int f=0,int t=0,int a=0,int b=0,int d=0,int n=0):
    from(f),to(t),at(a),bt(b),dist(d),next(n){}
}edge[maxm];
int tot,head[maxn],n;
void init(){
    for(int i=1;i<=n;i++)
        head[i]=-1;
    tot=0;
}
void add(int f,int t,int a,int b,int d){
    edge[tot]=Edge(f,t,a,b,d,head[f]);
    head[f]=tot++;
}
struct HeapNode{
    LL d;
    int u;
    bool operator<(const HeapNode &rhs)const{
        return d>rhs.d;
    }
};
struct Dijsktra{
    bool done[maxn];
    LL d[maxn];
    void dijsktra(int s){
        priority_queue<HeapNode>Q;
        for(int i=1;i<=n;i++) d[i]=INF;
        d[s]=0;
        memset(done,0,sizeof(done));
        Q.push((HeapNode){0,s});
        while(!Q.empty()){
            HeapNode x=Q.top();Q.pop();
            int u=x.u;
            if(done[u]) continue;
            done[u]=1;
            for(int i=head[u];i!=-1;i=edge[i].next){
                Edge &e=edge[i];
                LL dist=d[u];
                if(dist%(e.at+e.bt)+e.dist>e.at) dist+=(e.at+e.bt)-dist%(e.at+e.bt);
                if(d[e.to]>dist+e.dist){
                    d[e.to]=dist+e.dist;
                    Q.push((HeapNode){d[e.to],e.to});
                }
            }
        }
    }
}dijsktra;
int main()
{
//    freopen("data.in","r",stdin);
    int m,s,t,cas=1,u,v,a,b,tt;
    LL ans;
    while(scanf("%d%d%d%d",&n,&m,&s,&t)!=EOF){
        init();
        for(int i=0;i<m;i++){
            scanf("%d%d%d%d%d",&u,&v,&a,&b,&tt);
            if(a<tt)continue;
            add(u,v,a,b,tt);
        }
        dijsktra.dijsktra(s);
        ans=dijsktra.d[t];
        printf("Case %d: %lld\n",cas++,ans);
    }
    return 0;
}
