#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
const double PI=acos(-1.0);
struct POINT
{
 double x;
 double y;
};
double dist(POINT p1,POINT p2)
{
 return( sqrt( (p1.x-p2.x)*(p1.x-p2.x)+
              (p1.y-p2.y)*(p1.y-p2.y) ) );
}
struct Circle{
    double x,y;
    double r;
};

double calArea(Circle c1, Circle c2)
{
    double d;
    double s,s1,s2,s3,angle1,angle2,temp;

    d=sqrt((c1.x-c2.x)*(c1.x-c2.x)+(c1.y-c2.y)*(c1.y-c2.y));
    if(d>=(c1.r+c2.r))//两圆相离
        return 0;
    if((c1.r-c2.r)>=d)//两圆内含,c1大
        return acos(-1.0)*c2.r*c2.r;
    if((c2.r-c1.r)>=d)//两圆内含,c2大
        return acos(-1.0)*c1.r*c1.r;

    angle1=acos((c1.r*c1.r+d*d-c2.r*c2.r)/(2*c1.r*d));
    angle2=acos((c2.r*c2.r+d*d-c1.r*c1.r)/(2*c2.r*d));

    s1=angle1*c1.r*c1.r;s2=angle2*c2.r*c2.r;
    s3=c1.r*d*sin(angle1);
    s=s1+s2-s3;

    return s;
}
double c2area(POINT p1,double r1,POINT p2,double r2)
{

 Circle c1,c2;
 c1.r=r1;
 c2.r=r2;
 c1.x=p1.x;
 c1.y=p1.y;
 c2.x=p2.x;
 c2.y=p2.y;
 return calArea(c1,c2);
}
int main()
{
    int t,n;
    scanf("%d",&t);
    for(int ca=1;ca<=t;ca++)
    {
        double r,R,ans=0,d;
        scanf("%lf%lf",&r,&R);
        POINT a,b;
        scanf("%lf%lf",&a.x,&a.y);
        scanf("%lf%lf",&b.x,&b.y);
        d=dist(a,b);
        if(d<R+R+1e-6)
        {
            if(d>R+r+1e-6)
                ans=c2area(a,R,b,R);
            else
            {
                if(d>r+r+1e-6)
                    ans=c2area(a,R,b,R)-2*c2area(a,R,b,r);
                else
                    ans=c2area(a,R,b,R)-2*c2area(a,R,b,r)+c2area(a,r,b,r);
            }
        }
        printf("Case #%d: %.6lf\n",ca,ans);
    }
}
