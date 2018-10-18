#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <math.h>
using namespace std;
const double eps  = 1E-12;
const double PI = acos(-1.0);
struct Point
{
   /**********一般都要用的**********/
   double x, y;
   Point(){x = y = 0;}
   Point(double a, double b) {x = a, y = b;}

   inline Point operator-(const Point &b)const//重载减法，求 Dis 要调用
   {return Point(x - b.x, y - b.y);}

   inline double dot(const Point &b)const//点积
   {return x * b.x + y * b.y;}

   inline double Dis(const Point &b)const//距离
   {return sqrt((*this - b).dot(*this - b));}

   inline double cross(const Point &b, const Point &c)const//三点叉积，(*this).cross(b, c)右手关系为正
   {return (b.x - x) * (c.y - y) - (c.x - x) * (b.y - y);}

   double ToSeg(const Point&, const Point&)const;//点到线段距离*/

   inline Point operator+(const Point &b)const
   {return Point(x + b.x, y + b.y);}

   inline Point operator*(const double &b)const//x、y 扩大常数倍
   {return Point(x * b, y * b);}

   inline Point operator-()
   {return Point(-x, -y);}

   Point RotePoint(const Point &p, double ang)//p 绕*this 逆时针旋转 ang 弧度
   {
       return Point((p.x - x) * cos(ang) - (p.y - y) * sin(ang) + x,
               (p.x - x) * sin(ang) + (p.y - y) * cos(ang) + y);
   }
};
//直线交点
Point LineCross(const Point &a, const Point &b, const Point &c, const Point &d)
{
   double u = a.cross(b, c), v = b.cross(a, d);
   return Point((c.x * v + d.x * u) / (u + v), (c.y * v + d.y * u) / (u + v));
}
//点到线段距离
double Point::ToSeg(const Point &b, const Point &c)const//点到线段距离
{
   Point t(x + b.y - c.y, y + c.x - b.x);
   if(cross(t, b) * cross(t, c) > eps)
       return min(Dis(b), Dis(c));
   return Dis(LineCross(*this, t, b, c));
}
Point ma,cir,p1,p2,p3,p4,ro;
double r,ans;
double cal(double a)
{
    Point roo;
    roo=cir.RotePoint(ro,a);
    double d1=roo.Dis(ma);
    double d2=min(roo.ToSeg(p1,p2),roo.ToSeg(p3,p2));
    double d3=min(roo.ToSeg(p1,p4),roo.ToSeg(p3,p4));
    //cout<<a<<" "<<roo.x<<" "<<roo.y<<" "<<d1+min(d2,d3)<<endl;
    return d1+min(d2,d3);
}
int main()
{
    while(scanf("%lf%lf",&ma.x,&ma.y))
    {
        if(ma.x<eps&&ma.x>-eps&&ma.y<eps&&ma.y>-eps)break;
        scanf("%lf%lf%lf",&cir.x,&cir.y,&r);
        scanf("%lf%lf%lf%lf",&p1.x,&p1.y,&p3.x,&p3.y);
        double d=ma.Dis(cir);
        p2.x=p1.x;p2.y=p3.y;
        p4.y=p1.y;p4.x=p3.x;
        ro.x=cir.x+(ma.x-cir.x)*r/d;
        ro.y=cir.y+(ma.y-cir.y)*r/d;
        double l=-PI/2,r=PI/2,m1,m2;
        while(l+eps<r)
        {
            m1=(l+r)/2;
            m2=(m1+r)/2;
            if(cal(m1)<cal(m2))r=m2;
            else l=m1;
        }
        //cout<<ma.x<<" "<<ma.y<<endl;
        //cout<<cir.x<<" "<<cir.y<<endl;
        //cout<<ro.x<<" "<<ro.y<<endl;
       // for(int i=1;i<=360;i++)
        //{
       //     double a=(i-180)*PI/180;
        //    //cout<<"!";
       //     cal(a);
       // }
        printf("%.2lf\n" , cal(l)) ;
    }
    return 0;
}
