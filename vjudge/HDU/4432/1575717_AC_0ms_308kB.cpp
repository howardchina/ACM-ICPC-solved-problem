#include<iostream>
#include<string.h>
#include<stdio.h>
#define LL long long
using namespace std;
int main()
{
    long long  n,m;

    while(~scanf("%I64d%I64d",&n,&m))
    {
        LL ans=0;
        for(LL i=1;i<=n;i++)
        {
            if (i*i>n) break;
            if (n%i==0)
            {
                LL k1=i,k2=n/i;
                while (k1>0)
                {
                    LL mod=k1%m;
                    ans+=mod*mod;
                    k1=k1/m;
                }
                if ((n/i)!=i)
                {
                k1=k2;
                while (k1>0)
                {
                    LL mod=k1%m;
                    ans+=mod*mod;
                    k1=k1/m;
                }
                }
            }
        }
        int a[200];
        memset(a,0,sizeof(a));
        int t=0;
       // cout<<"ans="<<ans<<endl;
        while(ans>0)
        {
            a[t++]=ans%m;
            ans=ans/m;
        }

        for(int i=t-1;i>=0;i--)
        {
            if (a[i]>=10) printf("%c",'A'-10+a[i]);
            else printf("%d",a[i]);
        }
        printf("\n");

    }
    return 0;
}
