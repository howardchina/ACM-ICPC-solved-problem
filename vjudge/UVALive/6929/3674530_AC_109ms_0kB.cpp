#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL ;

int main()
{
    int T ;
    scanf("%d", &T) ;
    while(T--) {
        LL N ;
        scanf("%I64d", &N) ;
        bool flag = false ;
        LL a , num ;
        for(LL n = 2; n*n - n <= 2 * N; n++) {
            a = (2*N - (n*n - n)) / 2 / n ;
            if(2*a*n + n*n - n == 2*N) {
                flag = true ;
                num = n ;
                break ;
            }
        }
        if(flag && a>0) {
            printf("%d = ", N) ;
            printf("%d", a) ;
            for(int i=2; i<=num; i++){
                printf(" + %d", a + i - 1) ;
            }
            printf("\n");
        }
        else {
            puts("IMPOSSIBLE");
        }
    }
    return 0;
}
