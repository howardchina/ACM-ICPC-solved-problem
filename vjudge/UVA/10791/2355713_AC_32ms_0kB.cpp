#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long LL;
LL num[111], b[111];
int main()
{
//    freopen("data.in", "r", stdin);
    LL cas = 1, ans, n, i, j, k;
    while(scanf("%lld", &n) != EOF && n){
        k = 0;
        j = n;
        LL tmp = sqrt(n+0.5);
        for(i = 2; i <= tmp; i++){
            if(j%i == 0){
                b[k] = 0;
                while(j%i == 0)
                    b[k]++, j/=i;
                num[k++] = i;
            }
        }
        if(j > 1) num[k] = j, b[k++] = 1;
        if(n == j) ans = n+1;
        else{
            ans = 0;
            for(i = 0; i < k; i++)
                ans += pow(num[i], b[i]);
            if(k == 1) ans+=1;
        }
        printf("Case %lld: %lld\n", cas++, ans);
    }
    return 0;
}
