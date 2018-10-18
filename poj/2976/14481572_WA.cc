#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int maxn = 1111;
const double eps = 1e-7;

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
        for(int i=0;i<n;i++) scanf("%d",&p[i].a);
        for(int i=0;i<n;i++) scanf("%d",&p[i].b);
        R=1;
        do{
            L = R;
            u=b=0;
            for(int i=0;i<n;i++){
                p[i].v = p[i].a-L*p[i].b;
            }
            sort(p,p+n);
            for(int i=n-k-1;i>=0;i--){
                u+=p[i].a;
                b+=p[i].b;
            }
            R = u/b;
        }while(fabs(L-R)>=eps);
        printf("%.0lf\n",100*R);
    }
    return 0;
}
