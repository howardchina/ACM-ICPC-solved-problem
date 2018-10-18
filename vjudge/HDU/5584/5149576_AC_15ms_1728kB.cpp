#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;

LL gcd(LL a , LL b) {
    return b==0 ? a : gcd(b , a%b) ;
}
int dfs(LL x , LL y) {
    if(x == y) return 1 ;
    int ret = 1 ;
    if(x > y) swap(x , y) ;
    LL k = gcd(x , y) ;
    x/=k , y/=k;
    if(y % (x+1) == 0) ret += dfs(x*k , y/(x+1)*k) ;
    return ret ;
}

int main()
{
    int T , cas = 1;
    scanf("%d", &T) ;
    while(T--) {
        int x , y ;
        scanf("%d%d", &x, &y) ;
        printf("Case #%d: %d\n" , cas++, dfs(x, y));
    }
    return 0;
}
