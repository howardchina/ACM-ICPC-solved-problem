#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int maxn = 1111;
const double eps = 1e-7;

#define FOR(i,n) for(int i=0;i<n;i++)
#define RD(x) scanf("%d",&x)

struct Node{
    int a,b;
    double v;
    bool operator < (const Node& rhs)const{
        return v>rhs.v;
    }
}p[maxn];

int n,k;
double L,R,u,b;

int main()
{
//    freopen("data.in","r",stdin);
    while(1){
        scanf("%d%d",&n,&k);
        if(n==k && n==0) break;
        FOR(i,n){ RD(p[i].a);}
        FOR(i,n){ RD(p[i].b);}
        R=1;
        for(;;){
            L = R;
            u=b=0;
            FOR(i,n){    p[i].v = p[i].a-L*p[i].b;}
            sort(p,p+n);
            FOR(i,n-k){
                u+=p[i].a;
                b+=p[i].b;
            }
            R = u/b;
            if(fabs(L-R)<eps){break;}
        }
        printf("%.0lf\n",100*R);
    }
    return 0;
}
