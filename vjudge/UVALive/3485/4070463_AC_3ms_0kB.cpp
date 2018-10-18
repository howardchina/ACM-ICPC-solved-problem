#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

double F(double a,double x){
    double a2 = a*a, x2 = x*x;
    return (x*sqrt(a2+x2)+a2*log(fabs(x+sqrt(a2+x2))))/2;
}

double P(double w,double h){
    double a = 4.0*h/(w*w);
    double b = 1/(2*a);
    return (F(b,w/2)-F(b,0))*4*a;
}

const double eps = 1e-5;

int main()
{
//    freopen("data.in","r",stdin);
    int T,D,H,B,L;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++){
        scanf("%d%d%d%d",&D,&H,&B,&L);
        int n = (D+B-1)/D;
        double D1 = (double)B/n;
        double L1 = (double)L/n;
        double l=0,r=H;

        while(r-l>eps){
            double m = l+(r-l)/2;
            if(P(D1,m)<L1) l = m;
            else r = m;
        }
        printf("Case %d:\n%.2lf\n",cas,H-l);
        if(cas<T) puts("");
    }
}
