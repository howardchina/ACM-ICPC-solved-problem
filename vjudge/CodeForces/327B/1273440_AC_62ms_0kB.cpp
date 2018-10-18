#include <stdio.h>

#define MAX 1000000

int main()
{
    int n, i;
    while(~scanf("%d", &n)) {
        for(i = 1; i <= n; i++) {
            if(i != 1) printf(" ");
            printf("%d", i+MAX);
        }
        printf("\n");
    }
}
