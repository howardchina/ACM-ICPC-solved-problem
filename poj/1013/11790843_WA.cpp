#include <stdio.h>
#include <string.h>
#define MAX 20
#define clr(x,a) memset(x,a,sizeof(x))
char l[MAX];
char r[MAX];
bool tru[MAX];
int w[MAX];

int main()
{
    int n, tot, cnt, pos, len;
    char op[6];
    scanf("%d", &n);
    while(n--) {
        clr(l,0); clr(r,0); clr(tru,0); clr(w,0); tot = 0; cnt = 0;
        for(int k = 0; k < 3; k++) {
//            printf("k%d\n", k);
            scanf("%s%s%s", l, r, op);
//            printf("%s %s %s\n", l, r, op);
            len = strlen(l);
//            getchar();
//            scanf("%c", &op);
//            printf("op%c\n", op);
            if(op[0] == 'e') {
                for(int i = 0; i < len; i++) {
                    tru[l[i]-'A'] = true;
                }
                for(int i = 0; i < len; i++) {
                    tru[r[i]-'A'] = true;
                }
            }
            else if(op[0] == 'd') {
                tot++;
                for(int i = 0; i < len; i++) {
                    w[l[i]-'A']++;
                }
                for(int i = 0; i < len; i++) {
                    w[r[i]-'A']--;
                }
            }
            else if(op[0] == 'u') {
                tot++;
                for(int i = 0; i < len; i++) {
                    w[l[i]-'A']--;
                }
                for(int i = 0; i < len; i++) {
                    w[r[i]-'A']++;
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
        for(int i = 0; i < 12; i++) {
            if(tru[i])
                continue;
            if(w[i] == tot || w[i] == 0-tot) {
                pos = i;
                break;
            }
        }
        printf("%c is the counterfeit coin and it is light.\n", pos+'A');
    }
    return 0;
}
