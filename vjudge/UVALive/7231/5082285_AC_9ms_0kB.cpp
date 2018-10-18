#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<vector>
#include<stack>
using namespace std;
const int maxn=100010;
int fa[maxn][20],ans;
int d[maxn],now;
int vis[maxn];
int co[maxn];
vector<int> edg[maxn];
bool ok(int x,int root)
{
    if(d[root]>=d[x]||co[root]!=co[x])return false;
    int c=d[x]-d[root],k=0;
    while(c)
    {
        if(c&(1<<k))
        {
            x=fa[x][k];
            c-=(1<<k);
        }
        k++;
    }
    if(x==root)return true;
    return false;
}
void dfs(int x)
{
    //cout<<x<<" "<<now<<endl;
    vis[x]=now;
    co[x]=1-co[fa[x][0]];
    int l=edg[x].size();
    if(ans)return ;
    for(int i=0;i<l;i++)
    {
        int u=edg[x][i];
        //cout<<"u:"<<u<<" "<<vis[u]<<endl;
        if(vis[u]==0)
        {
            d[u]=d[x]+1;
            fa[u][0]=x;
            for(int j=1;(1<<j)<=d[u];j++)
                fa[u][j]=fa[fa[u][j-1]][j-1];
            dfs(u);
        }
        else if(vis[u]==now)
        {
            if(ok(x,u))
            {
                ans=1;
                printf("1\n%d\n",d[x]-d[u]+1);
                stack<int>output;
                while(x!=u)
                {
                    output.push(x);
                    //printf("%d\n",x);
                    x=fa[x][0];
                }
                output.push(x);
                while(!output.empty())
                {
                    x=output.top();
                    output.pop();
                    printf("%d\n",x);
                }
                return ;
            }
        }
    }
}
int main()
{
    //freopen("data.in","w",stdout);
    int T,n,m;
    co[0]=1;
    scanf("%d",&T);
    while(T--)
    {
        ans=0;
        memset(fa,0,sizeof fa);
        memset(co,0,sizeof co);
        memset(vis,0,sizeof vis);
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)edg[i].clear();
        for(int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            edg[x].push_back(y);
        }
        for(now=1;now<=n&&ans==0;now++)
            if(vis[now]==0)
            {
                d[now]=0;
                fa[now][0]=0;
                dfs(now);
            }
        if(ans==0)printf("-1\n");
    }
    return 0;
}
