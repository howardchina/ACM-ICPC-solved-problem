#include <iostream>
#include <cstdio>
#include <bitset>
#include <cstring>
#include <cmath>

using namespace std;

bitset<2550>bs[1111];
bitset<2550>a[11];
int r[11], c[11], R[11];

int g[50][50];

int main()
{
//    freopen("data.in", "r", stdin);
    int n,m;
    while(1){
        scanf("%d", &n);
        if (!n) break;
        scanf("%d", &m);
        memset(g, 0, sizeof g);
        for(int i = 0; i < m; i++){
            a[i] = 0;
            scanf("%d%d", &r[i], &c[i]);
            r[i]--, c[i]--;
            g[r[i]][c[i]] = 1;
        }
        for(int i = 0; i < m; i++){
            scanf("%d", &R[i]);
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if (g[i][j]) continue;
                int d = i*n+j;
                for(int k = 0; k < m; k++){
                    if ( abs(i-r[k])+abs(j-c[k]) <= R[k]){
                        a[k][d] = 1;
                    }
                }
            }
        }


        int lim = 1<<m;
        int fu = 0;
        int ans = -1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if (!g[i][j]) fu++;
            }
        }
        if (fu == 0) ans = 0;
        else{

            for(int i = 1; i < lim; i++){
                int lb = i&(-i);
                int t = lb;
                int x = -1;
                while(t > 0){
                    t>>=1;
                    x++;
                }
                bs[i] = a[x] | bs[i^lb];
                if ((int)bs[i].count() == fu){
                    int cnt = 0;
                    for(int k = 1; k <= i; k<<=1){
                        if (k&i) cnt++;
                    }
                    if (ans == -1 || cnt < ans){
                        ans = cnt;
                    }
                }
        //            cout<< bs[i].count()<<endl;
            }

        }
        printf("%d\n", ans);
    }

    return 0;
}
