#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
const int MAXN=111111,MAXM=333333;
struct Edge{
    int from,to,next;
    Edge(){}
    Edge(int f,int t,int n):from(f),to(t),next(n){}
};
struct SCC{
    Edge edge[MAXM];
    int head[MAXN],tot,n,pre[MAXN],lowlink[MAXN],sccno[MAXN],dfs_clock,scc_cnt;
    stack<int>S;
    void init(){
        memset(head,-1,sizeof head);
        tot=0;
    }
    void add(int f,int t){
        edge[tot]=Edge(f,t,head[f]);
        head[f]=tot++;
    }
    void dfs(int u){
        pre[u]=lowlink[u]=++dfs_clock;
        S.push(u);
        for(int p=head[u];~p;p=edge[p].next){
            int v=edge[p].to;
            if(!pre[v]){
                dfs(v);
                lowlink[u]=min(lowlink[u],lowlink[v]);
            }else if(!sccno[v]){
                lowlink[u]=min(lowlink[u],pre[v]);
            }
        }
        if(lowlink[u]==pre[u]){
            scc_cnt++;
            for(;;){
                int x=S.top();S.pop();
                sccno[x]=scc_cnt;
                if(x==u)break;
            }
        }
    }
    void find_scc(int _n){
        n=_n;
        dfs_clock=scc_cnt=0;
        memset(sccno,0,sizeof sccno);
        memset(pre,0,sizeof pre);
        while(!S.empty()) S.pop();
        for(int i=1;i<=n;i++)
            if(!pre[i])dfs(i);
    }
}ga;
struct Graph{
    Edge edge[MAXM];
    int head[MAXN],tot,dp[MAXN],w[MAXN];
    bool vis[MAXN];
    void init(){
        memset(head,-1,sizeof head);
        memset(dp,0,sizeof dp);
        memset(vis,0,sizeof vis);
        memset(w,0,sizeof w);
        tot=0;
    }
    void add(int f,int t){
        edge[tot]=Edge(f,t,head[f]);
        head[f]=tot++;
    }
    int dfs(int u){
        if(vis[u]) return dp[u];
        vis[u]=1;
        int ret=0;
        for(int p=head[u];~p;p=edge[p].next){
            int v=edge[p].to;
            ret=max(ret,dfs(v));
        }
        return dp[u]=ret+w[u];
    }
}gb;

int main()
{
//    freopen("data.in","r",stdin);
    int N,M,u,v;
    while(scanf("%d%d",&N,&M)==2){
        ga.init();
        for(int i=0;i<M;i++){
            scanf("%d%d",&u,&v);
            ga.add(u,v);
        }
        ga.find_scc(N);

        gb.init();
        for(int u=1;u<=N;u++){
            for(int p=ga.head[u];~p;p=ga.edge[p].next){
                int x=ga.sccno[u];
                int y=ga.sccno[ga.edge[p].to];
                if(x!=y)
                    gb.add(x,y);
            }
        }
        for(int u=1;u<=N;u++){
            int x=ga.sccno[u];
            gb.w[x]++;
        }

        int ans=0;
        for(int u=1;u<=ga.scc_cnt;u++)
            ans=max(ans,gb.dfs(u));
        printf("%d\n",ans);
    }
    return 0;
}
