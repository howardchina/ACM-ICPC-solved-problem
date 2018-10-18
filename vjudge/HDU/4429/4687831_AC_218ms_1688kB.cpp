#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 2050 ;
int son[maxn][2] ,sz[maxn], N , Q ;

struct Mat{
    int x1 ,y1 , x2 , y2 ;
    int read() {
        return scanf("%d%d%d%d", &x1 ,&y1, &x2 ,&y2) == 4 ;
    }
}M[maxn];
int mat_cnt ;

struct Line{
    int x1, y1 , x2 , y2 ;
    void read() {
        scanf("%d%d%d%d", &x1 ,&y1, &x2 ,&y2) ;
        if(x1 == x2 && y1 > y2) swap(y1 , y2) ;
        if(y1 == y2 && x1 > x2) swap(x1 , x2) ;
    }
};

bool point_in_mat(Mat m , int x, int y) {
    return m.x1 < x && x < m.x2 && m.y1 < y && y < m.y2 ;
}
int line_on_mat(Line l , Mat m) {
    /*
        0 : 不在矩形上
        1 ：水平切割
        2 ：垂直切割
    */
    if(l.y1 == l.y2){
        if(l.x1 == m.x1 && l.x2 == m.x2 && m.y1 < l.y1 && l.y2 < m.y2) return 1 ;
    }
    if(l.x1 == l.x2) {
        if(l.y1 == m.y1 && l.y2 == m.y2 && m.x1 < l.x1 && l.x1 < m.x2) return 2 ;
    }
    return 0 ;
}

void cut(Mat m , Line l) {
    Mat & m1 = M[++mat_cnt] ;
    m1.x1 = m.x1 , m1.y1 = m.y1 ;
    m1.x2 = l.x2 , m1.y2 = l.y2 ;
    son[mat_cnt][0] = son[mat_cnt][1] =  0;

    Mat &m2 = M[++mat_cnt] ;
    m2.x1 = l.x1 , m2.y1 = l.y1 ;
    m2.x2 = m.x2 , m2.y2 = m.y2 ;
    son[mat_cnt][0] = son[mat_cnt][1] =  0;
}

void build() {
    son[1][0] = son[1][1] = 0 ;
    mat_cnt = 1 ;

    for(int i=1; i<=N; i++) {
        Line l ;
        l.read() ;
        int pre = 0 ;
        for(int k=1; k<=mat_cnt; k++) {
            if(line_on_mat(l , M[k])) {
                pre = k ;
                break ;
            }
        }
        cut(M[pre] , l) ;
        son[pre][0] = mat_cnt - 1 ;
        son[pre][1] = mat_cnt ;
    }
}
void dfs(int u) {
    sz[u] = 0 ;
    if(son[u][0]) sz[u] ++ ;
    if(son[u][0]) dfs(son[u][0]) , sz[u] += sz[ son[u][0] ]  ;
    if(son[u][1]) dfs(son[u][1]) , sz[u] += sz[ son[u][1] ]  ;
}

int path[2][maxn], len[2] ;

void print_path(int x, int y, int u, int *p , int &len) {
    p[len++] = u ;
    if(son[u][0] && point_in_mat(M[ son[u][0] ] , x, y)) print_path(x , y , son[u][0] , p, len) ;
    if(son[u][1] && point_in_mat(M[ son[u][1] ] , x, y)) print_path(x , y , son[u][1] , p, len) ;
}

void query() {
    int x1 , y1 , x2 , y2;
    scanf("%d%d%d%d", &x1, &y1, &x2 , &y2) ;
    len[0] = len[1] = 0 ;
    print_path(x1, y1 , 1 , path[0], len[0]) ;
    print_path(x2, y2 , 1 , path[1] , len[1]) ;

    int x = 1 ;
    while(x < len[0] && x<len[1] && path[0][x] == path[1][x]) x ++ ;
    int tmp = sz[ path[0][x-1] ] ;
    printf("%d\n" , N+1 - tmp) ;
}

int main()
{
//    freopen("data.in","r", stdin) ;

    while(M[1].read()) {
        scanf("%d%d", &N, &Q) ;
        build();
        dfs(1) ;
        while(Q--) query() ;
    }
    return 0;
}
