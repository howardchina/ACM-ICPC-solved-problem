#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
const double eps=1e-10;
double abs(double x)
{
    if(x<0)return -x;
    return x;
}
int main()
{
    double r,R;
    while(scanf("%lf%lf",&r,&R)!=EOF)
    {
        double a,d,b1,s,r2,ll=0,rr=R*sqrt(3)/2;
        if(r*2>=R+eps)
            printf("NO Solution!\n");
        else
        {
            while(ll+eps<=rr)
            {
                a=(ll+rr)/2;
                d=sqrt(R*R-a*a)+R;
                b1=sqrt(d*d+a*a);
                s=a*d;
                //r2=s/(b1+a);
                //if(abs(r2-r)<eps)break;
                //else
                //{
                    if(s<r*(b1+a))
                        ll=a+eps/2;
                    else rr=a-eps/2;
                //}
            }
            a=(ll+rr)/2;
            d=sqrt(R*R-a*a)+R;
            b1=sqrt(d*d+a*a);
            a*=2;
            printf("%.18lf %.18lf %.18lf\n",a,b1,b1);
        }
    }
}
