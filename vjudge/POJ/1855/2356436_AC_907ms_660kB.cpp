#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
int gcd(int a, int b){
    return a%b?gcd(b, a%b):b;
}
LL lcm(int a, int b){
    return (LL)a*(LL)b/(LL)gcd(a,b);
}
int a[55];
int main()
{
//    freopen("data.in", "r", stdin);
    int n, t;
    while(scanf("%d%d", &n, &t) && n+t){
        for(int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        while(t--){
            LL ans1 = 0, ans2 = 0x3f3f3f3fLL, m;
            scanf("%lld", &m);
            for(int i = 3; i < n; i++){
                for(int j = 2; j < i; j++){
                    LL tmp = lcm(a[i], a[j]);
                    for(int k = 1; k < j; k++){
                        LL tmp2 = lcm(tmp, a[k]);
                        for(int p = 0; p < k; p++){
                            LL tmp3 = lcm(tmp2, a[p]);
                            LL tmp4 = m/tmp3*tmp3;
                            if(tmp4 > ans1) ans1 = tmp4;
                            LL tmp5 = tmp4 + (m%tmp3?tmp3:0);
                            if(tmp5 < ans2) ans2 = tmp5;
                            if(ans1 == ans2){
                                i = j = k = p = n;
                            }
                        }
                    }
                }
            }
            printf("%lld %lld\n", ans1, ans2);
        }
    }
    return 0;
}
