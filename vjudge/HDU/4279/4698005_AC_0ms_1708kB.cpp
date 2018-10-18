#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<algorithm>
#define LL long long
using namespace std;
LL cal(LL x)
{
    if(x<=5)return 0;
    LL r=x/2,t=(LL)(sqrt(x)+1e-12);
    if((t)*(t)>x)t--;
    //cout<<t<<endl;
    if(t&1)r++;
    return r-2;
}
int main()
{
    LL l,r,ans;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        ans=0;
        scanf("%I64d%I64d",&l,&r);
        ans=cal(r)-cal(l-1);
        printf("%I64d\n",ans);
    }
    return 0;
}
