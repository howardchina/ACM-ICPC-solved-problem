#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
struct node{
    int st, ed, c;//c是cover层数
    double m;//m是测度？？？
}ST[802];

struct line{
    double x, y1, y2; //纵直线 x横坐标 y1上坐标 y2下坐标
    bool s;//1 矩形的左纵线 0代表矩形的右纵线
}Line[205];
double y[205], ty[205];

void build(int root, int st, int ed){
    ST[root].st = st;
    ST[root].ed = ed;
    ST[root].c = 0;
    ST[root].m = 0;
    if(ed - st > 1){
        int mid = (st+ed)>>1;
        build(root<<1, st, mid);
        build((root<<1)|1, mid, ed);
    }
}
inline void updata(int root){
    if(ST[root].c > 0)
        ST[root].m = y[ST[root].ed-1] - y[ST[root].st-1];
    else if(ST[root].ed - ST[root].st == 1)
        ST[root].m = 0;
    else ST[root].m = ST[root<<1].m + ST[(root<<1)|1].m;
}
void insert(int root, int st, int ed, bool s){
    if(st <= ST[root].st && ST[root].ed <= ed){
        if(s) ST[root].c++;
        else ST[root].c--;
        updata(root);
        return ;
    }
    if(ST[root].ed - ST[root].st == 1) return ;
    int mid = (ST[root].ed + ST[root].st) >> 1;
    if(st < mid) insert(root<<1, st, ed, s);
    if(ed > mid) insert((root<<1)|1, st, ed, s);
    updata(root);
}
int Correspond(int n, double t){
    int low, high, mid;
    low = 0, high = n-1;
    while(low < high){
        mid = (low+high)>>1;
        if(y[mid] < t) low = mid + 1;
        else high = mid;
    }
    return high+1;//???
}
bool cmp(line l1, line l2){
    return l1.x < l2.x;
}
int main()
{
//    freopen("data.in", "r", stdin);
    int n, i, num, l, r, c = 0;
    double area, x1, x2, y1, y2;
    while(scanf("%d", &n) && n){
        for(i = 0; i < n; i++){
            scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
            Line[i<<1].x = x1;
            Line[i<<1].y1 = y1; Line[i<<1].y2 = y2;
            Line[i<<1].s = 1;
            Line[(i<<1)|1].x = x2;
            Line[(i<<1)|1].y1 = y1; Line[(i<<1)|1].y2 = y2;
            Line[(i<<1)|1].s = 0;
            ty[i<<1] = y1;ty[(i<<1)|1] = y2;
        }
        n <<= 1;
        sort(Line, Line+n, cmp);
        sort(ty, ty+n);
        y[0] = ty[0];
        for(i = num = 1; i < n; i++)
            if(ty[i] != ty[i-1]) y[num++] = ty[i];
        build(1, 1, num);
        area = 0;
        for(i = 0; i < n-1; i++){
            l = Correspond(num, Line[i].y1);
            r = Correspond(num, Line[i].y2);
            insert(1, l, r, Line[i].s);
            area += ST[1].m * (Line[i+1].x - Line[i].x);
        }
        printf("Test case #%d\n", ++c);
        printf("Total explored area: %.2lf\n\n", area);
    }
    return 0;
}
