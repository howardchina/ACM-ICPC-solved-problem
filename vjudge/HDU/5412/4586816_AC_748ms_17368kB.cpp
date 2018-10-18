#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 100050 * 3;

struct Oper{
    int id , l , r , k ;
    Oper (int id=0, int l=0, int r=0, int k=0):id(id), l(l) ,r(r) , k(k) {}
}q[maxn], q1[maxn] , q2[maxn];
int A[maxn] ,B[maxn],ans[maxn], san[maxn], sn , N , Q, qn , ans_n ;

inline int lowbit(int x){
    return x & -x ;
}
void update(int x ,int v) {
    for(; x<=N; x+=lowbit(x)) B[x] += v;
}
int query(int x) {
    int ret =0 ;
    for(; x>0; x-=lowbit(x))  ret += B[x] ;
    return ret ;
}

void solve(int l,int r,int L, int R) {
    if(L == R) {
        for(int i=l; i<=r; i++) {
            if(q[i].id) ans[q[i].id] = san[L-1] ;
        }
        return ;
    }
    int mid = L + (R-L) / 2 ;
    int n1=0 , n2 = 0;
    for(int i=l; i<=r; i++) {
        if(q[i].id) {
            int cnt = query(q[i].r) - query(q[i].l - 1) ;
            if(q[i].k <= cnt) q1[n1++] = q[i] ;
            else q[i].k -= cnt , q2[n2++] = q[i] ;
        }
        else if(q[i].id == 0) {
            if(q[i].k <= mid) q1[n1++] = q[i] , update(q[i].l , q[i].r) ;
            else q2[n2++] = q[i] ;
        }
    }
    for(int i=0; i<n1; i++) {
        if(q1[i].id == 0) update(q1[i].l , -q1[i].r) ;
    }
    memcpy(q+l, q1, n1*sizeof(q[0])) ;
    memcpy(q+l+n1, q2, n2*(sizeof(q[0]))) ;
    solve(l, l+n1-1, L , mid) ;
    solve(l+n1, r , mid+1, R) ;
}

int main()
{
//    freopen("data.in", "r" ,stdin) ;

    while(scanf("%d", &N) == 1) {
        sn = qn = ans_n = 0 ;
        for(int i=1; i<=N; i++) {
            scanf("%d", &A[i]) ;
            san[sn++] = A[i] ;
            q[qn++] = Oper(0 , i , 1 , A[i]) ;
        }
        scanf("%d", &Q) ;
        for(int i=1; i<=Q; i++) {
            int op , l , r , k ;
            scanf("%d%d%d", &op, &l , &r) ;
            if(op == 1) {
                q[qn++] = Oper(0 , l , -1 , A[l]) ;
                q[qn++] = Oper(0 , l , 1 , r) ;
                san[sn++] = A[l] = r ;
            }
            else {
                scanf("%d", &k) ;
                q[qn++] = Oper(++ans_n , l ,r, k) ;
            }
        }
        sort(san,  san+sn) ;
        sn = unique(san,  san+sn) - san ;
        for(int i=0; i<qn; i++) {
            if(q[i].id == 0) q[i].k = lower_bound(san , san+sn , q[i].k) - san + 1 ;
        }
        solve(0,qn-1, 1, sn) ;
        for(int i=1; i<=ans_n; i++) printf("%d\n",ans[i]) ;
    }
    return 0;
}
