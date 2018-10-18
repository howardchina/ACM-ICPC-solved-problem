#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 10050 ;

int a[maxn] ;

int main()
{
    int T ;
    scanf("%d", &T) ;
    while(T--) {
        int N ;
        scanf("%d" , &N) ;
        for(int i=1; i<=N; i++) scanf("%d", &a[i]) ;
        sort(a+1, a+1+N) ;

        int ans = 0 ;
        for(int i=1; i+2 <= N; i+=2) ans = max(ans, abs(a[i] - a[i+2])) ;
        for(int i=2; i+2 <= N; i+=2) ans = max(ans, abs(a[i] - a[i+2])) ;
        ans = max(ans, abs(a[1] - a[2])) ;
        ans = max(ans, abs(a[N-1] - a[N])) ;

        printf("%d\n" , ans) ;
    }
    return 0;
}
