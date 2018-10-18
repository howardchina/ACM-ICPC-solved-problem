#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 10050 ;

int d[maxn] , c[maxn] ;
int D[maxn], C[maxn] ;

int main()
{
    int N ;
    while(scanf("%d", &N) == 1 && N) {
        memset(D, 0x3f, sizeof(D)) ;
        memset(C, 0x3f , sizeof(C)) ;

        for(int i=1; i<=N; i++) {
            scanf("%d%d", &d[i], &c[i]) ;
            D[d[i]] = min(D[d[i]] , c[i]) ;
            C[c[i]] = min(C[c[i]] , d[i]) ;
        }
        for(int i=2; i<=10000; i++) {
            D[i] = min(D[i] , D[i-1]) ;
            C[i] = min(C[i] , C[i-1]) ;
        }
        int ans = 0 ;
        for(int i=1; i<=N; i++) {
            if(D[d[i]-1] <= c[i]) continue;
            if(C[c[i]-1] <= d[i]) continue;
            ans ++ ;
        }
        printf("%d\n" , ans) ;

    }
    return 0;
}
