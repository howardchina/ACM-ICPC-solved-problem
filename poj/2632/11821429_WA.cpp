#include <stdio.h>
#include <string.h>
int h[110][110];
char dir[4] = {'N', 'E', 'S', 'W'};
//char dir[110][110];
struct Node{
    int x, y;
    char dir;
} r[110];
int main()
{
//    freopen("data.in", "r", stdin);
//    freopen("data1.out", "w", stdout);
    int K, A, B, N, M, flag;
    scanf("%d", &K);
    while(K--) {
        memset(h, false, sizeof(h));
        scanf("%d%d", &A, &B);
        scanf("%d%d", &N, &M);
        for(int i = 1; i <= N; i++) {
            scanf("%d %d %c", &r[i].x, &r[i].y, &r[i].dir);
            h[r[i].x][r[i].y] = i;
        }
        flag = 1;
        for(int i = 1; i <= M; i++) {
            int id, rep;
            char act;
            scanf("%d %c %d", &id, &act, &rep);
            if(flag == 0) continue;
            if(act == 'F') {
                int xs, xd; xs = xd = r[id].x;
                int ys, yd; ys = yd = r[id].y;
                if(r[id].dir == 'N') {
                    yd += rep;
                } else if(r[id].dir == 'E') {
                    xd += rep;
                } else if(r[id].dir == 'S') {
                    yd -=rep;
                } else { //'W'
                    xd -= rep;
                }
                for(int j = xs; flag && j <= ((xd>A)?A:xd); j++) {
                    for(int k = ys; flag && k <= ((yd>B)?B:yd); k++) {
                        if(h[j][k] != 0 && h[j][k] != id) {
                            flag = 0;
                            printf("Robot %d crashes into robot %d\n", id, h[j][k]);
                        }
                    }
                }
                if(flag && (xd <= 0 || xd >= A+1 || yd <= 0 || yd >= B+1)) {
                    flag = 0;
                    printf("Robot %d crashes into the wall\n", id);
                }
                r[id].x = xd; r[id].y = yd;
                h[xs][ys] = 0; h[xd][yd] = id;
            } else if(act == 'L') {
                for(int j = 0; j < 4; j++) {
                    if(dir[j] == r[id].dir) {
                        r[id].dir = dir[(j-rep+400000)%4];
                    }
                }
            } else {//'R'
                for(int j = 0; j < 4; j++) {
                    if(dir[j] == r[id].dir) {
                        r[id].dir = dir[(j+rep)%4];
                    }
                }
            }
        }
        if(flag==1) puts("OK");
    }
    return 0;
}
