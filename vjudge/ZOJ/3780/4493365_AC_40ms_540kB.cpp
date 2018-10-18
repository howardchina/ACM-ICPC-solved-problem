#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
const int N = 500 + 10;
char g[N][N];
int R[N][2], C[N][2];
int ans[N<<1];
int n;

void Debug(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            putchar(g[i][j]);
        }
        printf("\n");
    }
    puts("");
}

int main()
{
//    freopen("data.in", "r", stdin);
//    freopen("data.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%s", g[i]+1);
        }
        memset(R, 0, sizeof R);
        memset(C, 0, sizeof C);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                R[i][g[i][j]=='X']++;
                C[j][g[i][j]=='X']++;
            }
        }
        int cnt = 0;
//        Debug();
        while(1){
            int flag = false;
            for(int i = n; i >= 1; i--){
                if (R[i][1] && R[i][0] == 0){
                    flag = true;
                    R[i][1] = 0;
                    ans[cnt++] = i;
                    for(int j = 1; j <= n; j++){
                        if (g[i][j] == 'X'){
                            g[i][j] = '#';
                            C[j][1]--;
                        }
                    }
                }
            }
//            Debug();
            if (flag) continue;
            for(int i = n; i >= 1; i--){
                if (C[i][0] && C[i][1] == 0){
                    flag = true;
                    C[i][0] = 0;
                    ans[cnt++] = n + i;
                    for(int j = 1; j <= n; j++){
                        if (g[j][i] == 'O'){
                            g[j][i] = '#';
                            R[j][0]--;
                        }
                    }
                }
            }
//            Debug();
            if (!flag) break;
        }
        int flag = false;
        for (int i = 1; i <= n; i++){
            if (R[i][0] || R[i][1] || C[i][0] || C[i][1]){
                flag = true;
                break;
            }
        }
        if (flag) puts("No solution");
        else{
            for(int i = cnt-1; i >= 0; i--){
                printf("%c%d%c", ans[i]>n?'C':'R', ans[i]>n?ans[i]-n:ans[i], i>0?' ':'\n');
            }
        }
    }

    return 0;
}
