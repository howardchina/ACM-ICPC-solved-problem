#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define lb(x) (x&(-(x)))
const int MaxN = 70000;
int a[MaxN], mp[MaxN];
int n;

void Insert(int x, int v){
    while(x <= n){
        if(a[x] < v)
            a[x] = v;
        x += lb(x);
    }
}

int Query(int x){
    int ret = 0;
    while(x){
        if(ret < a[x])
            ret = a[x];
        x -= lb(x);
    }
    return ret;
}

int main()
{
//    freopen("data.in", "r", stdin);
    int T, p, q, x, ans;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++){
        scanf("%d%d%d", &n, &p, &q);
        n *= n;
        p++, q++;
        memset(mp, 0, sizeof mp);
        for(int i = 1; i <= p; i++){
            scanf("%d", &x);
            mp[x] = i;
        }
        memset(a, 0, sizeof a);
        ans = 0;
        for(int i = 1; i <= q; i++){
            scanf("%d", &x);
            if(mp[x])
                Insert(mp[x], Query(mp[x]-1)+1);
        }
        ans = Query(n);
        printf("Case %d: %d\n", cas, ans);
    }
    return 0;
}
