#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 2110;
struct TwoSet{
    int n;
    vector<int>G[maxn*2];
    bool mark[maxn*2];
    int S[maxn*2] , c;

    void init(int n){
        this->n = n;
        for(int i=0;i<n*2;i++) G[i].clear();
        memset(mark, 0 , n*2*sizeof(mark[0]));
    }
    void add_clause(int x,int y){
        G[x].push_back(y) ;
    }
    bool dfs(int u){
        if(mark[u^1]) return false;
        if(mark[u])  return true;
        mark[u] = true;
        S[c++] = u;
        int ecnt = G[u].size();
        for(int i=0;i<ecnt;i++){
            if(!dfs(G[u][i])) return false;
        }
        return true;
    }
    bool solve(){
        for(int i=0;i<n*2;i+=2){
            if(!mark[i] && !mark[i^1]){
                c = 0 ;
                if(!dfs(i)){
                    while(c>0) mark[S[--c]] = false;
                    if(!dfs(i^1)) return false;
                }
            }
        }
        return true;
    }
}sol;

int N,M;
int key1[maxn] , key2[maxn];
int lock1[maxn] , lock2[maxn];

bool check(int max_floor) {
    sol.init(2*N) ;
    for(int i=1; i<=N; i++) {
        sol.add_clause(key1[i]*2+1 ,  key2[i]*2) ;
        sol.add_clause(key2[i]*2+1 ,  key1[i]*2) ;
    }
    for(int i=1; i<=max_floor; i++) {
        sol.add_clause(lock1[i]*2 , lock2[i]*2+1) ;
        sol.add_clause(lock2[i]*2 , lock1[i]*2+1) ;
    }
    return sol.solve() ;
}

int main()
{
    while(scanf("%d%d", &N, &M) == 2 && N+M) {
        for(int i=1; i<=N; i++) scanf("%d%d", &key1[i], &key2[i]) ;
        for(int i=1; i<=M; i++) scanf("%d%d", &lock1[i], &lock2[i]) ;

        int L = 0, R = M ;
        while(L < R) {
            int mid = L + (R-L+1)/2;
            if(check(mid)) L = mid ;
            else R = mid - 1 ;
        }
        printf("%d\n", L) ;

    }
    return 0;
}
