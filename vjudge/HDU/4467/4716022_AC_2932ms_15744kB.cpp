#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
typedef long long LL ;
const int maxn = 100005 ;

int N  ,M ;
bool color[maxn] , kind[maxn] ;
int du[maxn] , e1[maxn], e2[maxn] ;
LL e3[maxn] ;
LL sum[maxn][2] , ans[2][2] ;

int head1[maxn] , head2[maxn] , to[maxn*4] , nxt[maxn*4] , sz ;
LL val[maxn*4] ;

void init() {
    memset(ans ,0 ,sizeof(ans));
    memset(sum, 0, (N+1)*sizeof(sum[0])) ;
    memset(du,0,(N+1)*sizeof(du[0])) ;
    sz = 0;
    memset(head1, -1, (N+1)*sizeof(head1[0])) ;
    memset(head2, -1, (N+1)*sizeof(head2[0])) ;
}
void Add1(int u ,int v ,LL w) {
    if(!kind[v]) return ;
    sum[v][color[u]] += w ;
    to[sz] = v , val[sz] = w , nxt[sz] = head1[u] , head1[u] = sz ++ ;
}
void Add2(int u ,int v ,LL w) {
    if(kind[u]) return ;
    to[sz] = v , val[sz] = w , nxt[sz] = head2[u] , head2[u] = sz ++ ;
}

void ask(int x , int y) {
    printf("%I64d\n" , x==y ? ans[x][y] : ans[x][y] + ans[y][x]) ;
}
void change(int x) {
    color[x]^=1 ;

    // 统计答案
    if(kind[x]) {
        for(int i=0; i<2; i++) {
            ans[ color[x]^1 ][ i ] -= sum[x][i] ;
            ans[ color[x] ] [ i ]  += sum[x][i] ;
        }
    }
    else {
        for(int i=head2[x]; ~i ; i=nxt[i]) {
            ans[ color[x]^1 ][ color[ to[i] ] ]  -= val[i] ;
            ans[ color[x]   ][ color[ to[i] ] ]  += val[i] ;
        }
    }

    // 维护sum[ ][2]
    for(int i=head1[x] ; ~i ; i=nxt[i]) {
        sum[to[i]][ color[x]^1 ] -= val[i] ;
        sum[to[i]][ color[x] ] += val[i] ;
    }

}

int main()
{
//    freopen("data.in","r", stdin) ;
//    freopen("data.out","w",stdout) ;

    int cas = 1, edge_cnt ;
    while(scanf("%d%d", &N, &edge_cnt) == 2) {
        init() ;
        for(int i=1; i<=N; i++) {
            int x ;
            scanf("%d", &x) ;
            color[i] = x ;
        }

        map< pair<int,int> ,  int > ID ;
        M = 0 ;
        for(int i=1; i<=edge_cnt; i++) {
            int u , v , w ;
            scanf("%d%d%d", &u, &v, &w) ;
            int t = 0 ;
            pair<int,int>tmp1 = make_pair(u ,v) , tmp2 = make_pair(v, u) ;
            if(ID.count(tmp1)) t = ID[tmp1] ;
            if(ID.count(tmp2)) t = ID[tmp2] ;
            if(t) {
                e3[t] += w ;
            }
            else {
                ++ M ;
                e1[M] = u , e2[M] = v , e3[M] = w ;
                ID[make_pair(u,v)] = M ;
            }
        }

        for(int i=1; i<=M; i++) {
            //scanf("%d%d%d", &e1[i] , &e2[i], &e3[i]) ;
            du[e1[i]] ++ , du[e2[i]] ++ ;
            ans[ color[e1[i]] ][ color[e2[i]] ] += e3[i] ;
        }
        int limit = sqrt(2*M) ;
        for(int i=1; i<=N; i++) kind[i] = ( du[i] >= limit ) ;
        for(int i=1; i<=M; i++) {
            Add1(e1[i] , e2[i] , e3[i]) ;
            Add1(e2[i] , e1[i] , e3[i]) ;
            Add2(e1[i] , e2[i] , e3[i]) ;
            Add2(e2[i] , e1[i] , e3[i]) ;
        }

        printf("Case %d:\n", cas++) ;
        int Q;
        scanf("%d", &Q) ;
        while(Q--) {
            char op[10] ;
            int x , y;
            scanf("%s",op) ;
            if(op[0] == 'A') {
                scanf("%d%d", &x, &y) ;
                ask(x ,y) ;
            }
            else {
                scanf("%d", &x);
                change(x);
            }
        }

    }
    return 0;
}
