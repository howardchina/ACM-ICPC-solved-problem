#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const double INF = 1e10 ;
const int maxn = 1050;

int N ;
double X[maxn] , Y[maxn], Z[maxn] ;
double dis[maxn][maxn] , h[maxn][maxn];
bool vis[maxn] ;

double get_dist(int i ,int j) {
    return sqrt((X[i] - X[j])*(X[i] - X[j]) + (Y[i] - Y[j])*(Y[i]-Y[j])) ;
}
double get_height(int i ,int j) {
    return fabs(Z[i] - Z[j]) ;
}

double Prim(double K) {
    double ret = 0 , *d = dis[0] ;
    d[0] = 0 ;
    vis[1] = true ;

    vis[1] = true ;
    for(int i=2; i<=N; i++) {
        d[i] = h[1][i] - dis[1][i] * K ;
        vis[i] = false ;
    }
    for(int i=1; i<N; i++) {
        int p =  1 ;
        double min_d = INF ;
        for(int j=2; j<=N; j++) {
            if(!vis[j] && d[j] < min_d) {
                min_d = d[j] ;
                p = j ;
            }
        }

        if(p == 1) break ;
        ret += min_d ;
        vis[p] = true ;

        for(int j=2; j<=N; j++) {
            if(vis[j]) continue ;
            if(d[j] > h[p][j]-dis[p][j]*K) {
                d[j] = h[p][j] - dis[p][j] * K ;
            }
        }
    }
    return ret ;
}

int main()
{

    while(scanf("%d", &N) == 1 && N) {
        for(int i=1; i<=N; i++) {
            scanf("%lf%lf%lf", &X[i], &Y[i], &Z[i]) ;
        }
        for(int i=1; i<=N; i++) {
            for(int j=i+1; j<=N; j++) {
                dis[i][j] = dis[j][i] = get_dist(i , j) ;
                h[i][j] = h[j][i] = get_height(i, j) ;
            }
        }

        double L = 0 , R = 1e7 ;
        while(R-L > 1e-4) {
            double mid = (L+R)/2 ;
            if(Prim(mid) > 0.0) L = mid ;
            else R = mid ;
        }

        printf("%.3f\n" , L) ;

    }
    return 0;
}
