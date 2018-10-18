#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int x[55] , y[55] ;
struct Edge{
    int u ,v ;
    double  d;
    bool operator < (const Edge&rhs) const {
        return d < rhs.d ;
    }
}e[10000];
int fa[55] ;
int Find(int x) {
    return fa[x] == x ? x : fa[x] = Find(fa[x]) ;
}

double dist(int u ,int v){
    return sqrt( (x[u] - x[v])*(x[u] - x[v]) + (y[u] - y[v]) * (y[u] - y[v]) + 0.0 ) ;
}

int main()
{
    int N ;
    while(scanf("%d", &N) == 1 && N) {
        int p , q;
        scanf("%d%d", &p, &q) ;
        for(int i=1; i<=N; i++) scanf("%d%d", &x[i] , &y[i]) ;

        for(int i=1; i<=N; i++) fa[i] = i ;
        int n =  0;
        for(int i=1; i<=N; i++)
            for(int j=i+1; j<=N; j++)
                e[n++] = (Edge){i , j ,dist(i , j)} ;
        fa[p] = q ;
        double ans = dist(p ,q) ;

        sort(e ,e+n) ;
        for(int i=0; i<n; i++) {
            int u = Find(e[i].u) ;
            int v = Find(e[i].v) ;
            if(u != v) {
                ans += e[i].d ;
                fa[v] = u ;
            }
        }

        printf("%.2f\n" , ans) ;

    }
    return 0;
}
