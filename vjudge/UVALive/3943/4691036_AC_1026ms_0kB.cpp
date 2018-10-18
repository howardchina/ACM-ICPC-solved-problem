#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
const int maxn = 200050 ;
typedef unsigned long long uLL ;

char s[maxn] ;
int N ;
uLL xp[maxn] , h[maxn] , P = 997123 ;
uLL hs(int l, int r) {
    return h[r] - h[l-1] * xp[r-l+1] ;
}

struct SET{
    uLL f[1<<21] ;
    bool use[1<<21] ;
    int M ;
    void init(int n) {
        M = 1 ;
        while(M/2 < n) M *= 2;
        memset(use , false, M*sizeof(use[0])) ;
    }
    void insert(uLL x) {
        int p = x & (M-1) ;
        while(use[p] && f[p]!=x) p = (p+1) & (M-1) ;
        f[p] = x , use[p] = true ;
    }
    bool count(uLL x) {
        int p = x & (M-1) ;
        while(use[p] && f[p]!=x) p = (p+1) & (M-1) ;
        return use[p] && f[p] == x ;
    }
}S;

bool check(int l) {
    //set<uLL>S;
    S.init(N) ;
    for(int i=1; i+l-1<=N; i++) {
        uLL tmp = hs(i , i+l-1) ;
        if(S.count(tmp)) return true ;
        S.insert(tmp) ;
    }
    return false ;
}

int main()
{
    xp[0] = 1;
    for(int i=1; i<maxn; i++) xp[i] = xp[i-1] * P ;

    int cas = 1;
    while(scanf("%d", &N) == 1) {
        scanf("%s", s+1) ;
        h[0] = 0 ;
        for(int i=1; i<=N; i++) h[i] = h[i-1] * P + s[i] ;

        int L = 0, R = N-1;
        while(L < R) {
            int mid = L + (R-L+1)/2;
            if(check(mid)) L = mid ;
            else   R = mid -1 ;
        }
        printf("Case %d: %d\n", cas++ , L) ;
    }

    return 0;
}
