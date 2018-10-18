#include <iostream>
#include <cstdio>
using namespace std;

char mp[22][22];
bool color[22][22];
int n;
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
void draw(int x, int y){
    color[x][y]^=1;
    for(int i = 0; i < 4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx<0 || ny<0 || nx>=n || ny>=n) continue;
        color[nx][ny]^=1;
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--){

        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%s", mp[i]);
        }
        int ans = -1;
        for(int cur = (1<<n)-1; cur>=0; cur--){
            int step = 0;
            //initcolor
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(mp[i][j]=='w') color[i][j] = 0;
                    else color[i][j] = 1;
                }
            }
            //first row
            for(int i = 0; i < n; i++){
                if (cur&(1<<i)){
                    draw(0,i);
                    step++;
                }
            }
            //rest row
            for(int i = 1; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(!color[i-1][j]){
                        draw(i,j);
                        step++;
                    }
                }
            }
            int flag = 1;
            for(int j = 0; j < n; j++){
                if(!color[n-1][j]){
                    flag = 0;
                    break;
                }
            }
            if(flag && (ans == -1 || step < ans)){
                ans = step;
            }
        }
        if(ans == -1) printf("inf\n");
        else printf("%d\n", ans);

    }
    return 0;
}
