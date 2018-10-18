#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 10050 ;

int mod[maxn] , pre[maxn] , val[maxn];
bool vis[11] ;

int main()
{
//    freopen("data.in", "r", stdin) ;

    int n , m , cas = 1 ;
    while(scanf("%d%d", &n, &m) == 2) {
        memset(vis, 0, sizeof(vis)) ;
        for(int i=1; i<=m; i++) {
            int x;
            scanf("%d", &x) ;
            vis[x] = true ;
        }
        memset(mod, 0 , sizeof(mod));
        memset(pre, -1, sizeof(pre)) ;

        queue<int>Q ;
        for(int i=1; i<=9; i++) {
            if(vis[i]) continue ;
            if(!mod[i % n])
                Q.push(i % n) , mod[i % n] = 1, val[i%n] = i ;
        }
        while(!Q.empty()) {
            int u = Q.front() ; Q.pop() ;
            if(u == 0) break ;
            for(int i=0; i<10; i++) {
                if(vis[i]) continue ;
                int v = (u*10 + i) % n ;
                if(mod[v]) continue ;
                mod[v] = 1 , pre[v] = u , val[v] = i ;
                Q.push(v) ;
            }
        }

        printf("Case %d: ", cas++) ;

        if(!mod[0]) {
            printf("-1\n") ;
            continue ;
        }
        vector<int> ans ;
        int t = 0 ;
        while(t!=-1 && mod[t]) {
            ans.push_back(val[t]) ;
            t = pre[t] ;
        }

        for(int i=ans.size()-1 ; i>=0 ; i--) printf("%d" , ans[i]) ;
        printf("\n") ;
    }
    return 0;
}
