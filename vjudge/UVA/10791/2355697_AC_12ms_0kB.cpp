#include <cstdio>
#include <cstring>
#include <cmath>
typedef long long LL;
int main()
{
//    freopen("data.in", "r", stdin);
    LL cas = 1, ans, n, i, k;
    while(scanf("%lld", &n) != EOF && n){
        ans = 0, k = 0;
        for(i = 2; i*i<= n; i++){
            if(n%i == 0){
                LL tmp = 1;
                while(n%i == 0){
                    tmp *= i;
                    n /= i;
                }
                ans += tmp;
                k++;
            }
        }
        if(n > 1 || k == 0){
            ans += n;
            k++;
        }
        if(k == 1) ans++;
        printf("Case %lld: %lld\n", cas++, ans);
    }
    return 0;
}
