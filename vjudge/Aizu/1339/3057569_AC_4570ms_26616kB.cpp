#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#include <cassert>
using namespace std;
typedef long long LL;
typedef pair<int , LL>PII;

int ch , cv ;
map<LL , int> M;
LL start , finish;

int next[9][4] = {
    {1 , 8 , 6 , 3},
    {2 , 0 , 7 , 4} ,
    {3 , 1 , 8 , 5} ,
    {4 , 2 , 0 , 6} ,
    {5 , 3 , 1 , 7} ,
    {6 , 4 , 2 , 8} ,
    {7 , 5 , 3 , 0} ,
    {8 , 6 , 4 , 1} ,
    {0 , 7 , 5 , 2}
};

//LL a[10] ;


int main()
{ 

    while(scanf("%d%d", &ch , &cv) == 2 && ch + cv) {
        start = 0 ;
        for(int i=0; i<9; i++) {
            LL x ;
            scanf("%lld", &x) ;
            start = start | ( x << 4*i) ;
        }
        finish =  0;
        for(int i=0; i<9; i++) {
            LL x ;
            scanf("%lld", &x) ;
            finish = finish | ( x << 4*i)  ;
        }
        M.clear() ;
        priority_queue<PII>Q ;
        M[start] = 0 ;
        Q.push(make_pair(0 , start)) ;
        int ans = 0;
        while(!Q.empty()) {
            PII ts = Q.top() ; Q.pop() ;
            LL u = ts.second ;
            if(-ts.first > M[u]) continue ;
            if(u == finish) {
                ans = M[u] ;
                break ;
            }

            for(int i=0; i<9; i++) if( u & (15LL << i*4) ) {
                for(int j=0; j<4; j++) if( (u & (15LL << next[i][j]*4 )) == 0 ) {
                    LL tmp = ( (u >> i*4) & 15 ) ;
                    LL tmp2  = (1LL << 36) - 1 - (15LL << i*4) ;
                    LL v = (u & tmp2) | (tmp<<next[i][j]*4) ;
                    int cost = M[u] + (j<2 ? ch : cv) ;
                    if(!M.count(v) || cost < M[v]) {
                        M[v] = cost ;
                        Q.push(make_pair(-cost , v)) ;
                    }
                }
            }

        }
        printf("%d\n",ans) ;
    }
    return 0;
}
