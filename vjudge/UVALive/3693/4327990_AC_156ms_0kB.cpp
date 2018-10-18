#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <cassert>
#include <vector>
#include <map>
using namespace std;
typedef int LL ;
const int maxn = 45000 ;
const int maxv = 10240 ;

int a[20];
vector<int>S[maxv] ;
int X[1<<16];

void dfs(int d , int s, int v) {
    if(d == 4) {
        S[v].push_back(s) ;
        return ;
    }
    for(int i=0; i<16; i++) {
        if(s & (1<<i)) continue ;
        dfs(d+1 , s|(1<<i) , v + a[i]*(d+1)) ;
    }
}



int main()
{
//    freopen("data.in", "r", stdin) ;
    int cas = 1 ;
    while(scanf("%d", &a[0]) == 1 && a[0]) {
        for(int i=1 ;i<16; i++) scanf("%d", &a[i]) ;
        for(int i=0; i<maxv; i++) S[i].clear() ;
        dfs(0 , 0 , 0) ;

        memset(X, 0, sizeof(X)) ;
        for(int t=0; t<maxv; t++) {
            if(S[t].size() < 2) continue ;
            for(size_t i=0; i<S[t].size(); i++) {
                for(size_t j=i+1; j<S[t].size(); j++) {
                    if(S[t][i] & S[t][j]) continue ;
                    X[ S[t][i] | S[t][j] ] ++ ;
                }
            }
        }
        int ans = 0 ;
        for(int i=0; i<32768; i++) {
            ans += X[i] * X[65535 ^ i] ;
        }
        printf("Case %d: %d\n" , cas++ , ans) ;

    }
}
