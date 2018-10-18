#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 505;
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
    void add(int x , int y) {
        G[x].push_back(y);
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

int N ;
int b[maxn][maxn] ;

bool check(int d) {
    sol.init(N) ;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++){
            int tmp  =  ( b[i][j] >> d ) & 1 ;
            if(i == j) {
                if(b[i][j] != 0) return false ;
            }
            else if(i%2 == 1 && j%2 == 1) {
                if(tmp) {
                    sol.add(i*2, j*2+1) ;
                    sol.add(j*2, i*2+1) ;
                }
                else {
                    sol.add(i*2+1,  i*2) ;
                    sol.add(j*2+1,  j*2) ;
                }
            }
            else if(i%2 == 0 && j%2 == 0) {
                if(tmp) {
                    sol.add(i*2, i*2+1);
                    sol.add(j*2, j*2+1);
                }
                else {
                    sol.add(i*2+1, j*2) ;
                    sol.add(j*2+1, i*2) ;
                }
            }
            else {
                if(tmp) {
                    sol.add(i*2, j*2+1);
                    sol.add(i*2+1, j*2) ;
                    sol.add(j*2, i*2+1);
                    sol.add(j*2+1, i*2) ;
                }
                else {
                    sol.add(i*2, j*2) ;
                    sol.add(i*2+1, j*2+1) ;
                    sol.add(j*2, i*2) ;
                    sol.add(j*2+1 , i*2+1) ;
                }
            }
        }
    }

    return sol.solve();
}

int main()
{
    while(scanf("%d", &N) == 1) {
        int D = 0 ;
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++) {
                scanf("%d", &b[i][j]) ;
                while((1LL<<D) < b[i][j]) D ++;
            }
        bool flag = true ;
        for(int d=0; d<31; d++) {
            if(!check(d)) {
                flag = false ;
                break ;
            }
            if(d > D+1) break ;
        }
        if(flag) puts("YES") ;
        else puts("NO");
    }
    return 0;
}
