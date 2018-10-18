#include <iostream>
#include <cstdio>

using namespace std;

const int N = 50000 + 10;

int sum[N<<2];
int a[N];

int t;

void pushup(int k){
    sum[k] = sum[k<<1] + sum[k<<1|1];
}

void build(int k, int l, int r){
    if (l == r){ sum[k] = a[l]; return; }
    int m = (l+r)>>1;
    build(k<<1, l, m);
    build(k<<1|1, m+1, r);
    pushup(k);
}

void add(int k, int l, int r, int x, int y){
    if (l == r){ sum[k] += y; return; }
    int m = (l+r)>>1;
    if (x <= m) add(k<<1, l, m, x, y);
    else add(k<<1|1, m+1, r, x, y);
    pushup(k);
}

void query(int k, int l, int r, int x, int y){
    if (x <= l && r <= y){ t += sum[k]; return; }
    int m = (l+r)>>1;
    if (x <= m) query(k<<1, l, m, x, y);
    if (y > m) query(k<<1|1, m+1, r, x, y);
}

int main()
{
//    freopen("data.in", "r", stdin);
    int T, x, y, cas=1;
    scanf("%d", &T);
    while(T--){
        printf("Case %d:\n", cas++);
        int n; scanf("%d", &n);
        for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
        build(1, 1, n);
        char s[10];
        while(1){
            scanf("%s", s);
            if (s[0] == 'E') break;
            scanf("%d%d", &x, &y);
            if (s[0] == 'A'){
                add(1, 1, n, x, y);
            }
            else if (s[0] == 'S'){
                add(1, 1, n, x, -y);
            }
            else{
                t = 0;
                query(1, 1, n, x, y);
                printf("%d\n", t);
            }
        }
    }
    return 0;
}
