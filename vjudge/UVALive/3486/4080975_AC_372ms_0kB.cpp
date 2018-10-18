#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f ;
const int maxn = 300050 ;

int C[maxn],firstson[maxn], N ;
int _son[maxn],_fa[maxn], _n ;
int in[maxn] , out[maxn] , stk[maxn] , vis[maxn] ;

int find_fa(int x) { // x >= N
    int L = 0 , R = _n - 1 ;
    while(L < R) {
        int mid = L + (R-L+1)/2;
        if(_son[mid] <= x) L = mid ;
        else R = mid - 1 ;
    }
    return _fa[L] ;
}

void dfs(int u) {
    int top = 0 , dfs_clock = 0 ;
    memset(vis, 0 , sizeof(vis)) ;
    stk[top++] = u ;
    while(top) {
        int x = stk[top-1] ;
        if(vis[x]) {
            out[x] = ++ dfs_clock ;
            top -- ;
        }
        else {
            vis[x] = 1 ;
            in[x] = ++ dfs_clock;
            for(int v = firstson[x]; v<firstson[x] + C[x] ; v++) {
                if(v < N) stk[top++] = v  ;
            }
        }
    }
}

int main()
{
//    freopen("data.in", "r", stdin) ;

    int T ,cas = 1 ;
    scanf("%d", &T) ;
    while(T--) {
        scanf("%d", &N) ;
        for(int i=0; i<N; i++)
            scanf("%d", &C[i]) ;
        firstson[0] = 1;
        for(int i=1; i<N; i++)
            firstson[i] = firstson[i-1] + C[i-1];
        _n = 0 ;
        for(int i=0; i<N; i++) {
            if(C[i] > 0 && firstson[i]+C[i]-1 >= N) {
                _son[_n] = firstson[i];
                _fa[_n] = i ;
                _n ++ ;
            }
        }

//        int x ; while(cin>>x) cout<<find_fa(x)<<endl;

        dfs(0) ;
        if(cas > 1) printf("\n") ;
        printf("Case %d:\n", cas++) ;
        int Q ;
        scanf("%d", &Q) ;
        while(Q--) {
            int x , y ;
            scanf("%d%d", &x, &y) ;
            if(x >= N) printf("No\n") ;
            else if(x<N && y<N) {
                printf("%s\n" , in[x]<in[y] && out[y]<out[x] ? "Yes" : "No") ;
            }
            else if(x<N && y>=N) {
                y = find_fa(y) ;
                printf("%s\n" , in[x]<=in[y] && out[y]<=out[x] ? "Yes" : "No") ;
            }
        }
    }
    return 0;
}
