#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<string.h>
using namespace std;
#define LL long long
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
using namespace std;
const double eps = 1e-8;
const double pi = acos(-1.0);//3.1415926...度数转弧度的时候别忘了乘
int dcmp(double x) {return (x > eps) - (x < -eps);} //消除浮点误差比较函数
inline double Sqr(double x) {return x * x;}//平方
/*不用 std::max 和 std::min 的时候*/
/*
inline double min(double a, double b) {return a < b ? a : b;}
inline double max(double a, double b) {return a > b ? a : b;}
*/
//Point 定义
struct Point
{
   /**********一般都要用的**********/
   double x, y;
   Point(){x = y = 0;}
   Point(double a, double b) {x = a, y = b;}

   inline Point operator-(const Point &b)const//重载减法，求 Dis 要调用
   {return Point(x - b.x, y - b.y);}

   inline bool operator<(const Point &b)const//重载<，排序要用
   {return dcmp(x - b.x) ? x < b.x : y < b.y;}

   inline double dot(const Point &b)const//点积
   {return x * b.x + y * b.y;}

   inline double Dis(const Point &b)const//距离
   {return sqrt((*this - b).dot(*this - b));}

   inline double cross(const Point &b, const Point &c)const//三点叉积，(*this).cross(b, c)右手关系为正
   {return (b.x - x) * (c.y - y) - (c.x - x) * (b.y - y);}
   /**********点线关系有时候用的**********/
   /*
   bool Parallel()判断平行，struct 外的函数
   LineCross()直线交点，struct 外的函数
   SegCross()线段交点，struct 外的函数
   ToSeg()点到线段距离，声明在 struct 里具体定义在 struct 外面
   这四个里，下面的一般会调用上面的。
   */
   double ToSeg(const Point&, const Point&)const;//点到线段距离*/

   inline Point operator+(const Point &b)const
   {return Point(x + b.x, y + b.y);}

   inline Point operator*(const double &b)const//x、y 扩大常数倍
   {return Point(x * b, y * b);}

   inline Point operator-()
   {return Point(-x, -y);}

   inline bool InLine(const Point &b, const Point &c)const//三点共线
   {return !dcmp(cross(b, c));}

   inline bool OnSeg(const Point &b, const Point &c)const//点在线段上，包括端点
   {return InLine(b, c) && (*this - c).dot(*this - b) < eps;}
   inline bool InSeg(const Point &b, const Point &c)const//点在线段上，不包括端点
   {return InLine(b, c) && (*this - c).dot(*this - b) < -eps;}
   /**********其他。遇到了再添加**********/
   inline bool operator>(const Point &b)const
   {return b < *this;}

   inline bool operator==(const Point &b)const
   {return !dcmp(x - b.x) && !dcmp(y - b.y);}

   Point RotePoint(const Point &p, double ang)//p 绕*this 逆时针旋转 ang 弧度
   {
       return Point((p.x - x) * cos(ang) - (p.y - y) * sin(ang) + x,
               (p.x - x) * sin(ang) + (p.y - y) * cos(ang) + y);
   }
}pp[110];
Point LineCross(const Point &a, const Point &b, const Point &c, const Point &d)
{
   double u = a.cross(b, c), v = b.cross(a, d);
   return Point((c.x * v + d.x * u) / (u + v), (c.y * v + d.y * u) / (u + v));
}
inline double Sqr(const Point &p) {return p.dot(p);}
double LineCrossCircle(const Point &a, const Point &b, const Point &r, double R, Point &p1, Point &p2)
{
   Point fp = LineCross(r, Point(r.x + a.y - b.y, r.y + b.x - a.x), a, b);
   double rtol = r.Dis(fp), rtos = fp.OnSeg(a, b) ? rtol : min(r.Dis(a), r.Dis(b)), atob = a.Dis(b);
   double fptoe = sqrt(R * R - rtol * rtol) / atob;
   if(rtos > R - eps) return rtos;
   p1 = fp + (a - b) * fptoe;
   p2 = fp + (b - a) * fptoe;
   return rtos;
}
double SectorArea(const Point &r, const Point &a, const Point &b, double R)
//不大于180 度扇形面积，r->a->b 逆时针
{
   double A2 = Sqr(r - a), B2 = Sqr(r - b), C2 = Sqr(a - b);
   return R * R * acos((A2 + B2 - C2) * 0.5 / sqrt(A2) / sqrt(B2)) * 0.5;
}
double TACIA(const Point &r, const Point &a, const Point &b, double R)
//TriangleAndCircleIntersectArea，逆时针，p[0]为圆心
{
   double adis = r.Dis(a), bdis = r.Dis(b);
   if(adis < R + eps && bdis < R + eps) return r.cross(a, b) * 0.5;
   Point ta, tb;
   if(r.InLine(a, b)) return 0.0;
   double rtos = LineCrossCircle(a, b, r, R, ta, tb);
   if(rtos > R - eps) return SectorArea(r, a, b, R);
   if(adis < R + eps) return r.cross(a, tb) * 0.5 + SectorArea(r, tb, b, R);
   if(bdis < R + eps) return r.cross(ta, b) * 0.5 + SectorArea(r, a, ta, R);
   return r.cross(ta, tb) * 0.5 + SectorArea(r, a, ta, R) + SectorArea(r, tb, b, R);
}
double SPICA(Point p[], int n, Point r, double R)//SimplePolygonIntersectCircleArea
//一般两个都写上，只调用 SPICA
{
   int i;
   Point a, b;
   double res = 0, if_clock_t;
   p[n] = p[0];
   for(i = 1; i <= n; ++ i)
   {
       a = p[i - 1], b = p[i];
       if_clock_t = dcmp(r.cross(a, b));
       if(if_clock_t < 0) std::swap(a, b);
       res += TACIA(r, a, b, R) * if_clock_t;
   }
   return fabs(res);
}
int main()
{
    double x0,y0,v0,d0,t,g,r;
    while(scanf("%lf%lf%lf%lf%lf%lf%lf",&x0,&y0,&v0,&d0,&t,&g,&r))
    {
        if(v0+d0+t+g+r<eps)break;
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%lf%lf",&pp[i].x,&pp[i].y);
        Point plast;
        d0=d0/360*2*pi;
        double vx=v0*cos(d0),vy=v0*sin(d0);
        plast.x=x0+vx*t;
        plast.y=y0+vy*t-(g*t*t/2);
        printf("%.2lf\n",SPICA(pp,n,plast,r));
    }
    return 0;
}
