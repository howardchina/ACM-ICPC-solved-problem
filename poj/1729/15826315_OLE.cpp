#include<iostream> 
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<climits>
using namespace std; 
#define rep(i,n) for(i=0; i<(n); i++)
#define repf(i,n,m) for(i=(n); i<=(m); i++)//正循环的
#define repd(i,n,m) for(i=(n); i>=(m); i--) //负循环的 
#define fab(a) (a)>0?(a):0-(a)
#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)
#define ll __int64
#define arc(a) (a)*(a)
#define inf 1000000   //最大值的
#define exp 0.0000001     //浮点型的
#define N  105   //记录开的数组
int pre[N];
int length=INT_MAX;
struct pp
{
    int pre,y,len,cost;
}b[N*100];//代表的是路的 
int k,n,m,len;
int cost[N];
int dis[N];
int mincost[N],mindis[N];
bool flag[N]; 
void addpage(int s,int d,int l,int t)
{
    b[len].y=d;
    b[len].len=l;
    b[len].cost=t;
    b[len].pre=pre[s];
    pre[s]=len++;
} 
void find(int s)
{
    int i,j;
    queue<int>q;
    bool vis[N];
    memset(vis,false,sizeof(vis));
    vis[s]=true;
    q.push(s);
    while(!q.empty())
    {
        int y=q.front();
        q.pop();
        vis[y]=false;
  //      printf("　　%d\n",y);
        for(i=pre[y];i!=-1; i=b[i].pre)
        {
            j=b[i].y;
      //      printf("%d\n",j);
            if(dis[j]>dis[y]+b[i].len)
            {
                dis[j]=dis[y]+b[i].len;
                if(vis[j]==false)
                {
                    q.push(j);
                    vis[j]=true;
                }
            }
        }
    }
    vis[s]=false;
}
void find1(int s)
{
    int i,j;
    queue<int>q;
    bool vis[N];
    memset(vis,false,sizeof(vis));
    vis[s]=true;
    q.push(s);
    while(!q.empty())
    {
        int y=q.front();
        q.pop();
        vis[y]=false;
        for(i=pre[y];i!=-1; i=b[i].pre)
        {
            j=b[i].y;
            if(cost[j]>cost[y]+b[i].cost)
            {
                cost[j]=cost[y]+b[i].cost;
                if(vis[j]==false)
                {
                    q.push(j);
                    vis[j]=true;
                }
            }
        }
    }
    vis[s]=true;
}
void dfs(int s,int len,int p)
{
    if(s==n)
    {
        if(p<=k)
         length=min(len,length);
        return ;
    }
    int i,y,j;
    flag[s]=true;
    for(i=pre[s];i!=-1; i=b[i].pre)
    {
        y=b[i].y;
        if(p+mincost[y]+b[i].cost>k || len+b[i].len+mindis[y]>length)
         continue;
         dfs(y,len+b[i].len,p+b[i].cost);
    }
    flag[s]=false;
}

int main()
{
    int i,j;
    int s,d,l,t;
    while(~scanf("%d",&k))
    {
        scanf("%d%d",&n,&m);
        len=1;
        memset(pre,-1,sizeof(pre)); 
        repf(i,1,m)
        {
            scanf("%d%d%d%d",&s,&d,&l,&t);
            addpage(s,d,l,t);
        } 
        repf(i,1,n)
        {
            repf(j,1,n) 
            {
                cost[j]=dis[j]=inf; 
            } 
            dis[i]=0; 
            find(i);
            mindis[i]=dis[n];
     //      printf("%d\n",mindis[i]); 
            
            cost[i]=0;
            find1(i);
            mincost[i]=cost[n];
        //    printf("%d\n",mincost[i]);
       //     system("pause");
        }
        memset(flag,false,sizeof(flag));
        length=inf;
        dfs(1,0,0);
        printf("%d\n",length);
    }
    return 0;
} 