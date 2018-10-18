#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL ;
const int maxn= 100050;
char s[maxn], t[maxn] ;


int main()
{
    int T ;
    scanf("%d", &T) ;
    while(T--){
        scanf("%s%s", s + 1, t + 1);
        int L1 = strlen(s+1) ;
        int L2 = strlen(t+1) ;
        bool flag = true ;

        int now = 1 ;

        int h = 1 ;
        while(h < L2 && t[h] == t[h+1]) h ++ ;

        int i=1;
        for(; i<=h; i++) {
            if(s[now] == t[i]) {
                now ++ ;
            }
            else {
                flag = false ;
                goto NEXT ;
            }
        }


        for(; i<=L2; i++) {
            if(s[now] == t[i]) {
                now ++ ;
                if(now > L1) goto NEXT ;
            }
        }

        if(now <= L1) flag = false  ;


        NEXT :
        if(flag)printf("Yes\n") ;
        else printf("No\n") ;
    }
    return 0;
}
