#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 50005;
struct Point{
    int x, y;
    Point(int xx = 0, int yy = 0){
        x = xx, y = yy;
    }
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
        while(top>0 && mult(res[top], pnt[i], res[top-1])<=0) --top;
        res[++top] = pnt[i];
    }
    len = top;
    for(int i = n-2; i >= 0; --i){
        while(top > len && mult(res[top], pnt[i], res[top-1])<=0) --top;
        res[++top] = pnt[i];
    }
    return top;
}
inline int max(int x, int y){
    return (x > y)? x:y;
}
int rotating_calipers(Point pnt[], int top)
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
    }
    return 0;
}
