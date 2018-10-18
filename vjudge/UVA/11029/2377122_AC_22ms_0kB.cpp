#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

char str[222];

int powmod(int a, int b, int mod){
    a%=mod;
    int ret = 1;
    while(b){
        if(b&1) ret = ret*a%mod;
        a = a*a%mod;
        b>>=1;
    }
    return ret;
}

int powdiv(int a, int b){
    double ans = pow(10, 2+fmod(log10(a)*b, 1));
    sprintf(str, "%lf", ans);
    int ret = (str[0]-'0')*100+(str[1]-'0')*10+(str[2]-'0');
    return ret;
}

int main()
{
//    freopen("data.in", "r", stdin);
    int T, n, k;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &n, &k);
        printf("%d...%03d\n", powdiv(n,k), powmod(n,k,1000));
    }
    return 0;
}
