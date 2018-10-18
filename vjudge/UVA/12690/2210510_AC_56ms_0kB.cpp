#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <cstdio>
using namespace std;
#define LL long long
LL ab[100010][5];
int main()
{
    long long n,m,minx,ans;
    memset(ab,0,sizeof ab);
    ab[1][0]=1;
    for(LL i=3;i<=100000;i+=2)
    {
        ab[i][0]=i+ab[i-2][0];//ab
        ab[i][1]=-i*(i-1)+ab[i-2][1];//a,b
        ab[i][2]=i*(i-1)*(i-1)+ab[i-2][2];//c
    }
    while(scanf("%lld%lld",&n,&m)&&n)
    {
        minx=min(n,m);
        LL a=n;
        LL b=m;
        if(minx&1);
        else minx--;
        ans=ab[minx][0]*a*b+ab[minx][1]*(a+b)+ab[minx][2];
        printf("%lld\n",ans);
    }
    return 0;
}
