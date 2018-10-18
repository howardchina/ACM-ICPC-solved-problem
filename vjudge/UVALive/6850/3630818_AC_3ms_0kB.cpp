#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int dx[] = {0 , -1 , 0 , 1} ;
const int dy[] = {1 , 0 , -1 , 0} ;

int g[50][50] , cnt[50][50] , N ,M , SUM, sum, plus_cnt , lastx , lasty ;
bool center[50][50] ;

bool ingrid(int x ,int y) {
    if(x<1 || x>N || y<1 || y>M) return false ;
    return true ;
}

bool check(int x ,int y, int len) {
    if(center[x][y] || cnt[x][y]+1 > g[x][y]) return false ;
    for(int dir=0; dir<4; dir++) {
        int u = x , v = y;
        for(int l=1; l<=len; l++) {
            u = u + dx[dir];
            v = v + dy[dir] ;
            if(center[u][v] || cnt[u][v] + 1 > g[u][v]) return false ;
        }
    }
    return true ;
}

void Put(int x ,int y , int len) {
    plus_cnt ++ ;
    center[x][y] = true ;
    cnt[x][y] ++ , sum ++ ;
    for(int dir=0; dir<4; dir++) {
        int u = x , v = y;
        for(int l=1; l<=len; l++) {
            u = u + dx[dir];
            v = v + dy[dir] ;
            cnt[u][v]++ , sum ++ ;
        }
    }
}
void Remove(int x , int y , int len) {
    plus_cnt -- ;
    center[x][y] = false ;
    cnt[x][y] -- , sum -- ;
    for(int dir=0; dir<4; dir++) {
        int u = x , v = y;
        for(int l=1; l<=len; l++) {
            u = u + dx[dir];
            v = v + dy[dir] ;
            cnt[u][v]-- , sum -- ;
        }
    }
}

bool dfs(int x , int y) {
    if(x > N) return false ;
    int nextx , nexty ;
    int len = 0 , u = x , v = y ;
    if(y == M) nextx = x + 1 , nexty = 1 ;
    else nextx = x , nexty = y + 1 ;

    for(;;) {
        u = u + dx[1] ;
        v = v + dy[1] ;
        if(g[u][v] - cnt[u][v] > 1) return false ;
        if(g[u][v] - cnt[u][v] != 1 || u<1) break ;
        len ++ ;
    }
    if(len>5) return false ;
    for(int nx=1; nx<x-len; nx++) {
        if(g[nx][y] - cnt[nx][y] > 0) return false ;
    }

    if(len>0 && len<=5 && check(x, y, len)) {
        Put(x, y , len) ;
        if(sum == SUM) {
            lastx = x ;
            lasty = y ;
            return true ;
        }
        if(dfs(nextx , nexty)) return true ;
        Remove(x , y, len) ;
    }

    if(dfs(nextx , nexty)) return true ;
    return false ;
}


int main()
{
    //freopen("in.txt", "r", stdin);

    int T ;
    scanf("%d", &T) ;
    while(T--) {
        scanf("%d%d", &N, &M) ;
        memset(cnt , 0 ,sizeof(cnt)) ;
        memset(center, 0, sizeof(center)) ;
        SUM = 0 ;
        for(int i=1; i<=N; i++) {
            for(int j=1; j<=M; j++) {
                scanf("%d", &g[i][j]) ;
                SUM += g[i][j] ;
            }
        }
        plus_cnt = 0 , sum = 0 ;

        dfs(1 , 1) ;
        printf("%d\n" , plus_cnt) ;
        printf("%d %d\n" , lastx , lasty) ;
    }
    return 0;
}
