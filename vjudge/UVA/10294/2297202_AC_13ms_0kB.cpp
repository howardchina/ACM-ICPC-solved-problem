#include <iostream>
#include <cstdio>

using namespace std;
typedef long long LL;

LL pow(LL a, LL b){
    LL ret = 1;
    while(b){
        if(b&1) ret *= a;
        a*=a;
        b>>=1;
    }
    return ret;
}

LL gcd(LL a, LL b){
    return (b)?gcd(b,a%b):a;
}


int main()
{
//    freopen("data.in", "r", stdin);
    LL N, t, ans1, ans2;
    while(scanf("%lld%lld", &N, &t) != EOF){
        ans1 = 0;
        for(LL i = 1; i <= N; i++){
            ans1 += pow(t,gcd(N,i));
        }
        if(N&1){
            ans2 = ans1 + N*pow(t,(N+1)/2);
        }else{
            ans2 = ans1 + pow(t,N/2)*N/2*(t+1);
        }
        printf("%lld %lld\n", ans1/N, ans2/N/2);
    }
    return 0;
}
