#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
#define N 1010
int f[N][N],dp[N],ans[N];
int gcis(int a[],int la,int b[],int lb)
{//Êý×é´Ó1-LA
    int i,j,k,mx;
    memset(f,0,sizeof f);
    memset(dp,0,sizeof dp);
    for(i=1;i<=la;i++)
    {
        memcpy(f[i],f[i-1],sizeof f[0]);
        for(k=0,j=1;j<=lb;j++)
        {
            if(b[j-1]<a[i-1]&&dp[j]>dp[k])k=j;
            if(b[j-1]==a[i-1]&&dp[k]+1>dp[j])
            {
                dp[j]=dp[k]+1;
                f[i][j]=i*(lb+1)+k;
            }
        }
    }
    for(mx=0,i=1;i<=lb;i++)
    if(dp[i]>dp[mx])mx=i;
    for(i=la*lb+la+mx,j=dp[mx];j;i=f[i/(lb+1)][i%(lb+1)],j--)
    ans[j-1]=b[i%(lb+1)-1];
    //for(i=0;i<dp[mx];i++)
    //printf("%d ",ans[i]);
    return dp[mx];
}
int main()
{
    int i,an,bn,a[N],b[N],t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&an);
        for(i=0;i<an;++i)
        scanf("%d",&a[i]);
        scanf("%d",&bn);
        for(i=0;i<bn;++i)
        scanf("%d",&b[i]);
        printf("%d\n",gcis(a,an,b,bn));
    }
    return 0;
}
