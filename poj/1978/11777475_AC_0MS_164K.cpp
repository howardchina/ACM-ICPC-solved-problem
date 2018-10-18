#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

struct card{
    int i;
};

card cards[60];
card t[60];

int main()
{
    int n = 0, r = 0, p = 0, c = 0;
    while(scanf("%d%d", &n, &r)) {
        if(!n && !r) break;
        for(int i = 1; i <= n; i++) {
            cards[i].i = n-i+1;
        }
        for(int i = 1; i <= r; i++) {
            scanf("%d%d", &p, &c);
            for(int j = 1; j <= c; j++) { //抽牌
                t[j] = cards[p+j-1];
            }
            for(int j = p-1; j >= 1; j--) { //顶牌下落
                cards[j+c] = cards[j];
            }
            for(int j = 1; j <= c; j++) { //放顶牌
                cards[j] = t[j];
            }
        }
        printf("%d\n", cards[1].i);
    }

    return 0;
}
