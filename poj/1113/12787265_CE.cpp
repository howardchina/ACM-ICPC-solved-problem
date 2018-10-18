#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define zero 1e-6
#define maxn 1005
#define sqr(x) (x)*(x)
struct Point{
    double x, y;
};
Point p[maxn];
int ch[maxn];
inline int Sgn(double x){
    if(abs(x)<zero) return 0;
    if(x < 0) return -1; else return 1;
}
inline double Cross(Point a, Point b, Point c){
    return (b.x - a.x)*(c.y - a.y) - (c.x - a.x)*(b.y - a.y);
}
inline double Dist(Point a, Point b){
    return sqr(a.x - b.x) + sqr(a.y-b.y);
}
inline bool cmp(Point a, Point b, Point c){ //choose c
    int t = Sgn(Cross(a, b, c));
    if(t != 0) return t < 0;
    return Dist(a, b) < Dist(a, c);
}
inline int GW(int n){
    int m=0, t, k, j = 0;
    for(int i = 1; i <= n; i++){
        scanf("%lf%lf", &p[i].x, &p[i].y);
        if(j == 0 || p[i].x < p[j].x || (Sgn(p[i].x-p[j].x) == 0 && p[i].y <p[j].y))
            j = i;
    }
    t = j;
    while(1){
        k = 0;
        ch[++m] = j;
        for(int i = 1; i <= n; i++){
            if(i != j && (k == 0  || cmp(p[j], p[k], p[i])))
                k = i;
        }
        if(k == t) break;
        j = k;
    }
//    for(int i = 1; i <= m; i++){
//        printf("%.2lf %.2lf\n", p[ch[i]].x, p[ch[i]].y);
//    }
    return m;
}
int Cal(int m, int l){
    double sum = 0;
    for(int i = 1; i < m; i++)
        sum += sqrt(Dist(p[ch[i]], p[ch[i+1]]));
    if(m > 1) sum += sqrt(Dist(p[ch[m]], p[ch[1]]));
    sum += 2*3.14159265*l;
    return round(sum);
}
int main()
{
//    freopen("data.in", "r", stdin);
    int n, l;
    while(scanf("%d%d", &n, &l) != EOF){
        printf("%d\n", Cal(GW(n), l));
    }
    return 0;
}
