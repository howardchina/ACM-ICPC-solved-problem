#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

int hash[1000000];
char str[20];
int main()
{
    int n = 0, t = 0, len = 0, cnt = 0;
    while(~scanf("%d", &n)) {
        memset(hash, 0, sizeof(hash));
        t = n;
        cnt = 0;
//        printf("   Num     4   square     6 or few\n");
        while(true) {
            if(hash[t]) {
                printf("%d %d %d\n", t, cnt - hash[t] + 1, cnt);
                break;
            }

//            printf("%7d", t);

            cnt++;
            hash[t] = cnt;
            t /= 10;
            t %= 10000;

//            printf("  %4d", t);

            t = t * t;

//            printf("  %8d", t);

            len = sprintf(str, "%d", t);
            if(len > 2) {
                str[0] = '0';
                str[1] = '0';
                t = atoi(str);
            }

//            printf("%7d\n", t);

//            printf("%s\n", str);

        }
    }
    return 0;
}
