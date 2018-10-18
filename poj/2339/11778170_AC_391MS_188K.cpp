#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
char toda[105][105];
char tomo[105][105];
int main()
{
    int t = 0, r = 0, c = 0, n = 0, i = 0, j = 0;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d", &r, &c, &n);
        for(i = 0; i < r; i++) {
            scanf("%s", toda[i]);
        }
        for(i = 0; i < r; i++) {
            for(j = 0; j < c; j++) {
                tomo[i][j] = toda[i][j];
            }
        }
//        for(i = 0; i < r; i++) {
//            for(j = 0; j < c; j++) {
//                printf("%c", toda[i][j]);
//            }
//            printf("\n");
//        }
        while(n--) {
            for(i = 0; i < r; i++) {
                for(j = 0; j < c; j++) {
                    if(toda[i][j] == 'R') {
                        if(j+1 < c && toda[i][j+1] == 'S')
                            tomo[i][j+1] = 'R';
                        if(i-1 >= 0 && toda[i-1][j] == 'S')
                            tomo[i-1][j] = 'R';
                        if(j-1 >= 0 && toda[i][j-1] == 'S')
                            tomo[i][j-1] = 'R';
                        if(i+1 < r && toda[i+1][j] == 'S')
                            tomo[i+1][j] = 'R';
                    }
                    else if(toda[i][j] == 'S') {
                        if(j+1 < c && toda[i][j+1] == 'P')
                            tomo[i][j+1] = 'S';
                        if(i-1 >= 0 && toda[i-1][j] == 'P')
                            tomo[i-1][j] = 'S';
                        if(j-1 >= 0 && toda[i][j-1] == 'P')
                            tomo[i][j-1] = 'S';
                        if(i+1 < r && toda[i+1][j] == 'P')
                            tomo[i+1][j] = 'S';
                    }
                    else {
                        if(j+1 < c && toda[i][j+1] == 'R')
                            tomo[i][j+1] = 'P';
                        if(i-1 >= 0 && toda[i-1][j] == 'R')
                            tomo[i-1][j] = 'P';
                        if(j-1 >= 0 && toda[i][j-1] == 'R')
                            tomo[i][j-1] = 'P';
                        if(i+1 < r && toda[i+1][j] == 'R')
                            tomo[i+1][j] = 'P';
                    }
                }
            }
            for(i = 0; i < r; i++) {
                for(j = 0; j < c; j++) {
                    toda[i][j] = tomo[i][j];
                }
            }
        }
        for(i = 0; i < r; i++) {
            for(j = 0; j < c; j++) {
                printf("%c", toda[i][j]);
            }
            printf("\n");
        }
        if(n) printf("\n");
    }
    return 0;
}
