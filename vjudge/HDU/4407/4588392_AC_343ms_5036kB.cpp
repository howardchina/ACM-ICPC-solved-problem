#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL ;
const int maxn = 400050 ;

bool flag[maxn+10] ;
int pri[maxn/4], pri_cnt , f[maxn+10] ;

void init_pri(){
    flag[0] = flag[1]= true ;
    f[1] = 1 ;
    for(int i=2; i*i <= maxn; i++) if(!flag[i]) {
        for(int j=i*i ; j<=maxn; j+=i) {
            flag[j] = true ;
            if(!f[j]) f[j] = i ;
        }
    }
    for(int i=2; i<=maxn; i++) if(!flag[i]) f[i]= i, pri[pri_cnt++] = i ;
}

int vis[maxn] ,vis_flag , g1[1050] ,g2[1050], gn;

int gcd(int a , int b) {
    return b == 0 ? a : gcd(b , a%b) ;
}

LL cal(int n , int x) {
    int num = n / x;
    LL ret = (LL)(1+num) * num / 2 * x  ;
    return ret ;
}

LL solve(int n, int p) { // 1 ~ n  , co-pri with p
    if(n <= 1) return n ;

    int d[20] , cnt = 0 ;
    int t = p ;
    while(t > 1) {
        if(cnt == 0 || f[t] != d[cnt-1]) d[cnt++] = f[t] ;
        t /= f[t] ;
    }

    LL ret = 0 ;
    for(int s=0; s<(1<<cnt) ; s++) {
        int x = 1 , num = 0 ;
        for(int i=0; i<cnt; i++) if(s & (1<<i)) {
            x *= d[i];
            num ++ ;
        }
        if(num & 1) ret -= cal(n , x) ;
        else        ret += cal(n , x) ;
    }
    return ret  ;
}

int main()
{
//    freopen("data.in", "r", stdin) ;
//    freopen("data.out", "w", stdout) ;

    init_pri() ;

   // for(int i=1; i<maxn; i++) if(f[i] == 0) printf("%d %d\n", i , f[i]) ;

    int T ;
    scanf("%d", &T);
    while(T--) {
        gn = 0 ;
        int n , m  ;
        scanf("%d%d", &n, &m) ;


        for(int i=1; i<=m; i++) {
            int op , x , y , p ;
            scanf("%d%d%d", &op , &x , &y) ;
            if(op == 1) {
                scanf("%d", &p) ;
                vis_flag ++ ;

                LL ans = solve(y , p) - solve(x-1, p) ;
                //cout<<ans << endl ;

                for(int j=gn-1; j>=0; j--) {
                    if(vis[ g1[j] ] == vis_flag) continue ;
                    vis[ g1[j] ] = vis_flag ;

                    if(g1[j] < x || g1[j] > y) continue ;

                    if(gcd(g1[j] , p) == 1) ans -= g1[j] ;
                    if(gcd(g2[j] , p) == 1) ans += g2[j] ;
                }

                printf("%I64d\n" , ans);

            }
            else {
                g1[gn] = x , g2[gn] = y , gn ++  ;
            }
        }
    }

    return 0;
}
