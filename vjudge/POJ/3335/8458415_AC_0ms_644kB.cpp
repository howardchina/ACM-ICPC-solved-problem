#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

struct node{
    double x, y;
}point[111],p[111],q[111];
int n,m;
double a,b,c;

void gline(node x_, node y_){
    a = y_.y - x_.y;
    b = x_.x - y_.x;
    c = x_.y * y_.x - x_.x * y_.y;
}

node intersect(node x_, node y_){
    double u, v;
    u = fabs(a*x_.x + b*x_.y + c);
    v = fabs(a*y_.x + b*y_.y + c);
    node re;
    re.x = (x_.x*v + y_.x*u)/(u+v);
    re.y = (x_.y*v + y_.y*u)/(u+v);
    return re;
}

void cut(){
    int cutm = 0;
    for(int i = 1; i <= m; i++){
        if(a*p[i].x + b*p[i].y + c >= 0){
            q[++cutm] = p[i];
        }
        else{
            if(a*p[i-1].x + b*p[i-1].y + c > 0){
                q[++cutm] = intersect(p[i-1],p[i]);
            }
            if(a*p[i+1].x + b*p[i+1].y + c > 0){
                q[++cutm] = intersect(p[i],p[i+1]);
            }
        }
    }
    q[0] = q[cutm];
    q[cutm+1] = q[1];
    for(int i = 0; i <= cutm+1; i++){
        p[i] = q[i];
    }
    m = cutm;
}

void solve(){
    m=n;
    for(int i = 1; i <= n; i++){
        gline(point[i-1], point[i]);
        cut();
    }
    if (m==0) printf("NO\n");
    else printf("YES\n");
}

int main()
{
    //freopen("data.in", "r", stdin);
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%lf%lf", &point[i].x, &point[i].y);
        }
        point[0] = point[n];
        point[n+1] = point[1];
        for(int i = 0; i <= n+1; i++){
            p[i] = point[i];
        }
        solve();
    }

    return 0;
}
