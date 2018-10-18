#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const  int INF = 0x3f3f3f3f ;

int sum[22][22], dp[22][22][22][22] , N ,M ;
int getsum(int x1 ,int y1, int x2 , int y2) {
    return sum[x2][y2] - sum[x2][y1-1] - sum[x1-1][y2] + sum[x1-1][y1-1] ;
}
int DP(int x1 , int y1, int x2 ,int y2) {
    int &ret = dp[x1][y1][x2][y2] ;
    if(ret != -1) return ret ;
    if(getsum(x1,y1,x2,y2) == 1) return ret = 0  ;
    if(getsum(x1,y1,x2,y2) == 0) return ret = INF  ;
    int ans = INF ;
    for(int x=x1; x<x2; x++) ans = min(ans , DP(x1,y1,x,y2) + DP(x+1,y1,x2,y2) + y2-y1+1) ;
    for(int y=y1; y<y2; y++) ans = min(ans , DP(x1,y1,x2,y) + DP(x1,y+1,x2,y2) + x2-x1+1) ;
    return ret = ans ;
}

int main()
{
//    freopen("data.in","r",stdin);

    int R , cas = 1 ;
    while(scanf("%d%d%d", &N, &M, &R) != EOF) {
        memset(sum,0,sizeof(sum)) ;
        for(int i=1; i<=R; i++) {
            int x , y;
            scanf("%d%d", &x, &y);
            sum[x][y] = 1;
        }
        for(int x=1; x<=N; x++)
            for(int y=1; y<=M; y++)
                sum[x][y] += sum[x][y-1] + sum[x-1][y] - sum[x-1][y-1] ;


        memset(dp, -1, sizeof(dp)) ;
        printf("Case %d: %d\n" , cas++ , DP(1,1,N,M)) ;
    }
    return 0;
}
