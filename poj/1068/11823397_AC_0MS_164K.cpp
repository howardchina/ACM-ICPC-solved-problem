#include <stdio.h>
int p[50];
int main()
{
    int tcase, n, i, j, has, le, ri;
    scanf("%d", &tcase);
    while(tcase--) {
        scanf("%d", &n);
        le = 0; ri = 0;
        for(i = 0; i < n; i++) {
            scanf("%d", &has);//有has个'('
            for(j = le; j < has; j++) {
                p[j+ri] = -1;
                le++;
            }
            p[le+ri] = 1;
            ri++;
        }
//        for(i = 0; i < le+ri; i++) {
//            printf("%d", p[i]);
//        }
//        puts("");
        for(i = 0; i < le+ri; i++) {
            if(p[i] == 1) {
                int sum = 1;
                for(j = i-1; ;j--) {
                    sum+=p[j];
                    if(sum == 0)
                        break;
                }
                if(i != le+ri-1)
                    printf("%d ", (i-j+1)/2);
                else
                    printf("%d", (i-j+1)/2);
            }
        }
        puts("");
    }
    return 0;
}
