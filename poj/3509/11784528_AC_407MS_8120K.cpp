#include <stdio.h>
#define MAX 1010

int T[MAX][MAX], G[MAX][MAX], t[4*MAX], g[4*MAX];
int cal(int p, int n)
{
//    puts("intoCAl");
//    printf(("p%d n%d\n"), p, n);
    int r, c, i, j, cnt;

    cnt = 0;
    r = c = p;
    for(; c <= (n-p); c++) {
        t[cnt] = T[r][c];
        g[cnt] = G[r][c];
        cnt++;
    }
    for(; r <= n-p; r++) {
        t[cnt] = T[r][c];
        g[cnt] = G[r][c];
        cnt++;
    }
    for(; c > p; c--) {
        t[cnt] = T[r][c];
        g[cnt] = G[r][c];
        cnt++;
    }
    for(; r > p; r--) {
        t[cnt] = T[r][c];
        g[cnt] = G[r][c];
        cnt++;
    }

//    for(j = 0; j < cnt; j++, i = (i+1)%cnt) {
//        printf("g%d t%d\n", g[j], t[j]);
//    }


    for(i = 0; i < cnt; i++) {
        if(g[i] == t[0]) break;
    }
    if(g[i] != t[0]) return 0;
    for(j = 0; j < cnt; j++, i = (i+1)%cnt) {
//        printf("j%d i%d cnt%d\n", j, i, cnt);
//        printf("g%d t%d\n", g[i], t[j]);
        if(g[i] != t[j]) return 0;
    }
    return 1;
}

int main()
{
    int n, i, j, k, len, flag, cnt;
    cnt = 1;
    while(~scanf("%d", &n)) {
        if(!n) break;
        for(i = 1, k= 1; i <= n; i++) {
            for(j = 1; j <= n; j++) {
                scanf("%d", &G[i][j]);
                T[i][j] = k;
                k++;
            }
        }
        len = n&1?(n+1)/2:n/2;
        flag = 0;
        for(i = 1; i <= len; i++) {
            if(i == len && (n&1)) {
                if(T[i][i] != G[i][i]) flag = 1;
                break;
            }
            if(!cal(i, n)) {
                flag = 1;
                break;
            }
        }
        printf("%d. ", cnt++);
        if(flag) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
