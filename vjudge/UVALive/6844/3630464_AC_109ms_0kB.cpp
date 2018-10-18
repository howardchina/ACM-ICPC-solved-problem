#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef unsigned long long LL ;

LL C[100][100] ;
int dig[50], n ;

LL dfs(LL d , LL ones , bool equ) {
    LL ret = 0 ;
    if(!equ) {
        LL tmp = 1 ;
        for(LL i=0; i<=d+1; i++) ret += (tmp<<(ones+i)) * C[d+1][i] ;
        return ret ;
    }
    if(d == 0) {
        LL tmp = 1;
        ret += (tmp << (ones)) * C[1][0] ;
        if(dig[0] == 1) {
            ret += (tmp << (ones+1)) * C[1][1] ;
        }
        return ret ;
    }
    for(int x=0; x<=dig[d]; x++) {
        ret += dfs(d-1 , ones+x , equ && x==dig[d]) ;
    }
    return ret ;
}

LL solve(LL val) {
    if(val == 0) return 1 ;
    if(val < 0) return 0 ;
    n = 0 ;
    while(val) dig[n++] = val&1 , val >>= 1 ;
    dig[n] = 0 ;
    return dfs(n , 0 , true) ;
}

int main()
{
    for(int i=0; i<100; i++) C[i][0] = 1 ;
    for(int i=1; i<100; i++) {
        for(int j=1; j<=i; j++) {
            C[i][j] = C[i-1][j-1] + C[i-1][j] ;
        }
    }

    LL L , R ;
    while(scanf("%llu%llu", &L, &R) ==2 && L+R) {
      //  cout<<L << " " <<R<<endl ;
        LL ans = solve(R) ;
        if(L > 0) ans -= solve(L-1) ;
        printf("%llu\n" , ans) ;
    }

    return 0;
}
