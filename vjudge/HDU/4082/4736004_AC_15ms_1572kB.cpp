#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

const int maxn = 1000;

const double eps = 1e-12;

struct Tri{
    int x[3];

    bool validate(){
        if (sqrt(x[0]) + sqrt(x[1]) <= sqrt(x[2])+eps) return 0;
        if (sqrt(x[0]) + sqrt(x[2]) <= sqrt(x[1])+eps) return 0;
        if (sqrt(x[1]) + sqrt(x[2]) <= sqrt(x[0])+eps) return 0;
        return 1;
    }

    bool operator<(const Tri& rhs)const{
        for(int i = 0; i < 3; i++) {
            if (x[i] != rhs.x[i]) return x[i] < rhs.x[i];
        }
        return 0;
    }
}t[maxn];

pair<int,int> p[22];
#define mp make_pair
int x[22], y[22];

int d[3][2] = {{0,1},{0,2},{1,2}};

int main()
{
//    freopen("data.in", "r", stdin);
    int n, m;

    while(1){
        scanf("%d", &n);
        if (!n) break;
        for(int i = 0; i < n; i++){
            scanf("%d%d", &x[i], &y[i]);
            p[i] = mp(x[i], y[i]);
        }
        sort(p, p+n);
        n = unique(p, p+n) - p;
        for(int i = 0; i < n; i++){
            x[i] = p[i].first;
            y[i] = p[i].second;
        }
        m = 0;
        for(int i = 2; i < n; i++){
            for(int j = 1; j < i; j++){
                for(int k = 0; k < j; k++){
                    int e[] = {i, j, k};
                    for(int l = 0; l < 3; l++){
                        int ex = x[e[d[l][0]]] - x[e[d[l][1]]];
                        int ey = y[e[d[l][0]]] - y[e[d[l][1]]];
                        t[m].x[l] = ex*ex + ey*ey;
                    }
                    int tmp = __gcd(__gcd(t[m].x[0], t[m].x[1]), t[m].x[2]);
                    for(int k = 0; k < 3; k++){
                        t[m].x[k] /= tmp;
                    }
                    sort(t[m].x, t[m].x+3);
                    m++;
                }
            }
        }
        sort(t, t+m);
        int ans = 0;
        for(int i = 0, j = 0; i < m; i=j){
            j = i+1;
            if (!t[i].validate()){
                continue;
            }
            while(!(t[i] < t[j]) && !(t[j] < t[i]) && j < m){
                j++;
            }
            ans = max(ans, j-i);
        }
        printf("%d\n", ans);
    }
    return 0;
}
