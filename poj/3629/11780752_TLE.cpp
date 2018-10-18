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

    scanf("%d%d%d", &n, &k, &p);
    memset(cards, 0, sizeof(cards));
    for(i = 1; i <= k; i++) {
        cards[i-1].next = i;
        cards[i].i = i;
    }
    cards[k].next = -1;


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

    }
    qsort(good, cnt, sizeof(int), comp);
    for(i = 0; i < cnt; i++) {
        printf("%d\n", good[i]);
    }

    return 0;
}





