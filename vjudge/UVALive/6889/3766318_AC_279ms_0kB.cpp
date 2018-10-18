#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 50050 ;
const int INF = 0x3f3f3f3f ;

int N;
int X[maxn], Y[maxn], W[maxn], H[maxn] ;
int fa[maxn], area[maxn];
int Find(int u){
    return fa[u] == u ? u : fa[u] = Find(fa[u]) ;
}
void Union(int u , int v) {
    int fu = Find(u) , fv = Find(v) ;
    if(fu != fv) {
        area[fu] += area[fv] ;
        area[fv] = 0 ;
        fa[fv] = fu ;
    }
}

struct Node{
    int l , r, x, id  ;
    Node(int l=0 , int r=0 , int x=0 , int id =0) :
    l(l) , r(r) , x(x) , id(id) {} ;
    bool operator < (const Node&rr) const {
        if(x != rr.x) return x < rr.x ;
        if(l != rr.l) return l < rr.l ;
        return r < rr.r ;
    }
}seg[maxn*2];
int sn ;

void solve(){
    sort(seg , seg+sn);
    for(int i=0; i<sn; i++) {
        int t = i ;
        while(t<sn-1 && seg[t+1].x == seg[i].x) t ++ ;
        int last = seg[i].r ;
        for(int j=i+1; j<=t; j++) {
            if(seg[j].l <= last) Union(seg[j-1].id , seg[j].id) ;
            last = max(last , seg[j].r) ;
        }
        i = t ;
    }
}


int main()
{
   // freopen("in.txt", "r", stdin);

    while(scanf("%d", &N)== 1) {
        for(int i=0; i<=N; i++) fa[i] =  i;

        for(int i=1; i<=N; i++) {
            scanf("%d%d%d%d", &X[i], &Y[i], &W[i] ,&H[i]) ;
            area[i] = W[i] * H[i] ;
        }

        sn = 0 ;
        for(int i=1; i<=N; i++){
            seg[sn++] = Node(Y[i], Y[i]+H[i], X[i] , i) ;
            seg[sn++] = Node(Y[i], Y[i]+H[i], X[i]+W[i], i);
        }
        solve() ;

        sn = 0 ;
        for(int i=1; i<=N; i++) {
            seg[sn++] = Node(X[i], X[i]+W[i] , Y[i] ,i) ;
            seg[sn++] = Node(X[i], X[i]+W[i] , Y[i]+H[i], i) ;
        }
        solve();

        int ans = 0 ;
        for(int i=1;i<=N;i++) ans = max(ans, area[i]) ;

        printf("%d\n" , ans);

    }
    return 0;
}
