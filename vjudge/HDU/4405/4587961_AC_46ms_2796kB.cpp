#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<string.h>
using namespace std;
double dp[100010];
int f[100010];
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)&&n)
    {
        for(int i=0;i<=n+5;i++)
            dp[i]=f[i]=0;
        //memset(dp,0,sizeof (double)*(n+5));
        //memset(f,0,sizeof (int)*n);
        for(int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            f[x]=y;
        }
        for(int i=n-1;i>=0;i--)
        {
            if(f[i])
                dp[i]=dp[f[i]];
            else
            {
                for(int j=1;j<=6;j++)
                    dp[i]+=(dp[i+j]+1.0)/6;
            }
        }
        printf("%.4lf\n",dp[0]);
    }
    return 0;
}
