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

        double sum1 = 0 , sum2 = 0 ;
        for(int i=2; i<=N; i++) {
            sum1 += h[1][i] ;
            sum2 += dis[1][i] ;
        }

        double NK = sum1 / sum2 , K =0 ;
        do{
            K = NK ;
            dis[0][1] = 0  ;
            h[0][1] = 0 ;

            vis[1] = true ;
            for(int i=2; i<=N; i++) {
                dis[0][i] = dis[1][i] ;
                h[0][i] = h[1][i] ;
                vis[i] = false ;
            }
            sum1 = sum2 = 0 ;
            for(int i=1; i<N; i++) {
                int p =  1 ;
                double min_d = INF ;
                for(int j=2; j<=N; j++) {
                    if(!vis[j] && h[0][j]-dis[0][j]*K < min_d) {
                        min_d = h[0][j]-dis[0][j]*K ;
                        p = j ;
                    }
                }

                sum1 += h[0][p];
                sum2 += dis[0][p];
                vis[p] = true ;

                for(int j=2; j<=N; j++) {
                    if(vis[j]) continue ;
                    if(h[0][j]-dis[0][j]*K > h[p][j]-dis[p][j]*K) {
                        h[0][j] = h[p][j] ;
                        dis[0][j] = dis[p][j];
                    }
                }
            }
            NK = sum1 / sum2 ;
        }while(fabs(NK - K) > 1e-4) ;

        printf("%.3f\n" , K) ;

    }
    return 0;
}
