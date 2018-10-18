#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 222222;
struct Edge{
    int u,v,nxt;
    Edge(int u=0,int v=0,int nxt=0):u(u),v(v),nxt(nxt){}
}edge[maxn<<1];
struct Ans{
    int u,ans;
};
int head[maxn],tot;
void init(int n){
    tot=0;
    for(int i=0;i<=n;i++)
        head[i]=-1;
}
void add(int u,int v){
    edge[tot]=Edge(u,v,head[u]);
    head[u]=tot++;
    edge[tot]=Edge(v,u,head[v]);
    head[v]=tot++;
}
int q[maxn],vis[maxn],pre[maxn],path[maxn];
void clrvis(int n,int u=0){
    for(int i=0;i<=n;i++)
        vis[i] = 0;
    vis[u]=1;
}
int bfs(int u){
    int tail=0,v,farestv=u;
    q[tail++]=u;
    pre[u]=-1;
    vis[u]=1;
    for(int i=0;i<tail;i++){
        u=q[i];
        for(int e=head[u];~e;e=edge[e].nxt){
            v=edge[e].v;
            if(vis[v]) continue;
            vis[v]=vis[u]+1;
            pre[v]=u;
            if(vis[farestv]<vis[v]) farestv=v;
            q[tail++]=v;
        }
    }
    return farestv;
}
int getPath(int t){
    int n=0;
    path[++n]=t;
    while(~pre[t]){
        path[++n]=pre[t];
        t=pre[t];
    }
    return n;
}
//int cutAndGetAns(int n,int cutu){
//
//}
void getans(int n){
    int s,t,pathn,ansdis,ansu,ansv;
//    Ans centerAns = cutAndGetAns(n,n+1);
    clrvis(n,n+1);
    s=bfs(1);
    clrvis(n,n+1);
    t=bfs(s);
    pathn = getPath(t);

    if(pathn&1){/**odd number points in d*/
        int center = path[pathn/2+1],u=path[pathn/2],v=path[pathn/2+2];
        clrvis(n,v);
        s=bfs(u);
        clrvis(n,v);
        t=bfs(s);

        int un = getPath(t);
        ansu = path[un/2+1];
        ansdis = un/2;

        clrvis(n,center);
        s=bfs(v);
        clrvis(n,center);
        t=bfs(s);

        int vn = getPath(t);
        ansv = path[vn/2+1];
        ansdis = max(ansdis,vn/2);

        clrvis(n,u);
        s=bfs(v);
        clrvis(n,u);
        t=bfs(s);

        un = getPath(t);
        int ansu2 = path[un/2+1];
        int ansdis2 = un/2;

        clrvis(n,center);
        s=bfs(u);
        clrvis(n,center);
        t=bfs(s);

        vn = getPath(t);
        int ansv2 = path[vn/2+1];
        ansdis2 = max(ansdis2,vn/2);

        if(ansdis>ansdis2){
            ansu = ansu2;
            ansv = ansv2;
        }
    }else{/**even number points in d*/
        int u=path[pathn/2],v=path[pathn/2+1];
        clrvis(n,v);
        s=bfs(u);
        clrvis(n,v);
        t=bfs(s);

        int un = getPath(t);
        ansu = path[un/2+1];
        ansdis = un/2;

        clrvis(n,u);
        s=bfs(v);
        clrvis(n,u);
        t=bfs(s);

        int vn = getPath(t);
        ansv = path[vn/2+1];
        ansdis = max(ansdis,vn/2);
    }

    printf("%d %d %d\n",ansdis,ansu,ansv);
}
int main(){
//    freopen("data.in","r",stdin);
    int T,n,u,v;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        init(n);
        for(int i=1;i<n;i++){
            scanf("%d%d",&u,&v);
            add(u,v);
        }
        getans(n);
    }
    return 0;
}
