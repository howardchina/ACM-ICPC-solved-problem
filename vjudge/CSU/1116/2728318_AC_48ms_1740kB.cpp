#include<iostream>
#include<string.h>
#include<stdio.h>
#include<vector>
using namespace std;
int dp[(1<<16)+1],n,kk,m,ans,p[20];
vector <int> vt[20];
vector <int> vv[20];
void g()
{
    int i,j,k;
    ans=0;
    memset(dp,-1,sizeof dp);
    dp[1]=0;
    for(i=1;i<(1<<n);i++)
        if(dp[i]>=0)
        {
            int x=0;
            for(k=0;k<n;k++)
            {
                if(i & (1<<k))
                {
                    x+=p[k];
                    //cout<<x<<endl;
                    for(int j=0;j<vt[k].size();j++)
                    if((i & (1<<vt[k][j])) ==0&&dp[i]+vv[k][j]<=kk)
                    {
                        if(dp[i+(1<<vt[k][j])]>=0)dp[i+(1<<vt[k][j])]=min(dp[i+(1<<vt[k][j])],dp[i]+vv[k][j]);
                        else dp[i+(1<<vt[k][j])]=dp[i]+vv[k][j];
                    }
                }
            }
            ans=max(ans,x);
            //cout<<i<<" "<<x<<endl;
        }
    printf("%d\n", ans);
}
int main()
{
    int i,t,u,v,c;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&kk);
        for(i=0;i<n;++i)
        {
            scanf("%d",&p[i]);
            vv[i].clear();
            vt[i].clear();
        }
        for(i=0;i<m;++i)
        {
            scanf("%d%d%d",&u,&v,&c);
            vv[u-1].push_back(c);
            vv[v-1].push_back(c);
            vt[v-1].push_back(u-1);
            vt[u-1].push_back(v-1);
        }
        g();
    }
    return 0;
}
