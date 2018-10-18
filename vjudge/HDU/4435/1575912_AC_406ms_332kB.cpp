#include<cstdio>
#include<cmath>
#include<cstring>
#define maxn 130
#include<queue>
using namespace std;

struct node
{
    double x,y;
} no[maxn];
queue<int>q;
int dis[maxn][maxn],n,d,dd[maxn];
bool vis[maxn],flag[maxn];

bool bfs()
{
    while(!q.empty())q.pop();
    for(int i=1;i<=n;i++)if(flag[i])dd[i]=0;
        else dd[i]=9999999;
    q.push(1);
    vis[1]=1;
    while(!q.empty())
    {
        int u=q.front();
        vis[u]=1;
        q.pop();
        for(int i=1; i<=n; i++)
        {
            if(!vis[i]&&i!=u&&dis[u][i]<=d)
            {
                dd[i]=min(dd[i],dd[u]+dis[u][i]);
                if(flag[i])q.push(i);
            }
        }
    }
    for(int i=1;i<=n;i++)
        if(flag[i]==0&&dd[i]*2>d)return 0;
        else if(flag[i]&&!vis[i])return 0;
    return 1;
}

int main()
{
    while(scanf("%d%d",&n,&d)!=EOF)
    {
        memset(flag,1,sizeof flag);
        memset(vis,0,sizeof vis);
        for(int i=1; i<=n; i++)
            scanf("%lf%lf",&no[i].x,&no[i].y);
        for(int i=1; i<=n; i++)
            for(int j=i+1; j<=n; j++)
                dis[i][j]=dis[j][i]=ceil(sqrt((no[i].x-no[j].x)*(no[i].x-no[j].x)+(no[i].y-no[j].y)*(no[i].y-no[j].y)));
        if(!bfs()){puts("-1");continue;}
        for(int i=n; i>=2; i--)
        {
            memset(vis,0,sizeof vis);
            flag[i]=0;
            if(!bfs())flag[i]=1;
        }
        int i;
        for(i=n;i>=1;i--)if(flag[i])break;
        for(;i>=1;i--)if(flag[i])printf("1");
        else printf("0");
        printf("\n");
    }
    return 0;
}
