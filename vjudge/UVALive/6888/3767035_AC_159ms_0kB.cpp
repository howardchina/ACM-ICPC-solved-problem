#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
using namespace std;

//map<int,int>step ;

int R,N,M,limit ;
int target ;
char g[15][15] ;
int pos[4];

const int dx[] = {0, -1 , 0 , 1} ;
const int dy[] = {1 , 0 , -1 , 0} ;

const int HASH = 100007 ;
const int STATE = 10000000 ;
struct MyMap{
    int head[HASH],key[STATE],value[STATE],next[STATE],sz ;
    void clear() {
        memset(head , -1 ,  sizeof(head)) ;
        sz = 0 ;
    }
    bool count(int s) {
        int p = s%HASH;
        for(int i=head[p]; ~i ; i=next[i]) {
            if(key[i] == s) return true ;
        }
        return false ;
    }
    int & operator [] (int s) {
        int p=s%HASH ;
        for(int i=head[p]; ~i ; i=next[i]) {
            if(key[i] == s) return value[i] ;
        }
        key[sz] = s , next[sz] = head[p] , head[p] = sz ++ ;
        return value[sz-1] ;
    }
}step;

int encode() {
    sort(pos+1, pos+R);
    int ret = 0 ;
    for(int i=0; i<R; i++) {
        ret = ret<<7 | pos[i] ;
    }
    return ret ;
}

void decode(int x) {
    for(int i=R-1; i>=0; i--) {
        pos[i] = x & 127 ;
        x >>= 7 ;
    }
}


void Move(int i , int dir) {
    int x = pos[i] / M , y = pos[i] % M;
    while(1) {
        int nx = x + dx[dir] , ny = y + dy[dir] ;
        if(nx<0 || nx>=N || ny<0 || ny>=M) break;
        if(g[nx][ny] == 'W') break ;
        bool flag = true;
        for(int j=0; j<R; j++) if(i!=j && nx*M+ny == pos[j]) { flag = false ; break ;}
        if(!flag) break ;
        x = nx , y = ny ;
    }
    pos[i] = x * M + y ;
}


int main()
{

    //freopen("in.txt","r",stdin) ;

    while(scanf("%d%d%d%d", &R,&M,&N,&limit) == 4) {

        step.clear() ;

        for(int i=0; i<N; i++) {
            scanf("%s", g[i]) ;
            for(int j=0; j<M; j++) {
                if(g[i][j] == 'X') target = i * M + j ;
                if('1' <= g[i][j] && g[i][j] <= '4') pos[ g[i][j] - '1' ] = i * M + j;
            }
        }

        int begin = encode() ;
        int ans = limit + 1;
        queue<int>Q;
        Q.push(begin) , step[begin] = 0 ;
        while(!Q.empty()) {
            int u = Q.front(); Q.pop() ;
            if((u>>((R-1)*7)) == target) {
                ans = step[u] ;
                break ;
            }
            for(int i=0; i<R; i++) {
                for(int dir =0 ; dir < 4 ; dir++) {
                    decode(u) ;
                    Move(i , dir) ;
                    int v = encode();
                    if(step.count(v) || step[u]>=limit) continue ;
                    Q.push(v) , step[v] = step[u] + 1 ;
                }
            }
        }

        if(ans > limit) puts("NO SOLUTION") ;
        else printf("%d\n" , ans);

    }
    return 0;
}
