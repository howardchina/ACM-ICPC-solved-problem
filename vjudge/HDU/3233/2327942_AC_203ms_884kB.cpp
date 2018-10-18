#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MaxN = 22222;
const double INF = 1000000000000000.0;

struct FN{
    double w, r;
    int p;
    bool operator <(const FN &rhs)const{
        if(w != rhs.w) return w < rhs.w;
        return r < rhs.r;
    }
}fn[MaxN];

struct Node{
    double minv, maxv;
    int minp;
    double setv, addv;
    void init(int pos){
        this->minv = INF, this->maxv = 0, this->minp = pos;
        this->setv = -1, this->addv = 0;
    }
}node[MaxN*4];

double _min, _max;
int _minp;

void Update(int cur, int l, int r){
    int lc, rc;
    lc = cur << 1;
    rc = lc | 1;
    if(node[lc].minv <= node[rc].minv){
        node[cur].minv = node[lc].minv;
        node[cur].minp = node[lc].minp;
    }else{
        node[cur].minv = node[rc].minv;
        node[cur].minp = node[rc].minp;
    }
    node[cur].maxv = max(node[lc].maxv, node[rc].maxv);
}

void Build(int cur, int l, int r){
    int lc, rc, m;
    if(l == r)
        node[cur].init(l);
    if(l < r){
        lc = cur << 1;
        rc = lc | 1;
        m = l + ((r-l)>>1);
        Build(lc, l, m);
        Build(rc, m+1, r);
        Update(cur, l, r);
    }
}

void PushDown(int cur, int l, int r){
    int lc, rc;
    lc = cur << 1;
    rc = lc | 1;
    if(node[cur].setv != -1){
        node[lc].setv = node[rc].setv = node[cur].setv;
        node[lc].addv = node[rc].addv = 0;
        node[lc].minv = node[rc].minv = node[lc].maxv = node[rc].maxv = node[cur].setv;
        node[cur].setv = -1;
    }
    if(node[cur].addv != 0){
        node[lc].addv += node[cur].addv;
        node[rc].addv += node[cur].addv;
        node[lc].minv += node[cur].addv;
        node[rc].minv += node[cur].addv;
        node[lc].maxv += node[cur].addv;
        node[rc].maxv += node[cur].addv;
        node[cur].addv = 0;
    }
}

void Add(int cur, int l, int r, int ql, int qr, double v){
    int lc, rc, m;
    if(ql <= l && r <= qr){
        node[cur].addv += v;
        node[cur].minv += v;
        node[cur].maxv += v;
    }else{
        PushDown(cur, l, r);
        lc = cur << 1;
        rc = lc | 1;
        m = l + ((r-l)>>1);
        if(ql <= m) Add(lc, l, m, ql, qr, v);
        if(qr > m) Add(rc, m+1, r, ql, qr, v);
        Update(cur, l, r);
    }
}

void Set(int cur, int l, int r, int ql, int qr, double v){
    int lc, rc, m;
    if(ql <= l && r <= qr){
        node[cur].setv = v;
        node[cur].addv = 0;
        node[cur].minv = node[cur].maxv = v;
    }else{
        PushDown(cur, l, r);
        lc = cur << 1;
        rc = lc | 1;
        m = l + ((r-l)>>1);
        if(ql <= m) Set(lc, l, m, ql, qr, v);
        if(qr > m) Set(rc, m+1, r, ql, qr, v);\
        Update(cur, l, r);
    }
}

void Query(int cur, int l, int r, int ql, int qr){
    int lc, rc, m;
    if(ql <= l && r <= qr){
        if(_min > node[cur].minv || (_min == node[cur].minv && _minp > node[cur].minp)){
            _min = node[cur].minv;
            _minp = node[cur].minp;
        }
        _max = max(_max, node[cur].maxv);
    }else{
        PushDown(cur, l, r);
        lc = cur << 1;
        rc = lc | 1;
        m = l + ((r-l)>>1);
        if(ql <= m) Query(lc, l, m, ql, qr);
        if(qr > m) Query(rc, m+1, r, ql, qr);
    }
}

int main()
{
//    freopen("data.in", "r", stdin);
    int T, n, cas=1;
    double B;
    double ans;
    while(scanf("%d%d%lf", &T, &n, &B) != EOF && T+n+B){
        for(int i = 0; i < T; i++){
            scanf("%lf%d", &fn[i].w, &fn[i].p);
            fn[i].r = fn[i].w*(100-fn[i].p)/100.0;
            fn[i].r = fn[i].r;
        }
        sort(fn, fn+T);
        Build(1,1,n);
        ans = 0;
        if(n <= T){
            for(int i = 0; i < n; i++)
                Set(1,1,n,i+1,i+1,fn[i].r);
            for(int i = n; i < T; i++){
                _min = INF;
                _minp = n+1;
                Query(1,1,n,1,n);
                ans += _min/(B/n);
                Add(1,1,n,1,n,-_min);
                Set(1,1,n,_minp,_minp,fn[i].r);
            }
        }
        for(int i = 0; i < n;i++){
            _min = INF;
            _minp = n+1;
            Query(1, 1, n, 1, n);
            ans += _min/(B/(n-i));
            Add(1,1,n,1,n,-_min);
            Set(1,1,n,_minp,_minp,INF);
        }
        printf("Case %d: %.2lf\n\n", cas++, ans);
    }
    return 0;
}
