#include <cstdio>
#include <iostream>
using namespace std;
#define lowbit(x) (x & (-x))
const int maxn = 2e6 + 10;
const int maxm = 1e5 + 10;
struct FU{
    int p, l, r, city;
}s[maxm];
int a[maxn], b[maxn];
int Find(int x){
    return x != s[x].p ? s[x].p = Find(s[x].p) : x;
}
void Add(int l, int r, int state, int city){
    if(l >= r) return;
    while(r>0){
        a[r] += state;
        b[r] += city;
        r-=lowbit(r);
    }
    while(l>0){
        a[l] -= state;
        b[l] -= city;
        l-=lowbit(l);
    }
}
void Query(int x, int &ans1, int &ans2){
    ans1 = ans2 = 0;
    while(x < maxn){
        ans1 += a[x];
        ans2 += b[x];
        x +=lowbit(x);
    }
}
void Union(int x, int y){
    int fx = Find(x), fy = Find(y);
    if(fx != fy){
        if(s[fx].city != 1)
            Add(s[fx].l, s[fx].r, -1, -s[fx].city);
        if(s[fy].city != 1)
            Add(s[fy].l, s[fy].r, -1, -s[fy].city);
        s[fy].p = fx;
        s[fx].city += s[fy].city;
        s[fx].l = min(s[fx].l, s[fy].l);
        s[fx].r = max(s[fx].r, s[fy].r);
        Add(s[fx].l, s[fx].r, 1, s[fx].city);
    }
}
int main()
{
//    freopen("data.in", "r", stdin);
    int T, n, m;
    char str[30];
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%d%d", &m, &s[i].r);
            s[i].p = i, s[i].city = 1, s[i].l = s[i].r;
        }
        scanf("%d", &m);
        int x, y, ans1, ans2;
        for(int i = 0; i < maxn; i++) a[i] = b[i] = 0;
        while(m--){
            scanf("%s", str);
            if(str[0] == 'r'){
                scanf("%d%d", &x, &y);
                Union(x, y);
            }else{
                scanf("%d.%d", &x, &y);
                Query(x+1, ans1, ans2);
                printf("%d %d\n", ans1, ans2);
            }
        }
    }
    return 0;
}
