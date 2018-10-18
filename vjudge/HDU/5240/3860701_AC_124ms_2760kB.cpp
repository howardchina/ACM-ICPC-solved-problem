#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL ;
const int MAXN = 100050 ;

struct Node{
    int r , e , l ;
    bool operator < (const Node & b) const  {
        return e < b.e ;
    }
}a[MAXN];

int main()
{
    int T, cas = 1;
    scanf("%d", &T);
    while(T--) {
        int N ;
        scanf("%d", &N) ;
        for(int i=0; i<N; i++) {
            scanf("%d%d%d", &a[i].r, &a[i].e, &a[i].l) ;
        }
        sort(a , a+N) ;
        LL sumL = 0 , need = 0 ;
        bool flag = true ;
        if(a[0].e < a[0].r) flag = false ;
        need = a[0].r ;
        for(int i=1; i<N; i++) {
            need += a[i].r ;
            sumL += a[i-1].l ;
            if(a[i].e - sumL < need) {
                flag = false;
                break ;
            }
        }
        printf("Case #%d: %s\n", cas++ , (flag ? "YES" : "NO") );
    }
    return 0;
}
