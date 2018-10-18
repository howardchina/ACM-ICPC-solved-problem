#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef unsigned long long uLL ;
const int MOD = 20071027 ;
const int maxn = 400000 + 100 ;

int son[maxn][26], sz ;
bool isword[maxn] ;

void init() {
    sz = 1 ;
    memset(son[1], 0, sizeof(son[1]));
    isword[1] = false ;
}
int nextnode() {
    ++ sz ;
    memset(son[sz] , 0, sizeof(son[0])) ;
    isword[sz] = false ;
    return sz ;
}
void Insert(char  *s) {
    int u = 1 ;
    for(int i=0; s[i] ; i++) {
        int v = s[i] - 'a' ;
        if(!son[u][v]) son[u][v] = nextnode() ;
        u = son[u][v] ;
    }
    isword[u] = true ;
}

int dp[maxn] , len ;
char text[maxn] ;

int main()
{
//    freopen("data.in", "r", stdin) ;

    int cas = 1 ;
    while(scanf("%s", text+1) != EOF){
        len = strlen(text+1) ;
        int N  ;
        init() ;
        scanf("%d", &N) ;
        for(int i=0; i<N; i++) {
            char word[105] ;
            scanf("%s", word) ;
            Insert(word) ;
        }
        memset(dp, 0, (len+1) * sizeof(dp[0])) ;
        dp[0] = 1 ;

        for(int  i=0; i<len; i++) {
            int u = 1 , x = 0 , v ;
            for(; u ; u = son[u][v]) {
                if(isword[u]) {
                    dp[i+x] += dp[i] ;
                    if(dp[i+x] >= MOD) dp[i+x] -= MOD ;
                }
                x ++ ;
                if( !text[i+x]) break ;
                v = text[i+x]-'a' ;
            }
        }

        printf("Case %d: %d\n" ,cas++, dp[len]) ;

    }
    return 0;
}
