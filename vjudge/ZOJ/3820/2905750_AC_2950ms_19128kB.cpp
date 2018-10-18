#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
const int N = 204000;
int n;
vector<int> v[N];
int vis[N],father[N];
vector<int> line;
int BFS(int s,int flag)
{
    queue<int> q;
    int e=s;
    line.clear();
    memset(vis,0,sizeof(vis));
    memset(father,-1,sizeof(father));
    vis[flag]=1;
    q.push(s);
    vis[s]=1;
    int ans=1;
    while(!q.empty())
    {
        int f=q.front();
        q.pop();
        for(int i=0; i<v[f].size(); i++){
            int k=v[f][i];
            if(vis[k])
                continue;
            vis[k]=vis[f]+1;
            father[k]=f;
            if(vis[k]>ans){
                e=k;
                ans=vis[k];
            }
            q.push(k);
        }
    }
    for(int i=e;i!=-1;i=father[i])
        line.push_back(i);
    return e;
}
struct Node
{
    int one,two,ans;
};
void print()  //输出
{
    for(int i = 0;i<line.size();i++)
    {
        printf("x%d ",line[i]);
    }
    printf("\n");
}
pair<int,int> Yougth(int s,int t)
{
    int p1 = BFS(s,t);
    int p2 = BFS(p1,t);
    int len = line.size();
    int one = line[len/2];
    int tmp = len/2;
    pair<int,int> ans(one,tmp);
    return ans;
}
Node Importent(int fir,int sec)
{
    Node pps;
    int ans = -1;
    pair<int,int> tt = Yougth(fir,sec);
    pps.one = tt.first;
    ans = max(ans,tt.second);
    tt = Yougth(sec,fir);
    pps.two = tt.first;
    ans = max(ans , tt.second);
    pps.ans = ans;
    return pps;
}
void solve()
{
    Node pps,ans2;
    int p1 = BFS(1,n+1);
    int p2 = BFS(p1,n+1);
    int len = line.size()/2;
    int a = line[len-1],b = line[len] , c = line[len+1];
    if(line.size()%2==0)
    {
        pps = Importent(a,b);
    }
    else
    {
        pps = Importent(a,b);
        ans2 = Importent(b,c);
        if(ans2.ans<pps.ans)    //取小的。但是好像没有这样的数据
            pps = ans2;
    }
    printf("%d %d %d\n",pps.ans,pps.one,pps.two);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=0;i<n-1;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            v[x].push_back(y);
            v[y].push_back(x);
        }
        solve();
        for(int i=0;i<=n;i++)
            v[i].clear();
    }
    return 0;
}
