#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;

typedef pair<double,double> point2;
#define x first
#define y second
#define MP make_pair

int main()
{
//    freopen("data.in","r",stdin);
    int n;
    point2 A,B,C,D;
    double len,d,sum;
    while(1){
        scanf("%d",&n);
        if(!n) break;
        scanf("%lf%lf%lf%lf",&A.x,&A.y,&B.x,&B.y);
        if(A.y/A.x < B.y/B.x){
            swap(A,B);
        }
        d=0;
        sum=0;
        while(n--){
            scanf("%lf",&len);
            d+=len;
            sum+=len*len;
        }
        if(fabs(A.y/A.x -B.y/B.x)<1e-10){
            printf("0.000\n");
            continue;
        }
        C.x = d*(A.x*B.y + A.x*B.x)/(B.x*A.y - A.x*B.y);
        C.y = A.y*C.x/A.x;
        D.x = C.x + d;
        D.y = C.y - d;
        double tot,bot,ans;
        tot = (D.x+D.y)*C.y/2;
        bot = (D.x+D.y)*D.y/2;
        sum /= 2.0;
        ans = tot - bot - sum;
        printf("%.3f\n",ans);
    }


    return 0;
}
