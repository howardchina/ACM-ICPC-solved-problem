#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long LL;

const int maxn = 1e6 + 2;
LL dp[maxn];

int a[maxn], f[maxn], s[maxn];;
int vis[maxn];
int lastp[maxn];

int n;

#define lowbit(x) (x&(-x))
void add(int x){
    while(x <= n){
        vis[x]++;
        x += lowbit(x);
    }
}

int query(int x){
    int re = 0;
    while(x > 0){
        re += vis[x];
        x -= lowbit(x);
    }
    return re;
}

int main()
{
//    freopen("data.in", "r", stdin);
    while(1){
        scanf("%d", &n);
        if (!n) break;

        memset(vis, 0, sizeof vis);

        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);

            lastp[i] = vis[a[i]];
            vis[a[i]] = i;
        }

        memset(vis, 0, sizeof vis);
        f[n+1] = 0;
        for(int i = n; i >= 1; i--){
            f[i] = f[i+1];
            if (!vis[a[i]]){
                f[i]++;
                vis[a[i]]++;
            }
        }

        memset(vis, 0, sizeof vis);
        for(int i = n; i >= 1; i--){
            add(i - lastp[i]);
            s[i] = query(n) - query(i-1);
        }

        dp[1] = n;
        for(int i = 1; i < n; i++){
            dp[i+1] = dp[i] - f[n+1-i] + s[i+1];
        }

        int Q, x;
        scanf("%d", &Q);
        while(Q--){
            scanf("%d", &x);
            printf("%I64d\n", dp[x]);
        }

    }
    return 0;
}
