#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL ;
const int maxn = 20 ;

char buf[maxn] ;
int d[maxn] , N , Mid , ans ;
LL sum1 ;

void dfs2(int k , LL sum , LL tmp) {
    if(k == N) {
        if(sum + tmp == sum1) ans ++ ;
        return ;
    }
    dfs2(k+1,  sum+tmp , d[k+1]) ;
    dfs2(k+1, sum , tmp*10 + d[k+1]) ;
}

void dfs1(int k , LL sum , LL tmp) {
    if(k == Mid) {
        sum1 = sum + tmp ;
        dfs2(k+1 , 0 , d[k+1]) ;
        return ;
    }
    dfs1(k+1 , sum+tmp , d[k+1]) ;
    dfs1(k+1, sum , tmp*10 + d[k+1]) ;
}

int main()
{
    while(scanf("%s", buf + 1) != EOF && strcmp(buf+1 , "END") != 0) {
        N = strlen(buf+1) ;
        for(int i=1; i<=N; i++) d[i] = buf[i] - '0' ;
        ans = 0 ;
        for(Mid=1; Mid<N; Mid ++)
        dfs1(1 , 0 , d[1]) ;
        printf("%d\n" , ans) ;
    }
    return 0;
}
