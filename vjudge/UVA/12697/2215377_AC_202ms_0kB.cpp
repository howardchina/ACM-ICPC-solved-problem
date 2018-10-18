#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
const int maxn = 500050;
const int inf = 0x3fffffff;
ll sum[maxn];
ll minseg[maxn*4];
void Build(int o, int l, int r)
{

    if(l == r){
        minseg[o] = sum[l];
        return;
    }else{
        int m = (l+r)>>1;
        Build(o<<1, l, m);
        Build((o<<1)|1, m+1, r);
        minseg[o] = min(minseg[o<<1], minseg[(o<<1)|1]);
    }
}
int Query(int o, int l, int r, int ql, int qr, ll v){
    if(l == r){
        if(minseg[o] <= v)
            return l;
        return -1;
    }else{
        int m = (l+r)>>1;
        if(qr > m && minseg[(o<<1)|1] <= v) return Query((o<<1)|1, m+1, r, ql, qr, v);
        if(ql <= m && minseg[o<<1] <= v) return Query(o<<1, l, m, ql, qr, v);
        return -1;
    }
}
int main()
{
    int tcas, n, x, a;
    scanf("%d", &tcas);
    while(tcas--){
        scanf("%d%d", &n, &x);
        sum[0] = 0;
        for(int i = 1; i <= n; i++)
            scanf("%d", &a), sum[i] = a+sum[i-1];
        Build(1, 0, n);
        int ans = inf;
        for(int ri = 1;ri <= n; ri++){
            ll need = sum[ri] - x;
            int le = Query(1,0,n,0,ri-1,need);
            if(le != -1)
                ans = min(ans, ri - le);
        }
        printf("%d\n", (ans == inf)?-1:ans);
    }
    return 0;
}