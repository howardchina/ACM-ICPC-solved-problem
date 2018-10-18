#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
const int maxn = 1050 ;
const double INF = 1e18 ;

int N , X[maxn] , Y[maxn], P[maxn];
double D[maxn][maxn];

double cal_dist(int i , int j){
    return sqrt( 1.0 * (X[i] - X[j])*(X[i] - X[j]) + 1.0 * (Y[i] - Y[j]) * (Y[i]-Y[j]) ) ;
}

double d[maxn], maxd[maxn][maxn];
int pre[maxn] ;
bool vis[maxn];
vector<int>g[maxn] ;

int root  ;
void dfs(int u, int fa, double ma) {
    maxd[root][u] = ma ;

    for(size_t i=0; i<g[u].size() ; i++) {
        int v = g[u][i] ;
        if(v == fa) continue ;
        dfs(v , u , fmax(ma , D[u][v])) ;
    }

}


int main()
{
//    freopen("data.in", "r",  stdin) ;

    int T ;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        for(int i=0;i<=N; i++) g[i].clear();

        for(int i=1; i<=N; i++) scanf("%d%d%d", &X[i], &Y[i], &P[i]) ;
        for(int i=1;i<=N; i++)
            for(int j=i; j<=N; j++)
                D[i][j] = D[j][i] = cal_dist(i , j) ;


        memset(vis,0 ,sizeof(vis))  ;
        d[1] = 0 , pre[1] = 0, vis[1] = true ;
        for(int i=2; i<=N; i++) d[i] = D[1][i] , pre[i] = 1 ;

        double sum = 0;
        for(int rep=2; rep<=N; rep++) {
            int u = 0 ;
            double mi = INF ;
            for(int i=1; i<=N; i++) {
                if(vis[i]) continue ;
                if(d[i] < mi) {
                    mi = d[i] ;
                    u = i ;
                }
            }
            sum += mi ;
            g[u].push_back(pre[u]) ;
            g[pre[u]].push_back(u) ;
            vis[u] = true ;

            for(int v=1; v<=N; v++) {
                if(vis[v]) continue ;
                if(d[v] > D[u][v]) {
                    d[v] = D[u][v] ;
                    pre[v] = u ;
                }
            }

        }

        for(root = 1; root<=N ; root++) {
            dfs(root , -1 , 0) ;
        }


        double ans = 0 ;
        for(int i=1; i<=N; i++) {
            for(int j=i+1; j<=N; j++) {
                ans = fmax(ans , 1.0 * (P[i]+P[j]) / ( sum - maxd[i][j] )  ) ;
            }
        }

        printf("%.2f\n" , ans) ;




    }
    return 0;
}
