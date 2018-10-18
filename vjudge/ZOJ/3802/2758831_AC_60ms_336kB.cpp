#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int n;
int dp[2][8010],a[510];
int main()
{
    int n,t,lmax;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);

        dp[0][0]=1;
        lmax=0;
        for(int i=1;i<=n;i++)
        {
            memset(dp[i&1],0,sizeof dp[i&1]);
            for(int j=lmax;j>=0;j--)
            {
                if(dp[(i-1)&1][j])
                {
                    //cout<<i-1<<" "<<j<<" "<<dp[i-1][j]<<endl;
                    if(dp[i&1][j]<dp[(i-1)&1][j])
                        dp[i&1][j]=dp[(i-1)&1][j];
                    int one=2;
                    while(one<j&&(one&j)==0)one<<=1;
                    if(j==0)one=0;
                    if(a[i]>one)
                    {
                        if(dp[i&1][a[i]]<dp[(i-1)&1][j]+a[i])
                            dp[i&1][a[i]]=dp[(i-1)&1][j]+a[i];
                        if(lmax<a[i])lmax=a[i];
                    }
                    else
                    {
                        int c=a[i],cc=a[i];
                        while(cc==one&&one<=j)
                        {
                            cc<<=1;
                            c+=cc;
                            one<<=1;
                            while(one<j&&(one&j)==0)one<<=1;
                        }
                        if(dp[i&1][j+a[i]]<dp[(i-1)&1][j]+c)
                            dp[i&1][j+a[i]]=dp[(i-1)&1][j]+c;
                        if(lmax<j+a[i])lmax=j+a[i];
                    }
                }
            }
        }
            int ans=0;
        for(int i=0;i<=lmax;i++)
            if(ans<dp[n&1][i])ans=dp[n&1][i];
        printf("%d\n",ans-1);
    }
}
