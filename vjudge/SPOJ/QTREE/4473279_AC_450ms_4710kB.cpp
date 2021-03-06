#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define inf 0x7fffffff
const int N = 10000 + 10;

int RD(){
    int x;
    scanf("%d",&x);
    return x;
//    int x=0,f=1;char ch=getchar();
//    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
//    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
//    return x*f;
}

struct Edge{int to,nxt,c;}e[N<<1];
int tot, head[N], n, sz, vis[N];
void initt(){
    tot = 0;
    for(int i=1;i<=n;i++) head[i] = vis[i] = 0;
    sz = 0;
}
void add(int u,int v,int c){
    e[++tot].to = v; e[tot].nxt = head[u]; e[tot].c = c; head[u] = tot;
    e[++tot].to = u; e[tot].nxt = head[v]; e[tot].c = c; head[v] = tot;
}
int siz[N], fa[N], dep[N], val[N];
void dfs1(int u){
    siz[u] = 1; vis[u] = 1;
    for(int i=head[u];i;i=e[i].nxt){
        int v = e[i].to;
        if (vis[v]) continue;
        dep[v] = dep[u] + 1;
        val[v] = e[i].c;
        fa[v] = u;
        dfs1(v);
        siz[u] += siz[v];
    }
}
int pos[N], belong[N];
void dfs2(int u,int f){
    int k = 0;
    pos[u] = ++sz; belong[u] = f;
    for(int i=head[u];i;i=e[i].nxt){
        int v = e[i].to;
        if (dep[v] > dep[u] && siz[v] > siz[k]) k = v;
    }
    if (!k) return;
    dfs2(k, f);
    for(int i=head[u];i;i=e[i].nxt){
        int v = e[i].to;
        if (dep[v] > dep[u] && v != k) dfs2(v, v);
    }
}

struct Seg{int l,r,mx;}t[N<<2];
inline void pushup(int k){
    t[k].mx = max(t[k<<1].mx, t[k<<1|1].mx);
}
void build(int k,int l,int r){
    t[k].l = l; t[k].r = r;
    t[k].mx = 0;
    if (l==r) return;
    int mid = (l+r)>>1;
    build(k<<1, l, mid);
    build(k<<1|1,mid+1,r);
}
inline void change(int k,int x,int y){
    int l = t[k].l, r = t[k].r, mid = (l+r)>>1;
    if (l == r){ t[k].mx = y; return; }
    if (x <= mid) change(k<<1, x, y);
    else change(k<<1|1, x, y);
    pushup(k);
}
inline int queryMax(int k,int x,int y){
    int l = t[k].l, r = t[k].r, mid = (l+r)>>1;
    if (x <= l && r <= y) return t[k].mx;
    if (y <= mid) return queryMax(k<<1, x, y);
    else if (x > mid) return queryMax(k<<1|1, x, y);
    else return max(queryMax(k<<1, x, mid), queryMax(k<<1|1, mid+1, y));
}
inline int solveMax(int x,int y){
    int mx = -inf;
    while(belong[x] != belong[y]){
        if (dep[belong[x]] < dep[belong[y]]) swap(x,y);
        mx = max(mx, queryMax(1, pos[belong[x]], pos[x]));
        x = fa[belong[x]];
    }
    if (x == y) return mx;
    if (dep[x] < dep[y]) swap(x, y);
    if (pos[y]+1 <= pos[x]){
        mx = max(mx, queryMax(1, pos[y]+1, pos[x]));
    }
    return mx;
}
void debug(int k){
    int l = t[k].l, r = t[k].r;
    printf("l:%d r:%d max:%d\n", l, r, t[k].mx);
    if (l==r)  return;
    debug(k<<1);
    debug(k<<1|1);
}
int main()
{
//    freopen("data.in", "r", stdin);
    int T;
    T = RD();
    while(T--){
        n = RD();
        initt(); int a, b, c;
        for(int i=1;i<n;i++){
            a = RD(), b = RD(), c = RD();
            add(a, b, c);
        }
        dfs1(1);
        dfs2(1,1);
        build(1,1,n);
        for(int i=1;i<=n;i++){
            change(1, pos[i], val[i]);
        }
//        debug(1);
        char s[10];
        while(1){
            scanf("%s", s);
            if (s[0] == 'D') break;
            a = RD(), b = RD();
            if (s[0] == 'Q'){
                printf( "%d\n", solveMax(a, b));
            }else{
                int x = e[a<<1].to;
                int y = e[(a<<1) - 1].to;
                if (dep[x]<dep[y]) swap(x, y);
                change(1, pos[x], b);
            }
        }
//        debug(1);
    }
    return 0;
}
