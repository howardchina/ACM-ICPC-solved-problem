#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define LL long long
LL a,b,n,l,t;
int ok(LL r,LL m)
{
    LL z=a*(r-l+1)+(l-1+r-1)*b*(r-l+1)/2;
    if(m>(r-l+1))m=(r-l+1);
    //cout<<r<<" "<<z<<" "<<m*t<<endl;
    if(z>t*m)return 0;
    else return 1;
}
int main()
{
    while(scanf("%I64d%I64d%I64d",&a,&b,&n)!=EOF)
    {
        LL m,r;
        for(int i=1;i<=n;i++)
        {
            scanf("%I64d%I64d%I64d",&l,&t,&m);
            if(t>=a+b*(l-1))
            {
                LL ll=l,rr=(t-a)/b+1,mm;
                while(ll<rr)
                {
                    mm=(ll+rr)/2;
                    if(ok(mm,m))
                        ll=mm+1;
                    else
                        rr=mm-1;
                }
                while(ok(ll,m)==0)ll--;
                r=ll;
            }
            else
                r=-1;
            printf("%I64d\n",r);
        }
    }
    return 0;
}
