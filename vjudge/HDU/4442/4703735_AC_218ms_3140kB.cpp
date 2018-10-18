#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100050 ;
typedef long long LL ;
const int MOD = 365*24*60*60 ;

struct Node{
    LL a,b ;
    bool operator < (const Node & rhs) const {
        return a * rhs.b < rhs.a * b ;
    }
}p[maxn];

int main()
{
    int N ;
    while(scanf("%d", &N) == 1 && N) {
        for(int i=0; i<N; i++) scanf("%I64d%I64d" , &p[i].a, &p[i].b) ;
        LL ans = 0 ;
        sort(p , p+N) ;
        for(int i=0; i<N; i++) {
            ans = ( p[i].a + (p[i].b + 1 ) * ans ) % MOD ;
        }
        printf("%I64d\n" , ans) ;
    }
    return 0;
}
