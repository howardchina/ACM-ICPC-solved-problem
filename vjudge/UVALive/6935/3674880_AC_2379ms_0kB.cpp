#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL ;
const int maxn = 100050 ;


int N ;
int len[maxn];
char s[maxn][2] ;

int main()
{
   // freopen("in.txt","r", stdin);

    int T;
    scanf("%d", &T) ;
    while(T--) {
        scanf("%d", &N) ;
        LL B =  0 , W = 0 ;
        int ans = 0 ;

        for(int i=1;i<=N; i++) {
            scanf("%d%s", &len[i] , s[i]) ;
            if(s[i][0] == 'B') B += len[i] ;
            else W += len[i] ;
        }

        if(B == 0 || W == 0) {
            ans = B + W  ;
            printf("%d\n" , ans) ;
            continue ;
        }

        LL b = 0 , w = 0 ;
        for(int i=1; i<=N ;i++) {
            bool flag = false ;
            if(s[i][0] == 'B' && B*w % W == 0) {
                LL x = B * w / W - b ;
                if(0 <= x && x<=len[i] && w>0 && b+x>0) {
                    ans ++ ;
                    w = 0 ;
                    b = len[i] - x  ;
                    flag = true ;
                }
            }
            else if(s[i][0] == 'W' && b*W % B == 0){
                LL x = b * W / B - w ;
                if(0<=x && x<=len[i] && w+x>0 && b>0){
                    ans ++ ;
                    b = 0 ;
                    w = len[i] - x ;
                    flag = true ;
                }
            }

            if(!flag) {
                if(s[i][0] == 'W') w += len[i] ;
                else b += len[i] ;
            }
        }

        printf("%d\n" , ans) ;

    }
    return 0;
}
