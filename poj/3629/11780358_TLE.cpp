#include <stdio.h>
#include <stdlib.h>

int card[100010];
int good[50010];
int sto[15];

int comp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main()
{
    int n = 0, k = 0, p = 0, cnt = 0, time = 0;
    while(scanf("%d%d%d", &n, &k, &p) != EOF) {
        cnt = 0;
        time = 0;
        for(int i = 1; i <= k; i++) {
            card[i] = i;
        }
//        printf("start--\n");
//        for(int i = 1; i <= k; i++) {
//            printf("%d\n", card[i]);
//        }
//        puts("end==");
        for(time = 1; time <= k; time++) {
            if(!(time%n)) {
                good[cnt] = card[1];
                cnt++;
            }
            for(int i = 2; i <= k-time+1; i++) {//发牌前总牌数为k-time+1
                card[i-1] = card[i];
            }
            if(p < k-time+1) {
                for(int i = 1; i <= p; i++) {
                    sto[i] = card[i];
                }
                for(int i = p + 1; i <= k-time; i++) {//洗牌前总牌数为k-time
                    card[i-p] = card[i];
                }
                for(int i = 1; i <= p; i++) {
                    card[k-time-p+i] = sto[i];
                }
//                int t = card[p];
//                for(int i = p+1; i <= k+1-time; i++) {
//                    card[i-1] = card[i];
//                }
//                card[k-time] = t;
            }
//            printf("start--\n");
//            for(int i = 1; i <= k-time; i++) {
//                printf("%d\n", card[i]);
//            }
//            puts("end==");
        }
        qsort(good, cnt, sizeof(int), comp);
        for(int i = 0; i < cnt; i++) {
            printf("%d\n", good[i]);
        }
    }
    return 0;
}
