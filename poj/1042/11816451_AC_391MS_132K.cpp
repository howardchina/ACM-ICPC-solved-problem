#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAXN = 28;
int n, h, max;
int ans[MAXN];

struct Node{
    int f, d, t, i;
} lake[MAXN];

int comp(const void * c, const void * d)
{
    Node *a = (Node *)c;
    Node *b = (Node *)d;
    if((*b).f != (*a).f) {
        return (*b).f - (*a).f;
    } else {
        return (*a).i - (*b).i;
    }
}

void Input()
{
    int i;
    scanf("%d", &h);
    for(i = 0; i < n; i++) {
        scanf("%d", &lake[i].f);
        lake[i].i = i;
    }
    for(i = 0; i < n; i++) {
        scanf("%d", &lake[i].d);
    }
    for(i = 1; i < n; i++) {
        scanf("%d", &lake[i].t);
    }
    lake[0].t = 0;
}

void Find(int m)
{
    int res[MAXN];
    Node cur[MAXN];
    int i, Time = h * 12, fish = 0;
    memcpy(cur, lake, sizeof(lake));
    for(i = 0; i < m; i++) {
        Time -= cur[i].t;
    }
    memset(res, 0, sizeof(res));
    while(Time > 0) {
        qsort(cur, m, sizeof(Node), comp);
        fish += cur[0].f;
        cur[0].f -= cur[0].d;
        if(cur[0].f < 0) cur[0].f = 0;
        res[cur[0].i]++;
        Time--;
    }
    if(fish > max) {
        max = fish;
        res[0] += Time;
        memcpy(ans, res, sizeof(res));
    }
}

void Output()
{
    int i;
    printf("%d", ans[0]*5);
    for(i = 1; i < n; i++) {
        printf(", %d", ans[i]*5);
    }
    printf("\nNumber of fish expected: %d\n\n", max);
}

int main()
{
//    freopen("data.in", "r", stdin);
//    freopen("data1.out", "w", stdout);
    int i;
    while(scanf("%d", &n) && n != 0) {
        memset(ans, 0, sizeof(ans));
        Input();
        max = -1;
        for(i = 1; i <= n; i++) {
            Find(i);
        }
        Output();
    }
}
