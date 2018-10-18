#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int maxn = 1111;
const double eps = 1e-6;

struct Node{
    int a,b;
    double v;
    bool operator < (const Node& rhs)const{
        return v>rhs.v;
    }
}p[maxn];


int main()
{
//    freopen("data.in","r",stdin);
    int n,k;
    double L,R,u,b;
    while(scanf("%d%d",&n,&k)!=EOF && n+k){
        for(int i=0;i<n;i++) scanf("%d",&p[i].a);
        for(int i=0;i<n;i++) scanf("%d",&p[i].b);
        R=0.5;
        do{
            L = R;
            for(int i=0;i<n;i++){
                p[i].v = p[i].a - L * p[i].b;
            }
            sort(p, p+n);
            u = b = 0;
            for(int i=0;i<n-k;i++){
                u += p[i].a;
                b += p[i].b;
            }
            R = u/b;
        }while(fabs(L-R)>=eps);
        printf("%.0f\n",100*R);
    }
    return 0;
}
