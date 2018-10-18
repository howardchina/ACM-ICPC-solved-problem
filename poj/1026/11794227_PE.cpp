#include <stdio.h>
#include <string.h>
#define MAX 210
int a[MAX], r[MAX];
char dc[MAX], ec[MAX];

int main()
{
    int n, i, k;
    while(scanf("%d", &n) && n) {
        for(i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        for(i = 1; i <= n; i++) {
            int temp = i, min = 0;
            do{
                temp = a[temp];
                min++;
            }while(i != temp);
            r[i] = min;
        }
        while(scanf("%d", &k) && k) {
            gets(dc);
            for(i = strlen(dc); i <= n; i++)
                dc[i] = ' ';
            dc[n+1] = '\0';
            for(i = 1; i <= n; i++) {
                int temp = k%r[i];
                int pos = i;
                for(int j = 1; j <= temp; j++) {
                    pos = a[pos];
                }
                ec[pos] = dc[i];
            }
            ec[n+1] = '\0';
            printf("%s\n", ec+1);
        }
    }
    return 0;
}
