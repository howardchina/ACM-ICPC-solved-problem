#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int a[10] , n  ;
    while(scanf("%d",&n) == 1) {
        int sum = 0 ;
        for(int i=1; i<=n; i++) scanf("%d", &a[i]) , sum += a[i] ;
        sort(a+1, a+1+n) ;

        int ans = 0;
        if(n <= 3) ans = 1024 ;
        else if(n == 4) {
            for(int i=1; i<=n; i++) if((sum - a[i]) % 1024 == 0) {
                ans = 1024 ;
            }
            for(int i=1; i<n; i++)
            for(int j=i+1; j<=n; j++) {
                int tmp = a[i] + a[j];
                while(tmp > 1024) tmp -= 1024 ;
                ans = max(ans , tmp) ;
            }
        }
        else {
            for(int i=1; i<=n; i++)
            for(int j=i+1; j<=n; j++) {
                if((sum - a[i] - a[j]) % 1024 == 0) {
                    int tmp = a[i] + a[j] ;
                    while(tmp > 1024) tmp -= 1024  ;
                    ans = max(ans , tmp) ;
                }
            }
        }

        printf("%d\n" , ans) ;
    }
    return 0;
}
