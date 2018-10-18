#include <iostream>
#include <cstdio>
using namespace std;

typedef long long LL;

const int maxn = 1000011;

int a[maxn];

int main()
{
//    freopen("data.in", "r", stdin);
    int T;
    scanf("%d", &T);
    while(T--){
        int n; scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
        }

        int mx = -1;
        LL ans = 0;
        for(int i = n; i >= 1; i--){
            if (a[i] > mx){
                mx = a[i];
            }
            if (a[i] < mx){
                ans += mx - a[i];
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
