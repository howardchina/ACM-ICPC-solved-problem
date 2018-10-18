#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
long long dp[2][(1<<20)+10];
int k[50];
int main()
{
    int t,n;
    scanf("%d",&t);
    for(int ca=1;ca<=t;ca++)
    {
        int n,m;
        long long ans=0;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            scanf("%d",&k[i]);
        memset(dp,0,sizeof dp);
        int mm=0;
        dp[0][0]=1;
        for(int i=1;i<=n;i++)
        {
            memset(dp[i&1],0,sizeof dp[i&1]);
            for(int s=mm;s>=0;s--)
            if(dp[(i+1)&1][s])
            {
                //cout<<i<<" "<<s<<" "<<dp[(i+1)&1][s]<<endl;
                //cout<<(s^k[i])<<endl;
                dp[i&1][s]+=dp[(i+1)&1][s];
                dp[i&1][s^k[i]]+=dp[(i+1)&1][s];
                if(mm<(s^k[i]))mm=(s^k[i]);
            }
        }
        for(int i=m;i<=mm;i++)
        ans+=dp[n&1][i];
        printf("Case #%d: %I64d\n",ca,ans);
    }
}
