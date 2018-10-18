#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const int maxn = 3001003;

#define lowbit(x) (x&(-x))

int to[maxn];
int v[maxn];

int Hash(int x){
    int key = x%maxn;
    for(int i = key;;i++){
        if (i==maxn) i = 0;
        if (to[i] && to[i] != x){}
        else{
            to[i] = x;
            return i;
        }
    }
}

int search(int x){
    int key = x%maxn;
    for(int i = key;;i++){
        if (i==maxn) i = 0;
        if (to[i] && to[i] != x){}
        else{
            return i;
        }
    }
}

int N;

void add(int x, int y, int z){
    for(int i = x; i <= N; i+=lowbit(i)){
        for(int j = y; j <= N; j+=lowbit(j)){
            v[Hash(i*N+j)] += z;
        }
    }
}

int query(int x, int y){
    int re = 0;
    for(int i = x; i > 0; i-=lowbit(i)){
        for(int j = y; j > 0; j-=lowbit(j)){
            re += v[search(i*N+j)];
        }
    }
    return re;
}


int main()
{
//    freopen("data.in", "r", stdin);
    int n, m, p, x, y, z, _x, _y, x1, x2, y1, y2;
    while(1){
        scanf("%d", &n);
        if (!n) break;
        scanf("%d", &m);
        N = n*2;
        memset(to, 0, sizeof to);
        memset(v, 0, sizeof v);
        while(m--){
            scanf("%d%d%d%d", &p, &_x, &_y, &z);
            x = (_x - _y) + n;
            y = (_x + _y) - 1;
            if (p == 1){
                add(x, y, z);
            }
            else{
                x1 = max(1, x-z);
                y1 = max(1, y-z);
                x2 = min(N, x+z);
                y2 = min(N, y+z);
                printf("%d\n", query(x2, y2) -  query(x1-1, y2) - query(x2, y1-1) + query(x1-1, y1-1));
            }
        }
    }
    return 0;
}
