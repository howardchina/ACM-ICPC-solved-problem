//非凸多棱柱、凸多面体切割， O(n^2)三角剖分，三维坐标点多种操作
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<vector>
#include<list>
#include<algorithm>
#include<iostream>
using namespace std;

const double eps = 1e-8;
inline int dcmp(double x)
{
    return x > eps ? 1 : (x < -eps ? -1 : 0);
}
inline double pz(double x)
{
    return dcmp(x) ? x : 0;
}
/******************************************************************************/
//定义三维点
struct Point3
{
    double x, y, z;
    Point3()
    {
        x = y = z = 0;
    }
    Point3(double a, double b, double c)
    {
        x = a, y = b, z = c;
    }
    Point3 cross(Point3 p)
    {
        return Point3(y * p.z - p.y * z,
                      z * p.x - x * p.z,
                      x * p.y - y * p.x);
    }

    double dot(Point3 p)
    {
        return x * p.x + y * p.y + z * p.z;
    }
    Point3 operator-(const Point3 &p)const
    {
        return Point3(x - p.x, y - p.y, z - p.z);
    }
    Point3 operator-()const
    {
        return Point3(-x, -y, -z);
    }
    Point3 operator+(const Point3 &p)const
    {
        return Point3(x + p.x, y + p.y, z + p.z);
    }
    Point3 operator*(const double b)const
    {
        return Point3(x * b, y * b, z * b);
    }
    bool operator==(const Point3 &p)const
    {
        return !dcmp(x - p.x) && !dcmp(y - p.y) && !dcmp(z - p.z);
    }
    bool operator!=(const Point3 &p)const
    {
        return !(*this == p);
    }
    bool operator<(const Point3 &p)const
    {
        if(!dcmp(x - p.x))
        {
            if(!dcmp(y - p.y))
                return dcmp(z - p.z) < 0;
            return dcmp(y - p.y) < 0;
        }
        return dcmp(x - p.x) < 0;
    }
    bool operator>(const Point3 &p)const
    {
        return p < *this;
    }
    bool operator>=(const Point3 &p)const
    {
        return !(*this < p);
    }
    bool operator<=(const Point3 &p)const
    {
        return !(*this > p);
    }
    Point3 fxl(Point3 b, Point3 c)//平面法向量
    {
        return (*this - b).cross(b - c);
    }
    double Dis(Point3 b)
    {
        return sqrt((*this - b).dot(*this - b));
    }
    double vlen()
    {
        return sqrt(dot(*this));
    }
    bool PinLine(Point3 b, Point3 c)//三点共线
    {
        return fxl(b, c).vlen() < eps;
    }
    bool PonPlane(Point3 b, Point3 c, Point3 d)//四点共面
    {
        return !dcmp(fxl(b, c).dot(d - *this));

    }
    bool PonSeg(Point3 b, Point3 c)//点在线段上，包括端点
    {
        return !dcmp((*this - b).cross(*this - c).vlen()) &&
               (*this - b).dot(*this - c) <= 0;
    }
    bool PinSeg(Point3 b, Point3 c)//点在线段上，不包括端点
    {
        return PonSeg(b, c) && *this != b && *this != c;
    }
    double PtoLine(Point3 b, Point3 c)//点到直线距离
    {
        return (*this - b).cross(c - b).vlen() / b.Dis(c);
    }
    double PtoPlane(Point3 b, Point3 c, Point3 d)//点到平面距离
    {
        return fabs(b.fxl(c, d).dot(*this - b)) / b.fxl(c, d).vlen();
    }
};
/******************************************************************************/
//定义平面+空间平面凸包
struct Plane
{
    double a, b, c, d;
    bool outplane;//计入表面积的面
    vector<Point3> p;
    Plane()
    {
        a = b = c = d = 0, outplane = false;
        p.clear();
    }
    inline void init(double a_, double b_, double c_, double d_)
    {
        a = a_, b = b_, c = c_, d = d_;
        p.clear();
    }
    inline void init(Point3 pa, Point3 pb, Point3 pc)
    {
        Point3 t = (pa - pb).cross(pa - pc);
        a = t.x, b = t.y, c = t.z;
        d = -(pa.x * t.x + pa.y * t.y + pa.z * t.z);
        p.clear();
    }
    Plane(double a_, double b_, double c_, double d_)
    {
        init(a_, b_, c_, d_);
    }
    Plane(Point3 pa, Point3 pb, Point3 pc)
    {
        init(pa, pb, pc);
    }
    double PtoPlane(const Point3 &pa)const//点面距离
    {
        return fabs(Sub(pa)) / sqrt(a * a + b * b + c * c);
    }
    double Sub(const Point3 &p)const//点代入方程
    {
        return p.x * a + p.y * b + p.z * c + d;
    }
    Point3 PcrossPlane(Point3 a, Point3 b)
    {
        return a + (b - a) * (PtoPlane(a) / (PtoPlane(a) + PtoPlane(b)));//定比分点求法，所以 a、 b 在同侧的时候要变减号
    }
    int Parallel(Plane pl)//面平行
    {
        if(!dcmp(a * pl.b - b * pl.a) && !dcmp(a * pl.c - c * pl.a) && !dcmp(b * pl.c - c * pl.b))
            return dcmp(pl.Sub(p[0])) > 0 ? 1 : -1;
        return 0;

    }
    bool Cut(Plane &pl)//平面切割
    {
        switch(Parallel(pl))
        {
        case -1:
            return true;
        case 1:
            return false;
        }
        int i, j, k, n = p.size();
        bool flag1, flag2;
        Point3 p1, p2;
        vector<Point3> ret;
        for(i = flag1 = flag2 = 0; i < n; ++ i)
        {
            flag1 |= pl.Sub(p[i]) < 0;
            flag2 |= pl.Sub(p[i]) > 0;
        }
        if(flag1 != flag2) return flag1;
        if(!flag1) return true;
        for(i = 0; pl.Sub(p[i]) >= 0; ++ i);
        for(; pl.Sub(p[i]) < 0; i = (i + 1) % n);
        for(j = i; pl.Sub(p[j]) >= 0; j = (j + 1) % n);
        for(k = j; k != i; k = (k + 1) % n)
            ret.push_back(p[k]);
        p1 = pl.PcrossPlane(p[i], p[(i + n - 1) % n]);
        p2 = pl.PcrossPlane(p[j], p[(j + n - 1) % n]);
        ret.push_back(p1), ret.push_back(p2);
        p = ret;
        pl.p.push_back(p1), pl.p.push_back(p2);
        return true;
    }
    void Graham()//求空间平面凸包
    {
        int len, i, n, top = 1;
        vector<Point3> res;
        Point3 fx(a, b, c);
        sort(p.begin(), p.end());
        vector<Point3>::iterator iter = unique(p.begin(), p.end());
        p.erase(iter, p.end());
        n = p.size();
        res.push_back(p[0]), res.push_back(p[1]);
        for(i = 2; i < n; ++ i)
        {
            while(top && dcmp((res[top] - res[top - 1]).cross(p[i] - res[top]).dot(fx)) <= 0)
                res.pop_back(), -- top;
            res.push_back(p[i]), ++ top;
        }
        len = top;
        res.push_back(p[n - 2]), ++ top;
        for(i = n - 3; i >= 0; -- i)
        {
            while(top != len && dcmp((res[top] - res[top - 1]).cross(p[i] - res[top]).dot(fx)) <= 0)
                res.pop_back(), -- top;
            res.push_back(p[i]), ++ top;
        }
        res.pop_back();
        p = res;
    }
    double PolygonArea()//空间平面凸包面积
    {
        int n = p.size();
        double ret = 0;
        for(int i = 2; i < n; ++ i)
            ret += (p[i - 1] - p[0]).cross(p[i] - p[0]).vlen();
        return ret * 0.5;
    }
};


int N;
double Height , Area ;
Point3 P[55];

Point3 TouYing(Plane pl , Point3 p) {
    double t = (pl.a*p.x+pl.b*p.y+pl.c*p.z+pl.d) / (pl.a*pl.a+pl.b*pl.b+pl.c*pl.c);
    return Point3(p.x-pl.a*t,p.y-pl.b*t,p.z-pl.c*t) ;
}

void solve(Plane pl) {
    double H = -1 , S = 1e18 ;
    Plane tmp = pl ;
    for(int i=1; i<=N; i++) {
        H = fmax(H , pl.PtoPlane(P[i])) ;
        tmp.p.push_back(TouYing(pl , P[i])) ;
    }
    tmp.Graham() ;
    S = tmp.PolygonArea() ;

    if(dcmp(H - Height) > 0) {
        Height = H ;
        Area = S ;
    }
    else if(dcmp(H - Height) == 0  && dcmp(S - Area) < 0) {
        Height = H ;
        Area = S ;
    }
}

int main()
{
//    freopen("data.in", "r" ,stdin) ;

    while(scanf("%d", &N) == 1 && N) {
        for(int i=1; i<=N; i++) {
            double x , y , z;
            scanf("%lf%lf%lf", &x, &y, &z) ;
            P[i] = Point3(x , y , z) ;
        }

        Height  = -1  , Area = 1e18 ;

        for(int i=1; i<=N; i++){
            for(int j=i+1; j<=N; j++){
                for(int k=j+1; k<=N; k++) {
                    if(P[i].PinLine(P[j], P[k])) continue ;
                    bool flag1 = false , flag2 = false ;
                    Point3 fax = P[i].fxl(P[j] , P[k]) ;

                    for(int u=1; u<=N; u++) {
                        if(u==i || u==j || u==k) continue ;
                        int tmp = dcmp( fax.dot(P[u] - P[i]) ) ;
                        if(tmp > 0) flag1 = true ;
                        if(tmp < 0) flag2 = true ;
                    }

                    if(flag1 && flag2) continue ;

                    Plane pl(P[i] , P[j] , P[k]) ;

                    solve(pl) ;
                }
            }
        }

        printf("%.3f %.3f\n" , Height , Area) ;

    }
    return 0 ;
}
