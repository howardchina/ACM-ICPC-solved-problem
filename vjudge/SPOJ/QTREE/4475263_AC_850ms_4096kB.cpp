#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int RD(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

const int N = 20000 + 10;

int n, m, top;
int c[N][2], fa[N], q[N];
int w[N], mx[N];
bool rev[N];

bool isroot(int x){
    return c[fa[x]][0] != x && c[fa[x]][1] != x;
}

void update(int x){
    int l = c[x][0], r = c[x][1];
    mx[x] = max(w[x], max(mx[l], mx[r]));
}

void pushdown(int x){
    int l = c[x][0], r = c[x][1];
    if (rev[x]){
        rev[x] ^= 1; rev[l] ^= 1; rev[r] ^= 1;
        swap(c[x][0], c[x][1]);
    }
}

void rotate(int x){
    int y = fa[x], z = fa[y], l, r;
    l = (c[y][1] == x); r = 1^l;
    if (!isroot(y)) c[z][c[z][1] == y] = x;
    fa[c[x][r]] = y; fa[y] = x; fa[x] = z;
    c[y][l] = c[x][r]; c[x][r] = y;
    update(y); update(x);
}

void splay(int x){
    q[++top] = x;
    for(int i=x; !isroot(i); i=fa[i]){
        q[++top] = fa[i];
    }
    while(top) pushdown(q[top--]);
    while(!isroot(x)){
        int y = fa[x], z = fa[y];
        if (!isroot(y)){
            if ((c[y][0] == x) ^ (c[z][0] == y)) rotate(x);
            else rotate(y);
        }
        rotate(x);
    }
}

void access(int x){
    for(int t = 0; x; t = x, x = fa[x]){
        splay(x), c[x][1] = t, update(x);
    }
}

void makeroot(int x){
    access(x); splay(x); rev[x] ^= 1;
}

void link(int x, int y){
    makeroot(x); fa[x] = y;
}

void split(int x,int y){
    makeroot(x); access(y); splay(y);
}

int a[N], b[N];
int main(){
//    freopen("data.in", "r", stdin);
    int T;
    scanf("%d", &T);
    while(T--){
        int n; scanf("%d", &n);
        memset(w, 0, sizeof w);
        memset(c, 0, sizeof c);
        memset(mx, 0, sizeof mx);
        memset(rev, 0, sizeof rev);
        memset(fa, 0, sizeof fa);
        for(int i=1;i<n;i++){
            a[i] = RD(), b[i] = RD(), w[n+i] = RD();
        }
        for(int i=1;i<n;i++){
            link(a[i], i+n);
            link(b[i], i+n);
        }
        char s[10];int x, y;
        while(1){
            scanf("%s", s);
            if (s[0] == 'D') break;
            x = RD(); y = RD();
            if (s[0] == 'C'){
                splay(x+n);
                w[x+n] = y;
                update(x+n);
            }
            else{
                split(x, y);
                printf("%d\n", mx[y]);
            }
        }

    }
    return 0;
}
