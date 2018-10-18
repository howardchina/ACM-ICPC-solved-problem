#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 30005 ;

char flag[120000000] ;
int ans[maxn] ;

int main()
{
    ans[0] = 1 ;
    flag[0] = true ;

    int limit = 30000 ;

    for(int n=1; n<=limit; n++) {
        int sum = 0 ;
        for(int i=0; i<=n; i++) {
            int x=i*n ;
            int u=x>>3;
            int v = x & 7 ;
            if( (flag[u] & (1<<v)) == 0 ) {
                sum ++ ;
                flag[u] |= 1<<v ;
            }
        }
        ans[n] = ans[n-1] + sum ;
    }

    int T,n;
    scanf("%d", &T) ;
    while(T--) {
        scanf("%d", &n) ;
        printf("%d\n" , ans[n]) ;
    }


    return 0;
}
