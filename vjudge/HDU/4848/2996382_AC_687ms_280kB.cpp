#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int INF = 0x3f3f3f3f;
int n,ans;
int deadline[33];
int g[33][33];
int vis[33];
void shortPath(){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
                if(g[k][j]>g[k][i]+g[i][j])
                    g[k][j] = g[k][i]+g[i][j];
}
void dfs(int u,int cur,int dep,int sum){
    if(dep==n){
        ans = min(ans,sum);
        return;
    }
    if(sum + cur*(n-dep)>=ans) return;
    for(int i=2;i<=n;i++){
        if(!vis[i] && cur > deadline[i])
            return;
    }
    for(int i=2;i<=n;i++){
        if(!vis[i] && u!=i && cur+g[u][i]<=deadline[i]){
            vis[i] = 1;
            dfs(i,cur+g[u][i],dep+1,sum+cur+g[u][i]);
            vis[i] = 0;
        }
    }
}
int main()
{
    while(scanf("%d",&n)!=EOF){
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                scanf("%d",&g[i][j]);
        for(int i=2;i<=n;i++)
            scanf("%d",&deadline[i]);
        shortPath();
        memset(vis,0,sizeof vis);
        ans = INF;
        dfs(1,0,1,0);
        if(ans == INF) ans = -1;
        printf("%d\n",ans);
    }
    return 0;
}
