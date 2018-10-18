#include<stdio.h>
#include<math.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define LL long long
LL const  MOD=1000000007;
int n;
int tri[5000100];
int er[5000100];
int main()
{
    int CA=1;
    er[0]=1;
    for(int i=1;i<=5000000;i++)
    {
        tri[i]=tri[i-1] + (i-1)/2 - i/3 + (i%3?0:1);
        if(!(i&1))tri[i]-=i/4;
        if(tri[i]>=MOD) tri[i]-=MOD;
        if(tri[i]<0) tri[i]+=MOD;
        er[i]=(er[i-1]<<1)%MOD;
        //cout<<i<<" "<<tri[i]<<endl;
    }
    for(int i=3;i<=5000000;i++)
        for(int j=i+i;j<=5000000;j+=i)
        {
            tri[j]-=tri[i];
            if(tri[j]<0)
                tri[j]+=MOD;
        }
    while(scanf("%d",&n)!=EOF){
        LL ans=0;
        for(int i=1;i*i<=n;i++)
            if(n%i==0)
            {
                ans=(ans+(LL)tri[i]*er[n/i-1])%MOD;
                if(i*i!=n)
                    ans=(ans+(LL)tri[n/i]*er[i-1])%MOD;
            }
        printf("Case %d: %I64d\n",CA++,ans%MOD);
    }
    return 0;
}
