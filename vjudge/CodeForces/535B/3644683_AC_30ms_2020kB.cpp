#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int dig[20], n;

int dfs(int d , bool equ) {
    if(!equ) return ( 1<<(d+1) ) ;
    if(d == 0) {
        return dig[0] == 4 ? 1 : 2 ;
    }
    int ret = 0 ;
    ret += dfs(d-1 , equ && dig[d] == 4) ;
    if(dig[d] == 7)  ret += dfs(d-1 , equ && dig[d] == 7) ;
    return ret ;
}

int main()
{
    int x;
    cin>>x;
    while(x) dig[n++] = x % 10, x /= 10 ;
    dig[n] = 4 ;

    int ans = 0 ;
    for(int i=1; i<n; i++) ans += 1<<i ;
    ans += dfs(n , true) ;

    cout<<ans<<endl;

    return 0;
}
