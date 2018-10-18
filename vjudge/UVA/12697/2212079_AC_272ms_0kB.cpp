#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <cstdio>
using namespace std;
#define LL long long
LL s[500010],sum,qz[500010],qq[500010];
int n,ans;
int main()
{
    //freopen("data.in", "r", stdin);
    int t,b;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%lld",&n,&sum);
        ans=n+1;
        for(int i=1;i<=n;i++)
        scanf("%lld",&s[i]);
        LL x=0;
        s[0]=0;
        b=1;
        for(int i=1;i<=n;i++)
        {
            x+=s[i];
            if(x>=sum)ans=n;
            if(x<0&&ans==n+1){x=0;b=i;}
        }
        if(ans>n)ans=-1;
        else{
            qq[b]=qz[b]=s[b];
            for(int i=b+1;i<=n;i++)
                qq[i]=qz[i]=qz[i-1]+s[i];
            for(int i=b+1;i<=n;i++)
                if(qz[i]<qz[i-1])
                qz[i]=qz[i-1];
                //cout<<endl;
            for(int i=b;i<=n;i++)
            {
                int le=i,r=n;
                if(s[i]<0)continue;
                if(qz[r]-qq[i-1]>=sum)
                {
                    ans=min(ans,r-i+1);
                    //cout<<i<<"!"<<ans<<endl;
                }
                while(le<r)
                {
                    int m=(le+r)/2;
                    if(qz[m]-qq[i-1]>=sum)r=m;
                    else le=m+1;
                }
                if(qz[le]-qq[i-1]>=sum)
                ans=min(ans,le-i+1);
                //cout<<i<<" "<<ans<<endl;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
