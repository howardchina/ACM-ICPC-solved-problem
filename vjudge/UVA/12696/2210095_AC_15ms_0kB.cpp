#include <iostream>
#include <cstdio>
using namespace std;
const double eps = 1e-8;
int main()
{
//    freopen("data.in", "r", stdin);
    double l,w,d,ww;
    int t, ans;
    while(scanf("%d", &t) != EOF){
        ans = 0;
        while(t--){
            scanf("%lf%lf%lf%lf", &l, &w, &d, &ww);
            if(((l <= 56.0+eps && w <= 45.0+eps && d <= 25.0+eps)
               ||(l+w+d <= 125.0+eps)) && (ww <= 7.0+eps)){
                puts("1");
                ans++;
            }else{
                puts("0");
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
