#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 1010;

int xx[maxn], yy[maxn];
int ax[maxn][maxn], ay[maxn][maxn];
double fx[maxn], fy[maxn], gx[maxn], gy[maxn];

int main()
{
//    freopen("data.in", "r", stdin);
    int T, cas = 1; scanf("%d", &T);
    while(T--){
        int k, m, n;
        scanf("%d%d%d", &k, &m, &n);
        for(int i = 1; i <= k; i++){
            scanf("%d%d", &xx[i], &yy[i]);
        }
        memset(ax, 0, sizeof ax);
        memset(ay, 0, sizeof ay);
        for(int i = 1; i <= m; i++){
            int w, u, v;
            scanf("%d%d%d", &w, &u, &v);
            if (u < 0){
                ax[v][v] += w;
                ax[v][n+1] += w * xx[-u];

                ay[v][v] += w;
                ay[v][n+1] += w * yy[-u];
            }else if(v < 0){
                ax[u][u] += w;
                ax[u][n+1] += w * xx[-v];

                ay[u][u] += w;
                ay[u][n+1] += w * yy[-v];
            }else{
                ax[u][u] += w;
                ax[u][v] -= w;

                ax[v][v] += w;
                ax[v][u] -= w;

                ay[u][u] += w;
                ay[u][v] -= w;

                ay[v][v] += w;
                ay[v][u] -= w;
            }
        }

        memset(fx, 0, sizeof fx);
        memset(fy, 0, sizeof fy);
        memset(gx, 0, sizeof gx);
        memset(gy, 0, sizeof gy);
        double p = 1.0;
        while(p > 0.00001){
            p = 0;
            for(int i = 1; i <= n; i++){
                double sumx = 0, sumy = 0;
                for(int j = 1; j <= n; j++){
                    if (i == j) continue;
                    sumx += ax[i][j] * fx[j];
                    sumy += ay[i][j] * fy[j];
                }
                gx[i] = (ax[i][n+1] - sumx)/ax[i][i];
                gy[i] = (ay[i][n+1] - sumy)/ay[i][i];
            }
            for(int i = 1; i <= n; i++){
                p = max(p, gx[i] - fx[i]);
                p = max(p, gy[i] - fy[i]);
                fx[i] = gx[i];
                fy[i] = gy[i];
            }
        }
        printf("Test case number : %d\n", cas++);
        for(int i = 1; i <= n; i++){
            printf("%d %.2f %.2f\n", i, gx[i], gy[i]);
        }
    }
    return 0;
}
