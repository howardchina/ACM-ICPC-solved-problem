#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>
using namespace std;
int dp[23][13][166];
int main()
{
    int n,k,s;
    memset(dp,0,sizeof dp);
    dp[0][0][0]=1;
    for(int j=0;j<=10;j++)
        for(int i=0;i<=20;i++)
            for(int s=155;s>=0;s--)
            if(dp[i][j][s])
                for(int e=i+1;e<=20&&s+e<=155;e++)
                dp[e][j+1][s+e]+=dp[i][j][s];
    for(int s=155;s>=0;s--)
    for(int j=0;j<=10;j++)
        for(int i=1;i<=20;i++)
            dp[i][j][s]+=dp[i-1][j][s];
    while(scanf("%d%d%d",&n,&k,&s)&&n)
    {
        printf("%d\n",dp[n][k][s]);
    }
    return 0;
}
