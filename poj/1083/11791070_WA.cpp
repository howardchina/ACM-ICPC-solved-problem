#include <stdio.h>
#include <string.h>
int r[200];

void swap(int &x, int &y)
{
    int t;
    t = x;
    x = y;
    y = t;
}

int main()
{
    int T, N, s, t, max;
    scanf("%d", &T);
    while(T--) {
        memset(r, 0, sizeof(r));
        scanf("%d", &N);
        for(int i = 1; i <= N; i++) {
            scanf("%d%d", &s, &t);
            if(s>t) swap(s,t);
            for(int j = (s+1)/2; j < (t+1)/2; j++) {
                r[j]++;
            }
        }
//        for(int i = 1; i <= 200; i++) {
//            printf("%4d", r[i]);
//        }
//        puts("");
        max = r[1];
        for(int i = 1; i <= 200; i++) {
            if(r[i] > max) max = r[i];
        }
        printf("%d\n", max*10);
    }
    return 0;
}
