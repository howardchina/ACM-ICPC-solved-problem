#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<stack>
using namespace std;
#define LL long long
LL ans[66];
int f[66];
int main()
{
    int t;
    scanf("%d",&t);
    for(int ca=1;ca<=t;ca++)
    {
        LL n,k,c=1;
        scanf("%I64d%I64d",&n,&k);
        printf("Case #%d:\n",ca);
        for(int i=1;i<=k;i++)
            c=c*2;
        if(n==c)
        {
            c=1;
            for(int i=1;i<k;i++)
            {
                printf("%I64d +\n",c);
                c*=2;
            }
            printf("%I64d +\n",c+1);
        }
        else
        {
            c/=2;
            if((n&1)==0)
            {
                n--;
                ans[k]=c+1;
            }
            else
                ans[k]=c;
            int k1=k;
            while(c)
            {
                if(n&c){
                    f[k1--]=1;
                    c/=2;
                }
                else
                {
                    f[k1--]=1;
                    c/=2;
                    while((n&c)==0)
                    {
                        f[k1--]=-1;
                        c/=2;
                    }
                    f[k1--]=-1;
                    c/=2;
                }
            }
            ans[1]=1;
            for(int i=1;i<=k;i++)
            {
                if(i<k&&i>1)ans[i]=ans[i-1]*2;
                printf("%I64d %c\n",ans[i],f[i]>0?'+':'-');
            }
        }
    }
    return 0;
}
