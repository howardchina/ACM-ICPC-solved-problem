#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const int hx[8] = {-2, -2, 2, 2, -1, 1, -1, 1};
const int hy[8] = {-1, 1, -1, 1, -2, -2, 2, 2};
int eat[22];

struct Piece{
    int x, y;
    char type[5];
}p[22];

int n;

bool check(int x, int y){
    memset(eat, 0, sizeof eat);
    for(int i = 0; i < n; i++){
        if (p[i].x == x && p[i].y == y) eat[i] = 1;
    }
    bool re = 0;
    for(int i = 0; i < n; i++){
        if (eat[i]) continue;
        //判竖的 帅和车
        if ((p[i].type[0] == 'G' || p[i].type[0] == 'R') && p[i].y == y){
            bool flag = 1;
            for (int j = 0; j < n; j++){
                if (i == j || eat[j]) continue;
                if (p[j].y == p[i].y  &&
                    ( (x < p[j].x && p[j].x < p[i].x)
                    ||(x > p[j].x && p[j].x > p[i].x) ) ){
                    flag = 0;
                    break;
                }
            }
            re |= flag;
        }
        //判横的 车
        if (p[i].type[0] == 'R' && p[i].x == x){
            bool flag = 1;
            for (int j = 0; j < n; j++){
                if (i == j || eat[j]) continue;
                if (p[j].x == p[i].x  &&
                    ( (y < p[j].y && p[j].y < p[i].y)
                    ||(y > p[j].y && p[j].y > p[i].y) ) ){
                    flag = 0;
                    break;
                }
            }
            re |= flag;
        }
        //判竖的 炮
        if (p[i].type[0] == 'C' && p[i].y == y){
            int cnt = 0;
            for (int j = 0; j < n; j++){
                if (i == j || eat[j]) continue;
                if (p[j].y == p[i].y  &&
                    ( (x < p[j].x && p[j].x < p[i].x)
                    ||(x > p[j].x && p[j].x > p[i].x) ) ){
                    cnt++;
                }
            }
            re |= cnt==1;
        }
        //判横的  炮
        if (p[i].type[0] == 'C' && p[i].x == x){
            int cnt = 0;
            for (int j = 0; j < n; j++){
                if (i == j || eat[j]) continue;
                if (p[j].x == p[i].x  &&
                    ( (y < p[j].y && p[j].y < p[i].y)
                    ||(y > p[j].y && p[j].y > p[i].y) ) ){
                    cnt++;
                }
            }
            re |= cnt==1;
        }
        //判马
        if (p[i].type[0] == 'H'){
            bool flag = 0;
            for(int k = 0; k < 8; k++){
                if (x == p[i].x + hx[k] && y == p[i].y + hy[k]){
                    bool tflag = 1;
                    for(int j = 0; j < n; j++){
                        if (i == j || eat[j]) continue;
                        if (p[j].x == p[i].x + dx[k/2] && p[j].y == p[i].y + dy[k/2]){
                            tflag = 0;
                            break;
                        }
                    }
                    flag |= tflag;
                }
            }
            re |= flag;
        }
    }
    return re;
}

int main()
{
//    freopen("data.in", "r", stdin);
    int bx, by;
    while(1){
        scanf("%d%d%d", &n, &bx, &by);
        if (n == 0 && bx == 0 && by == 0) break;
        for(int i = 0; i < n; i++){
            scanf("%s%d%d", p[i].type, &p[i].x, &p[i].y);
        }
        int ans = 1;
        for(int i = 0; i < 4; i++){
            if (bx + dx[i] < 1 || bx + dx[i] > 3) continue;
            if (by + dy[i] < 4 || by + dy[i] > 6) continue;
            ans &= check(bx+dx[i], by+dy[i]);
        }
        printf("%s\n", ans?"YES":"NO");
    }

    return 0;
}
