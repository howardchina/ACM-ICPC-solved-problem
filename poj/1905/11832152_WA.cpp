#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INF 0xffffff


int main()
{
    double dl, dn, dc, dl1, seg, ans, mid, left, right;
    while(~scanf("%lf%lf%lf", &dl, &dn, &dc)) {
        if(dl == -1 && dn == -1 && dc == -1) break;
        dl1 = (1.0 + dn * dc) * dl;
        left = 0; right = INF; mid = (left + right)/2.0;
        seg = mid * 2 * asin(dl/2.0/mid);
        while(fabs(seg - dl1) >= 0.00000001) {
            if(seg < dl1) {
                right = mid;
            } else if(seg > dl1) {
                left = mid;
            } else {
                break;
            }
            mid = (left + right)/2.0;
            seg = mid * 2 * asin(dl/2.0/mid);
        }
        ans = mid - sqrt(mid*mid-dl*dl/4.0);
        printf("%.3lf\n", ans);
    }
    return 0;
}
