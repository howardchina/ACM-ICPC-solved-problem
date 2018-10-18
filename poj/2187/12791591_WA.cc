#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int maxn = 50005;
struct Point{
    int x, y;
    Point(int xx = 0, int yy = 0){
        x = xx, y = yy;
    }
//    Point operator - (Point b){
//        return Point(x-b.x, y-b.y);
//    }
//    int operator * (Point b){
//        return (x*b.y - y*b.x);
//    }
}p[maxn], res[maxn];
int stack[maxn];
int Dist(Point a, Point b){
    return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}
bool mult(Point a, Point b, Point c){
    return (a.x - c.x) * (b.y - c.y) - (b.x - c.x)*(a.y - c.y);
}
bool cmp(Point l, Point r){
    return l.y < r.y ||(l.y == r.y && l.x < r.x);
}
int Graham(Point pnt[], int n, Point res[]){
    int len, top = 1;
    if(n < 2){
        res[0] = pnt[0]; return 1;
    }
    sort(pnt, pnt+n, cmp);
    res[0] = pnt[0]; res[1] = pnt[1];
    for(int i = 2; i < n; i++){
        while(top && mult(pnt[i], res[top], res[top-1])>=0) --top;
        res[++top] = pnt[i];
    }
    len = top; res[++top] = pnt[n-2];
    for(int i = n-3; i >= 0; --i){
        while(top != len && mult(pnt[i], res[top], res[top-1])>=0) --top;
        res[++top] = pnt[i];
    }
    return top;
}
int rotating_calipers(Point pnt[], int top)  //卡壳
{
    int q=1;
    int ans=0;
    pnt[top] = pnt[0];
    for(int i=0;i<top;i++) {
        while(mult(pnt[i+1], pnt[q+1], pnt[i]) > mult(pnt[i+1], pnt[q], pnt[i]))
            q=(q+1)%(top);
        ans=max(ans , max(Dist(pnt[i],pnt[q]),Dist(pnt[i+1], pnt[q+1])));
    }
    return ans;
}
int main()
{
//    freopen("data.in", "r", stdin);
    int n, tot;
    while(scanf("%d", &n) != EOF){
        for(int i = 0; i < n; i++)
            scanf("%d%d", &p[i].x, &p[i].y);
        tot = Graham(p, n, res);
        printf("%d\n", rotating_calipers(res, tot));
//        for(int i = 0; i < tot; i++){
//            printf("%d %d\n", res[i].x, res[i].y);
//        }

    }
    return 0;
}
