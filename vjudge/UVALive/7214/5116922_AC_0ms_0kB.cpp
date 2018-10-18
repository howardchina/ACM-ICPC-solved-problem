#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a[10], b[10] , c[10] , n ;
bool check() {
    n = 0;
    int tmp = a[1] ;
    for(int i=2; i<=4; i++) {
        if(b[i-1] == 2) {
            c[n++] = tmp ;
            tmp = a[i] ;
        }
        else if(b[i-1] == 0) {
            tmp += a[i] ;
        }
        else if(b[i-1] == 1) {
            tmp -= a[i] ;
        }
    }
    c[n++] = tmp ;
    if(n < 2) return false ;
    for(int i=1; i<n; i++)
        if(c[i] != c[i-1]) return false ;
    return true ;
}

char f(int x){
    if(x==0) return '+' ;
    if(x==1) return '-' ;
    if(x==2) return '=' ;
    return '!';
}

int main()
{
    int T , cas = 1 ;
    scanf("%d" , &T) ;
    while(T--) {
        for(int i=1; i<=4; i++) scanf("%d", &a[i]) ;

        bool flag = true ;
        for(int i=0; i<3 && flag; i++)
            for(int j=0; j<3 && flag; j++)
                for(int k=0; k<3 && flag ; k++) {
                    b[1] = i;
                    b[2] = j;
                    b[3] = k;
                    if(check()) flag = false ;
                }

        printf("Case #%d: %d %c %d %c %d %c %d\n", cas++ , a[1] , f(b[1]) ,  a[2] , f(b[2]) , a[3] , f(b[3]) , a[4]) ;

    }
    return 0;
}
