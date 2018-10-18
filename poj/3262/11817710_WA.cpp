#include <stdio.h>
#include <stdlib.h>

typedef long long LL;
const int MAXN = 100000+ 100;
struct Node{
    int t, d;
} cow[MAXN];

int comp(const void *a, const void *b)
{
    if((*(Node *)a).d != (*(Node *)b).d) {
        return (*(Node *)b).d - (*(Node *)a).d;
    }
    return (*(Node *)a).t - (*(Node *)b).t;
}

int main()
{
    LL ans;
    int n, i;
    while(~scanf("%d", &n)) {
        ans = 0;
        for(i = 0; i < n; i++) scanf("%d%d", &cow[i].t, &cow[i].d);
        qsort(cow, n, sizeof(Node), comp);
        for(i = n-2; i >= 0; i--) {
            cow[i].d += cow[i+1].d;
        }
        for(i = 1; i < n; i++) {
            ans += (cow[i].d*cow[i-1].t*2);
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
