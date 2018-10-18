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
int n, top;
inline int Dist(Point a, Point b){
    return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}
inline int mult(Point a, Point b, Point c){
    return (a.x - c.x) * (b.y - c.y) - (b.x - c.x)*(a.y - c.y);
}
inline bool cmp(Point l, Point r){
    return l.y < r.y ||(l.y == r.y && l.x < r.x);
}
inline int Graham(){
    int len;
    top = 1;
    if(n < 2){
        res[0] = p[0]; return 1;
    }
    sort(p, p+n, cmp);
    res[0] = p[0]; res[1] = p[1];
    for(int i = 2; i < n; i++){
        while(top && mult(p[i], res[top], res[top-1])>=0) --top;
        res[++top] = p[i];
    }
    len = top;res[++top] = p[n-2];
    for(int i = n-3; i >= 0; --i){
        while(top != len && mult(p[i], res[top], res[top-1])>=0) --top;
        res[++top] = p[i];
    }
    return top;
}
inline int max(int x, int y){
    return (x > y)? x:y;
}
inline int rotating_calipers()
{
    int q=1;
    int ans=0;
    res[top] = p[0];
    for(int i=0;i<top;i++) {
        while(mult(res[i+1], res[q+1], res[i]) > mult(res[i+1], res[q], res[i]))
            q=(q+1)%(top);
        ans=max(ans , max(Dist(res[i],res[q]),Dist(res[i+1], res[q+1])));
    }
    return ans;
}
int main()
{
    while(scanf("%d", &n) != EOF){
        for(int i = 0; i < n; i++)
            scanf("%d%d", &p[i].x, &p[i].y);
        top = Graham();
        printf("%d\n", rotating_calipers());
    }
    return 0;
}
