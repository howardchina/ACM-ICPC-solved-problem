#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 200 ;
int cnt[maxn] , Max[maxn] ;

int main()
{ 

    int cas = 1 ;
    int S , T, M ;
    while(scanf("%d%d%d", &S, &T, &M) == 3 && S+T+M) {
        memset(cnt, 0, sizeof(cnt)) ;
        memset(Max, 0, sizeof(Max)) ;

        for(int i=1; i<=S; i++) {
            int id , b, c ;
            scanf("%d%d%d", &id, &b, &c) ;
            cnt[id] += b + c ;
        }
        for(int i=1; i<=T; i++) {
            int id , x ;
            scanf("%d%d", &id, &x) ;
            if(x >= M) Max[id] = 1 ;
        }
        int ans = 0 ;
        for(int i=1; i<=S; i++) ans += min(cnt[i] + Max[i] , 3) ;
        printf("Case %d: %d\n" , cas++ , ans) ;
    }
    return 0;
}
