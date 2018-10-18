#include <stdio.h>
#include <string.h>
struct Node{
    int x, y;
    char dir;
} robot[110];
int grid[110][110];
char dir[4] = {'N', 'E', 'S', 'W'};
int K, A, B, N, M, flag;
void myF()
{
    for(int i = 1; i <= N; i++) {
        printf("robot%d x%d y%d dir%c\n", i, robot[i].x, robot[i].y, robot[i].dir);
    }
    puts("grid");
    for(int i = B; i >= 1; i--) {
        for(int j = 1; j <= A; j++) {
            printf("%d ", grid[j][i]);
        }
        puts("");
    }
}

int main()
{
    scanf("%d", &K);
    while(K--) {
        memset(grid, false, sizeof(grid));
        scanf("%d%d", &A, &B);
        scanf("%d%d", &N, &M);
        for(int i = 1; i <= N; i++) {
            scanf("%d %d %c", &robot[i].x, &robot[i].y, &robot[i].dir);
            grid[robot[i].x][robot[i].y] = i;
        }

//        myF();

        flag = 1;
        for(int i = 1; i <= M; i++) {
            int id, rep;
            char act;
            scanf("%d %c %d", &id, &act, &rep);
            if(flag == 0) continue;
            if(act == 'F') {
                int xs, xd; xs = xd = robot[id].x;
                int ys, yd; ys = yd = robot[id].y;
                for(int j = 0; j < rep; j++) {
                    if(robot[id].dir == 'N') {
                        yd ++;
                    } else if(robot[id].dir == 'E') {
                        xd ++;
                    } else if(robot[id].dir == 'S') {
                        yd --;
                    } else { //'W'
                        xd --;
                    }
                    if(xd == 0 || xd == A+1 || yd == 0 || yd == B+1) {
                        flag = 0;
                        printf("Robot %d crashes into the wall\n", id);
                        break;
                    }
                    if(grid[xd][yd] != 0 && grid[xd][yd] != id) {
                        flag = 0;
                        printf("Robot %d crashes into robot %d\n", id, grid[xd][yd]);
                        break;
                    }
                }
                if(flag != 0) {
                    robot[id].x = xd; robot[id].y = yd;
                    grid[xs][ys] = 0; grid[xd][yd] = id;
                }
            } else if(act == 'L') {
                for(int j = 0; j < 4; j++) {
                    if(dir[j] == robot[id].dir) {
                        robot[id].dir = dir[(j+3*rep)%4];
                    }
                }
            } else {//'R'
                for(int j = 0; j < 4; j++) {
                    if(dir[j] == robot[id].dir) {
                        robot[id].dir = dir[(j+rep)%4];
                    }
                }
            }
//            myF();
        }
        if(flag==1) puts("OK");
    }
    return 0;
}
