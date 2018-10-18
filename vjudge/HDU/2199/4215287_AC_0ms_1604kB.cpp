#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const double eps = 1e-6;

double cal(double x){
    return 8*x*x*x*x + 7*x*x*x + 2*x*x + 3*x + 6;
}

int main()
{
//    freopen("data.in","r",stdin);
    int T;
    double Y;
    scanf("%d", &T);
    while(T--){
        scanf("%lf", &Y);
        double l=0, r=100, m;
        for(int i=0;i<60;i++){
            m = (l + r)/2;
            if (cal(m) >= Y){
                r = m;
            }
            else{
                l = m;
            }
        }
        if (abs(cal(m)-Y)<=eps){
            printf("%.4f\n", m);
        }
        else{
            puts("No solution!");
        }

    }
    return 0;
}
