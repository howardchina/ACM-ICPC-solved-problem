#include <stdio.h>
#include <bitset>
#include <iostream>
using namespace std;
bitset<110>a;

int main()
{
    int n, i, j, k, in;
    unsigned int max;
    while(~scanf("%d", &n)) {
        a.reset();
        for(i = 0; i < n; i++) {
            scanf("%d", &in);
            if(in) a.set(i);
        }
//        for(i = 0; i < n; i++) {
//            printf("%d", a.test(i));
//        }
//        printf("\n");
        max = 0;
//        printf("max %d\n", max);
        for(i = 0; i < n; i++) {
            for(j = i; j < n; j++) {
                for(k = i; k <= j; k++) {
                    a.flip(k);
                }
//                for(k = 0; k < n; k++) {
//                    printf("%d", a.test(k));
//                }
//                printf("\n");
                max = (max > a.count())?max:a.count();
//                printf("max %d\n", max);
                for(k = i; k <= j; k++) {
                    a.flip(k);
                }
            }
        }
        printf("%d\n", max);

    }
    return 0;
}
