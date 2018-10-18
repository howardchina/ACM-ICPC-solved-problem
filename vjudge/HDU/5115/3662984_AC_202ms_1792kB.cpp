#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
int dp[210][210];
int a[250],b[250];
int main()
{
    int t,n;
    scanf("%d",&t);
    for(int ca=1;ca<=t;ca++)
    {
        int n,m;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)
            scanf("%d",&b[i]);
        a[0]=a[n+1]=b[0]=b[n+1]=0;
        memset(dp,-1,sizeof dp);
        for(int i=0;i+1<=n+1;i++)
            dp[i][i+1]=0;
        for(int i=0;i+2<=n+1;i++)
            dp[i][i+2]=a[i+1]+b[i]+b[i+2];
        for(int l=3;l<=n+1;l++)
        for(int i=0;i+l<=n+1;i++)
        {
            for(int k=i+1;k<i+l;k++)
            if(dp[i][i+l]==-1||(dp[i][i+l]>dp[i][k]+a[k]+b[i]+b[i+l]+dp[k][i+l]))
            dp[i][i+l]=dp[i][k]+a[k]+b[i]+b[i+l]+dp[k][i+l];
            //cout<<dp[i][i+l]<<" "<<i<<" "<<i+l<<endl;
        }
        printf("Case #%d: %d\n",ca,dp[0][n+1]);
    }
    return 0;
}
