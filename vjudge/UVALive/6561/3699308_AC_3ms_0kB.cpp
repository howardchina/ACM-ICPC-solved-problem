#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL ;

LL N ,M ;
LL cnt[100];

void init() {

    cnt[0] = cnt[1] = 1;
    for(int i=2; i<100; i++) {
        cnt[i] = cnt[i-1] + 2 * cnt[i-2] ;
    }
}

//LL cal(int n , int pre , int finish) {
//    if(n == 0) {
//        if(finish) return 1 ;
//        else return 0 ;
//    }
//
//}

void solve(LL x){
    int n = 1 ;
    while(cnt[n] < x) {
        x -= cnt[n] ;
        n ++ ;
    }

    while(n) {
        if(n == 1) {
            if(x == 1) printf("a");
            else printf("b");
            n = 0 ;
            break ;
        }
        if((1LL << (n-1)) >= x) {
            printf("a");
            for(int i=n-1; i>=1; i--) {
                if((1LL << (i-1)) >= x) {
                    printf("a") ;
                }
                else {
                    x -= (1LL << (i-1)) ;
                    printf("b");
                }
            }
            break ;
        }
        else {
            x -= (1LL << (n-1)) ;
            printf("bb") ;
            n -= 2 ;
        }
    }

}

int main()
{

   // freopen("in.txt","r", stdin);
    init() ;


    int cas = 1 ;
    while(cin>>N>>M && N+M) {
        LL s = N*(M-1)+1 , t = N*M ;
        printf("Case %d: ", cas++) ;
        solve(s) ;
        printf(" ");
        solve(t) ;
        printf("\n") ;
    }
    return 0;
}
