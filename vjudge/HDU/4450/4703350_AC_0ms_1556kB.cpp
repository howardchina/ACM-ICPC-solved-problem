#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
//    freopen("data.in", "r", stdin);
    int n, x, ans;
    while(1){
        scanf("%d", &n);
        if (!n) break;
        ans = 0;
        while(n--){
            scanf("%d", &x);
            ans += x*x;
        }
        printf("%d\n", ans);
    }
    return 0;
}
