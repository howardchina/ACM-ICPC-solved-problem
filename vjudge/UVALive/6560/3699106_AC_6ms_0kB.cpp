#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<string.h>
using namespace std;
int a[1010][3],dp[1010][8];
int main()
{
    int n,ans=0,ca=1;
    while(scanf("%d",&n)&&n)
    {
        ans=0;
        memset(dp,0,sizeof dp);
        memset(a,0,sizeof a);
        for(int j=0;j<=2;j++)
            for(int i=1;i<=n;i++)
                scanf("%d",&a[i][j]);
        dp[0][3]=a[1][1]*a[1][2];
        dp[0][6]=a[1][1]*a[1][0];
        dp[0][7]=max(dp[0][3],dp[0][6]);
    for(int i=1;i<=n;i++)
    {
        dp[i][0]=max(dp[i][0],dp[i-1][4]+a[i][1]*a[i][2]);
        dp[i][0]=max(dp[i][0],dp[i-1][1]+a[i][1]*a[i][0]);
        dp[i][0]=max(dp[i][0],dp[i-1][7]);

        dp[i][1]=max(dp[i][1],dp[i-1][6]+a[i][2]*a[i+1][2]);

        dp[i][2]=max(dp[i][2],dp[i-1][5]+a[i][1]*a[i+1][1]);

        dp[i][3]=max(dp[i][3],dp[i-1][7]+a[i+1][1]*a[i+1][2]);
        dp[i][3]=max(dp[i][3],dp[i-1][4]+a[i][1]*a[i+1][1]+a[i][2]*a[i+1][2]);

        dp[i][4]=max(dp[i][4],dp[i-1][3]+a[i][0]*a[i+1][0]);

        dp[i][5]=max(dp[i][5],dp[i-1][2]+a[i][0]*a[i+1][0]+a[i][2]*a[i+1][2]);

        dp[i][6]=max(dp[i][6],dp[i-1][7]+a[i+1][1]*a[i+1][0]);
        dp[i][6]=max(dp[i][6],dp[i-1][1]+a[i][1]*a[i+1][1]+a[i][0]*a[i+1][0]);

        dp[i][7]=max(dp[i][7],dp[i-1][0]+a[i][1]*a[i+1][1]+a[i][0]*a[i+1][0]+a[i][2]*a[i+1][2]);
        dp[i][7]=max(dp[i][7],dp[i-1][3]+a[i][0]*a[i+1][0]+a[i+1][1]*a[i+1][2]);
        dp[i][7]=max(dp[i][7],dp[i-1][6]+a[i][2]*a[i+1][2]+a[i+1][1]*a[i+1][0]);

        //cout<<i<<" 0 "<<dp[i][0]<<endl;
        //cout<<i<<" 1 "<<dp[i][1]<<endl;
        //cout<<i<<" 2 "<<dp[i][2]<<endl;
        //cout<<i<<" 3 "<<dp[i][3]<<endl;
        //cout<<i<<" 4 "<<dp[i][4]<<endl;
        //cout<<i<<" 5 "<<dp[i][5]<<endl;
        //cout<<i<<" 6 "<<dp[i][6]<<endl;
        //cout<<i<<" 7 "<<dp[i][7]<<endl;

        dp[i][1]=max(dp[i][1],dp[i][0]);
        dp[i][2]=max(dp[i][2],dp[i][0]);
        dp[i][4]=max(dp[i][4],dp[i][0]);

        dp[i][3]=max(dp[i][3],dp[i][1]);
        dp[i][3]=max(dp[i][3],dp[i][2]);

        dp[i][5]=max(dp[i][5],dp[i][1]);
        dp[i][5]=max(dp[i][5],dp[i][4]);

        dp[i][6]=max(dp[i][6],dp[i][2]);
        dp[i][6]=max(dp[i][6],dp[i][4]);

        dp[i][7]=max(dp[i][7],dp[i][3]);
        dp[i][7]=max(dp[i][7],dp[i][5]);
        dp[i][7]=max(dp[i][7],dp[i][6]);
    }
    for(int i=0;i<=7;i++)ans=max(ans,dp[n][i]);
    printf("Case %d: %d\n",ca++,ans);
    }
    return 0;
}
