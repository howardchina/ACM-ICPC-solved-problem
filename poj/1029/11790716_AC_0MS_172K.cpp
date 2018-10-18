#include <stdio.h>
#include <string.h>
#define MAX 1010
#define clr(x,a) memset(x,a,sizeof(x))
int cur[MAX];
bool r[MAX];
int w[MAX];

int main()
{
    int n, k, p, tot, cnt, pos;
    char op;
    while(~scanf("%d%d", &n, &k)) {
        clr(cur,0); clr(r,0); clr(w,0); tot = 0; cnt = 0;
        while(k--) {
//            printf("k%d\n", k);
            scanf("%d", &p);
//            printf("p%d\n", p);
            for(int i = 0; i < 2*p; i++) {
                scanf("%d", &cur[i]);
            }
//            puts("cur");
//            for(int i = 0; i < 2*p; i++) {
//                printf("%d", cur[i]);
//            }
//            puts("");
            getchar();
            scanf("%c", &op);
//            printf("op%c\n", op);
            if(op == '=') {
                for(int i = 0; i < 2*p; i++) {
                    r[cur[i]] = true;
                }
            }
            else if(op == '>') {
                tot++;
                for(int i = 0; i < p; i++) {
                    w[cur[i]]++;
                }
                for(int i = p; i < 2*p; i++) {
                    w[cur[i]]--;
                }
            }
            else if(op == '<') {
                tot++;
                for(int i = 0; i < p; i++) {
                    w[cur[i]]--;
                }
                for(int i = p; i < 2*p; i++) {
                    w[cur[i]]++;
                }
            }
        }
//        puts("w");
//        for(int i = 1; i <= n; i++) {
//            printf("%3d", w[i]);
//        }
//        puts("");
//        puts("r");
//        for(int i = 1; i <= n; i++) {
//            printf("%3d", r[i]);
//        }
//        puts("");
        for(int i = 1; i <= n; i++) {
            if(r[i])
                continue;
            if(w[i] == tot || w[i] == 0-tot) {
                cnt++;
                pos = i;
            }
        }
        if(cnt != 1)
            printf("0\n");
        else
            printf("%d\n", pos);
    }
    return 0;
}
