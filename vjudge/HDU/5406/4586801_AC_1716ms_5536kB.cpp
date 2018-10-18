#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1005 ;

int N;
int a[maxn] ,san[maxn] ,val[maxn], sn ;
struct Node{
    int h , d ;
    bool operator < (const Node & rhs) const  {
        return h > rhs.h || ( h == rhs.h && d < rhs.d) ;
    }
}p[maxn];
struct BIT{
    int f[maxn] ;
    void init() {
        memset(f, 0,  (N+1) * sizeof(f[0])) ;
    }
    void update(int x, int v) {
        if(x == 0) f[0] = max(f[0] ,  v) , x ++ ;
        for(; x<=N; x+=lowbit(x)) f[x] = max(f[x] , v) ;
    }
    int query(int x) {
        int ret = 0 ;
        for(;x>0; x-=lowbit(x)) ret = max( ret , f[x]) ;
        ret = max(ret , f[0]);
        return ret ;
    }
    int lowbit(int x) {
        return x & -x ;
    }
}X[maxn];

int main()
{
//    freopen("data.in", "r" , stdin) ;

    int T ;
    scanf("%d", &T) ;
    while(T--) {
        scanf("%d", &N) ;
        for(int i=0; i<=N; i++) X[i].init() ;
        for(int i=1; i<=N; i++) scanf("%d%d", &p[i].h , &p[i].d) ;
        sort(p+1, p+1+N) ;
        sn = 0  ;
        for(int i=1; i<=N; i++) {
            san[sn++] = a[i] = p[i].d ;
        }
        sort(san, san+sn) ;
        sn = unique(san , san+sn) - san ;
        for(int i=1; i<=N; i++) a[i] = lower_bound(san, san+sn , a[i]) - san + 1 ;

        int ans = 0 ;
        for(int i=1; i<=N; i++) {
            for(int j=0; j<i; j++) val[j] = X[j].query(a[i]) + 1 ;
            for(int j=0; j<i; j++) {
                ans = max(ans,  val[j]) ;
                X[j].update(a[i] , val[j]) ;
                X[i].update(a[j] , val[j]) ;
            }
        }
        printf("%d\n" , ans) ;
    }
    return 0;
}
