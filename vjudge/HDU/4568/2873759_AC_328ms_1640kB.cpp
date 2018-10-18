#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int d[14][14];
int g[222][222];
int N,M,K;
struct Node{
    int x,y,d;
    Node(int x=0,int y=0,int d=0):x(x),y(y),d(d){}
    bool operator <(const Node &rhs)const{
        return d>rhs.d;
    }
}pnt[14];

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int vis[222][222];
void bfs(int id){
    memset(vis,-1,sizeof vis);
    Node o = Node(pnt[id].x,pnt[id].y,0),nx;
    priority_queue<Node>q;
    q.push(o);
    int tot=N*M,cnt=0;
    while(!q.empty() && cnt<tot){
        o = q.top();
        q.pop();
        if(-1 != vis[o.x][o.y]) continue;
        vis[o.x][o.y] = o.d;
        cnt++;
        for(int i=0;i<4;i++){
            nx=o;
            nx.x+=dx[i];
            nx.y+=dy[i];
            if(nx.x<0 || nx.x>=N || nx.y<0 || nx.y>=M || g[nx.x][nx.y]==-1) continue;
            nx.d+=g[nx.x][nx.y];
            q.push(nx);
        }
    }
    for(int i=1;i<=K;i++){
        if(d[id][i] < vis[pnt[i].x][pnt[i].y])
            d[id][i] = vis[pnt[i].x][pnt[i].y];
    }
    int *p = &d[id][0];
    for(int i=0;i<N;i++){
        if(vis[i][0]!=-1)
            if(*p==-1 || *p > vis[i][0]) *p=vis[i][0];
        if(vis[i][M-1]!=-1)
            if(*p==-1 || *p > vis[i][M-1]) *p=vis[i][M-1];
    }
    for(int i=0;i<M;i++){
        if(vis[0][i]!=-1)
            if(*p==-1 || *p > vis[0][i]) *p=vis[0][i];
        if(vis[N-1][i]!=-1)
            if(*p==-1 || *p > vis[N-1][i]) *p=vis[N-1][i];
    }
}
int dp[14][1<<14];
void go()
{
    memset(dp,0,sizeof dp);
    for(int i=1;i<=K;i++)
        if(d[i][0]!=-1&&g[pnt[i].x][pnt[i].y]!=-1)
        dp[i][1<<(i-1)]=d[i][0]+g[pnt[i].x][pnt[i].y];
    for(int s=1;s<(1<<K);s++)
        for(int i=1;i<=K;i++)
            if(dp[i][s])
            for(int j=1;j<=K;j++)
                if(((1<<(j-1))&s)==0&&d[i][j]!=-1)
                    if(dp[j][s+(1<<(j-1))]==0||dp[j][s+(1<<(j-1))]>dp[i][s]+d[i][j])
                        dp[j][s+(1<<(j-1))]=dp[i][s]+d[i][j];
    int ans1=0,ans=0;
    for(int s=1;s<(1<<K);s++)
        for(int i=1;i<=K;i++)
        if(dp[i][s])
        {
            int tot=0;
            for(int j=1;j<=K;j++)
                if(((1<<(j-1))&s))tot++;
            if(tot==ans1)ans=min(ans,dp[i][s]+d[i][0]);
            if(tot>ans1)ans1=tot,ans=dp[i][s]+d[i][0];
        }
    printf("%d\n",ans);
}
int main()
{
    //freopen("data.in","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&N,&M);
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++)
                scanf("%d",&g[i][j]);
        scanf("%d",&K);
        for(int i=1;i<=K;i++)
            scanf("%d%d",&pnt[i].x,&pnt[i].y);
        memset(d,-1,sizeof d);
        for(int i=1;i<=K;i++)
        {
            bfs(i);
            // printf("11  %d %d\n",i,d[i][0]+g[pnt[i].x][pnt[i].y]);
        }

        //puts("o")
        go();
    }

    return 0;
}