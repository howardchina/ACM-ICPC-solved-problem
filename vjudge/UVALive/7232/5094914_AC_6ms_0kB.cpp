#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const int maxn = 100010;

typedef long long LL;

struct Node{
    int k, d;
    bool operator < (const Node &rhs)const{
        if (k != rhs.k) return k > rhs.k;
        return d > rhs.d;
    }
}b[maxn];

struct Point{
    LL x, y;
    int mark;
    Point(int x=0, int y=0, int mark=0):x(x), y(y), mark(mark){}
    double len(){
        return sqrt((double)x*x + (double)y*y);
    }
}a[maxn], c[maxn*2];

Point operator + (const Point &a, const Point &b) {
    return Point(a.x + b.x, a.y + b.y);
}
Point operator - (const Point &a, const Point &b) {
    return Point(a.x - b.x, a.y - b.y);
}
Point operator / (const Point &a, const double &b) {
    return Point(a.x/b, a.y/b);
}
Point operator * (const Point &a, const double &b) {
    return Point(a.x*b, a.y*b);
}
LL operator * (const Point &a, const Point &b) {
    return a.x*b.y - a.y*b.x;
}
int n;

double Dis(Point u, Point v){
    return sqrt((u.x - v.x)*(u.x - v.x) + (u.y - v.y)*(u.y - v.y));
}

double dis[maxn*2];
int q[maxn*2];

Point convert(int k, int d){
    Point u = a[k], v = a[k+1 >= n ? 0 : k+1];
    Point uv = v-u;
    double len = uv.len();
    uv = uv/len;
    return uv * d + u;
}

int check(Point a, Point b, Point c){
    Point ab = (b - a), ac = (c - a);
    LL u = ab * ac;
    if (u > 0) return 1;
    return 0;
}

int main()
{
//    freopen("data.in", "r", stdin);
    int T; scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%I64d%I64d", &a[i].x, &a[i].y);
        }
        int m; scanf("%d", &m);
        for(int i = 0; i < m; i++){
            scanf("%d%d", &b[i].k, &b[i].d);
        }
        sort(b, b + m);
        int nn = 0, j = 0;
        for(int i = n-1; i >=0; i--){
            while(b[j].k >= i && j < m){
                c[nn] = convert(b[j].k, b[j].d);
                c[nn++].mark = 1;
                j++;
            }
            c[nn] = a[i];
            c[nn++].mark = 0;
        }

//        for(int i = 0; i < nn; i++){
//            printf("%I64d %I64d %d\n", c[i].x, c[i].y, c[i].mark);
//        }

        int tail = 0;
        q[tail++] = nn-1;
        q[tail++] = 0;
        dis[nn-1] = 0;
        dis[0] = Dis(c[nn-1], c[0]);
        double sum = 0;
        for(int i = 1; i < nn-1; i++){
            while (tail > 1){
                if (check(c[q[tail-2]], c[q[tail-1]],  c[i])){
                    break;
                }else{
                    tail--;
                }
            }
            dis[i] = dis[q[tail-1]] + Dis(c[q[tail-1]], c[i]);
            q[tail++] = i;
        }
        for(int i = 0; i < nn; i++){
            if (c[i].mark) sum += dis[i];
        }
        printf("%.1lf\n", sum);
    }
    return 0;
}
