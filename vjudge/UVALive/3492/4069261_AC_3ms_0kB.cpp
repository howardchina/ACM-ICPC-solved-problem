#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF= 0x3f3f3f3f ;
const int maxn = 3000 ;

const int dx[] = {0 , -1 , 0 , 1} ;
const int dy[] = {1, 0 , -1, 0} ;

int px[maxn] , py[maxn] , pn ;
int dp[maxn][4] ;


int Move(int u , int du , int v , int dv) {
    int x1 = px[u] + dx[(du+2)%4] ;
    int y1 = py[u] + dy[(du+2)%4] ;
    int x2 = px[v] + dx[(dv+2)%4] ;
    int y2 = py[v] + dy[(dv+2)%4] ;
    return (x1!=x2) + (y1 != y2) ;
}

int main()
{
//    freopen("in.txt", "r", stdin) ;

    int T, cas = 1 ;
    scanf("%d", &T) ;
    while(T--) {
        pn = 0;

        int step ;
        scanf("%d", &step) ;
        int dir = 0 , tx =  0 , ty = 0 ;
        while(step--) {
            char oper[20] ;
            scanf("%s", oper) ;
            if(oper[0] == 'F') {
                tx += dx[dir];
                ty += dy[dir];
            }
            else if(oper[0] == 'T') {
                scanf("%s", oper) ;
                if(oper[0] == 'L') {
                    dir = (dir + 1) % 4 ;
                }
                else if(oper[0] == 'R'){
                    dir = (dir + 3) % 4 ;
                }
            }
            else if(oper[0] == 'S') {
                pn ++ ;
                px[pn] = tx + dx[dir] ;
                py[pn] = ty + dy[dir] ;
            }
        }

        px[0] = 0 , py[0] = 1 ;
        memset(dp , 0x3f , sizeof(dp)) ;
        dp[0][0] = 0 ;

        for(int i=1; i<=pn; i++) {
            for(int p=0; p<4; p++){
                for(int q=0; q<4; q++){
                    dp[i][q] = min(dp[i][q] , dp[i-1][p] + Move(i-1,p , i , q)+1) ;
                }
            }
        }

        int ans = INF;
        for(int i=0; i<4; i++)
            ans = min(ans , dp[pn][i]) ;

        if(cas>1) printf("\n");
        printf("Case %d:\n", cas++) ;
        printf("%d\n" , ans) ;

    }
    return 0;
}
