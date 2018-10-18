
#include <iostream>
#include <cstdio>
using namespace std;

typedef long long LL;


int main()
{
//    freopen("data.in","r",stdin);
    LL low,high;
    while(scanf("%lld%lld",&low,&high)!=EOF && low){
        LL x = low/5;
        LL y = high/5;
        printf("%lld\n",y-x+1);
    }


    return 0;
}
