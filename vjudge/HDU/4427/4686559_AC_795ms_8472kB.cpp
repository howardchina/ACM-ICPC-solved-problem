#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL ;
const int maxn = 1050 ;
const LL MOD = 1e9 + 7 ;

bool flag[maxn+1] ;
int pri[maxn], pn ;

void init() {
    for(int i=2; i*i < maxn; i++) if(!flag[i]) {
        for(int j=i*i; j<maxn; j+=j) flag[j] = true ;
    }
    for(int i=2; i<maxn; i++) if(!flag[i]) pri[pn++] = i ;
}

int p[10], w[10], n ;
int a[maxn],s[maxn], cnt  ;

void dfs(int d , int val , int sta) {
    if(d == n) {
        a[cnt] = val ;
        s[cnt] = sta ;
        cnt ++ ;
        return ;
    }
    int tmp = 1 ;
    for(int i=0; i<=w[d]; i++) {
        dfs(d+1, val*tmp , sta | ( i==w[d] ? (1<<d) : 0 ) ) ;
        tmp *= p[d] ;
    }
}

void devide(int x) {
    n = 0 ;
    for(int i=0; pri[i]*pri[i] <= x; i++) {
        if(x % pri[i] == 0) {
            p[n] = pri[i] ;
            w[n] = 0 ;
            while(x % pri[i] == 0) x /= pri[i] , w[n] ++ ;
            n ++ ;
        }
    }
    if(x > 1) {
        p[n] = x ;
        w[n] = 1;
        n ++ ;
    }

    cnt = 0 ;
    dfs(0 , 1 , 0) ;
}

int dp[105][maxn][16] ;



int main()
{
    init() ;
    int N , M , K ;
    while(scanf("%d%d%d", &N, &M, &K) == 3) {
        devide(M) ;
        memset(dp, 0, sizeof(dp)) ;
        dp[0][0][0] = 1;
        for(int i=0; i<K; i++) {
            for(int x=0; x<=N; x++) {
                for(int u=(1<<n)-1; u>=0; u--) {
                    for(int j=0; j<cnt; j++) {
                        if(x + a[j] <= N) {
                            int &ans = dp[i+1][x+a[j]][u|s[j]] ;
                            ans += dp[i][x][u] ;
                            if(ans >= MOD) ans -= MOD ;
                        }
                    }
                }
            }
        }

        printf("%d\n" , dp[K][N][(1<<n)-1]) ;
    }

    return 0;
}
