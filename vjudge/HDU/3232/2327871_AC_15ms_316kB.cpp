#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
//    freopen("data.in", "r", stdin);
    int n, d, p, l, v, cas = 1;
    while(scanf("%d%d", &n, &d) != EOF && n+d){
        double ans = 0;
        while(n--){
            scanf("%d%d%d", &p, &l, &v);
            ans += (double)l/v*2;
            d -= l;
        }
        ans += (double)d;
        printf("Case %d: %.3lf\n\n", cas++, ans);
    }
    return 0;
}
