#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 100 + 10;
const int inf = 0x3f3f3f3f;
int dp[maxn][maxn];
int a[maxn];

int DP(int l, int r){
    int& re = dp[l][r];
    if (re != -1) return re;
    if (l >= r){
        return 0;
    }
    re = inf;
    int D = a[l] - a[l-1];
    for(int i = l, k = 0; i <= r; i++, k++){
        re = min(re, DP(l+1, i) + k*D + DP(i+1, r) + (a[r] - a[i]) * (k+1) );
    }
    return re;
}

int main()
{
//    freopen("data.in", "r", stdin);
    int T, cas = 1;
    scanf("%d", &T);
    while(T--){
        int n;
        scanf("%d", &n);
        a[0] = 0;
        for(int i = 1; i<= n; i++){
            scanf("%d", &a[i]);
            a[i] += a[i-1];
        }
        memset(dp, -1, sizeof dp);
        int ans = DP(1, n);
        printf("Case #%d: %d\n", cas++, ans);
    }

    return 0;
}
