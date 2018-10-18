#include <iostream>
#include <cstdio>
#define  mp(a, b) make_pair((a), (b))
#define  Rep(i, base, n) for(int i = base; i < n; i++)
using namespace std;
typedef long long  LL;
const int maxn = 500000 + 1090;
LL sum[maxn];
int a[maxn];
pair<LL, int> pa[maxn];
int main()
{
    int T;
    for(int t = scanf("%d", &T); t<= T; t++) {
        int n;
        LL X;
        scanf("%d%lld", &n, &X);
        Rep(i, 1, n+1) scanf("%d", a+i), sum[i] = sum[i-1] + a[i];
        int ans = n+1;
        int p , q;
        p = q = n+1;
        for(int i = n; i >= 1; i--) {
            while(q < p && pa[q].first <= sum[i]) q++;//寻找比sum[i]大的和，将sum[i]放在其后面
            pa[--q] = mp(sum[i], i);//形成和从大到小，下标由大到小的顺序；
            int low = lower_bound(pa+q, pa+p, mp(sum[i-1] + X, 0)) - pa;//查找比sum[i-1]+X大的最左边的元素。
            if(low < p) ans = min(ans, pa[low].second - i+1);
        }
        printf("%d\n", (ans == n+1) ? -1 : ans);
    }
    return 0;
}
