#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 40000 + 10;

int a[N];

int main()
{
//    freopen("data.in", "r", stdin);
//    freopen("data.out", "w", stdout);
    int T, n, m;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &n, &m);
        int x, sum=0;
        for(int i=0;i<n;i++){
            scanf("%d", &x);
            a[i] = x;
            sum += x;
        }
        sort(a, a+n);
        int ans = 0;
        if (a[n-1] * m >= sum) ans = a[n-1];
        else ans = (sum - a[n-1] * m ) / m + ((sum - a[n-1] * m ) % m ? 1 : 0) + a[n-1];
        printf("%d\n", ans);
    }

    return 0;
}
