#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const double pi = 3.14159265;

int main()
{
    double dl, dn, dc, dl1, seg, ans, mid, left, right;
    while(~scanf("%lf%lf%lf", &dl, &dn, &dc)) {
        if(dl == -1 && dn == -1 && dc == -1) break;
        if(dn * dc < 0.000001) {
            printf("0.000\n");
            continue;
        }
        dl1 = (1.0 + dn * dc) * dl;
        left = 0; right = pi; mid = (left + right)/2.0;
        seg = dl/2.0/sin(mid)*2*mid;
        while(fabs(seg - dl1) >= 0.0000001) {
            if(seg < dl1) {
                left = mid;
            } else if(seg > dl1) {
                right = mid;
            } else {
                break;
            }
            mid = (left + right)/2.0;
            seg = dl/2.0/sin(mid)*2*mid;
        }
        ans = dl/2.0/sin(mid) * (1-cos(mid));
        printf("%.3lf\n", ans);
    }
    return 0;
}
