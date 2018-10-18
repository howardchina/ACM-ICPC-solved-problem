//#include <stdio.h>
//#include <stdlib.h>
//
//int card[100010];
//int good[50010];
//int sto[15];
//
//int comp(const void *a, const void *b) {
//    return *(int *)a - *(int *)b;
//}
//
//int main()
//{
//    int n = 0, k = 0, p = 0, cnt = 0, time = 0;
//    while(~scanf("%d%d%d", &n, &k, &p)) {
//        cnt = 0;
//        time = 0;
//        for(int i = 1; i <= k; i++) {
//            card[i] = i;
//        }
////        printf("start--\n");
////        for(int i = 1; i <= k; i++) {
////            printf("%d\n", card[i]);
////        }
////        puts("end==");
//        for(time = 1; time <= k; time++) {
//            if(!(time%n)) {
//                good[cnt] = card[1];
//                cnt++;
//            }
//            for(int i = 2; i <= k-time+1; i++) {//发牌前总牌数为k-time+1
//                card[i-1] = card[i];
//            }
//            if(p < k-time+1) {
//                for(int i = 1; i <= p; i++) {
//                    sto[i] = card[i];
//                }
//                for(int i = p + 1; i <= k-time; i++) {//洗牌前总牌数为k-time
//                    card[i-p] = card[i];
//                }
//                for(int i = 1; i <= p; i++) {
//                    card[k-time-p+i] = sto[i];
//                }
////                int t = card[p];
////                for(int i = p+1; i <= k+1-time; i++) {
////                    card[i-1] = card[i];
////                }
////                card[k-time] = t;
//            }
////            printf("start--\n");
////            for(int i = 1; i <= k-time; i++) {
////                printf("%d\n", card[i]);
////            }
////            puts("end==");
//        }
//        qsort(good, cnt, sizeof(int), comp);
//        for(int i = 0; i < cnt; i++) {
//            printf("%d\n", good[i]);
//        }
//    }
//    return 0;
//}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct card{
    int i;
    int next;
};

int comp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

card cards[100010];
int good[50000];
int main()
{
    int n = 0, k = 0, p = 0, i = 0, j = 0, pbot = 0, pfol = 0, temp = 0, rebot = 0, cnt = 0;

    while(~scanf("%d%d%d", &n, &k, &p)) {
        memset(cards, 0, sizeof(cards));
        for(i = 1; i <= k; i++) {
            cards[i-1].next = i;
            cards[i].i = i;
        }
        cards[k].next = -1;

//        puts("===start===");
//        for(i = 0; cards[i].next != -1; i = cards[i].next) {
//            printf("%d\n", cards[i].next);
//        }
//        puts("===end===");

        for(i = 1; i <= k; i++) {
            if(!(i%n)) {
                good[cnt++] = cards[cards[0].next].i;
            }
            cards[0].next = cards[cards[0].next].next;

            if(k - i > p) {
                for(j = 1, pbot = cards[0].next; j <= p-1; j++) {
                    pbot = cards[pbot].next;
                }
                pfol = cards[pbot].next;
                cards[pbot].next = -1;
                temp = cards[0].next;
                cards[0].next = pfol;
                rebot = pfol;
                for(j = 1; j <= k-p-i-1; j++) {
                    rebot = cards[rebot].next;
                }
                cards[rebot].next = temp;
            }
//            puts("===start===");
//            for(j = 0; cards[j].next != -1; j = cards[j].next) {
//                printf("%d\n", cards[j].next);
//            }
//            puts("===end===");
        }
        qsort(good, cnt, sizeof(int), comp);
        for(i = 0; i < cnt; i++) {
            printf("%d\n", good[i]);
        }
    }
    return 0;
}





