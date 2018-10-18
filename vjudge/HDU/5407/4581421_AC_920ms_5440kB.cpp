#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long LL;
const int maxn = 1e6 + 10;
const int mod = 1000000007;

int a[333];

int fact[maxn];

void init(int n){
    for(int i = 2; i <= n; i+=2){
        fact[i] = 2;
    }
    for(int i = 3; i <= n; i+=2){
        if (fact[i]) continue;
        for(int j = i; j <= n; j+=i){
            if (fact[j]) continue;
            fact[j] = i;
        }
    }
}

int powmod(int x,int b){
    int re = 1;
    while(b){
        if (b&1) re = ((LL)re*x)%mod;
        x = ((LL)x * x )%mod;
        b >>= 1;
    }
    return re;
}

int main()
{
//    freopen("data.in", "r", stdin);
    int T, n = 1;
    scanf("%d", &T);
    for(int i = 0; i < T; i++){
        scanf("%d", &a[i]);
        n = max(n, a[i]);
    }
    init(n);
    for(int _i = 0; _i < T; _i++){
        n = a[_i] + 1;
        int mul = 1;
        for(int i = 2; i <= n; i++){
            if (fact[i] != i) continue;
            int b = floor(log(n)/log(i) + 0.0000001);
            mul = ((LL)mul * powmod(i, b))%mod;
        }
        int ans = ((LL)mul * powmod(n, mod-2))%mod;
        printf("%d\n", ans);
    }

    return 0;
}
