#include <stdio.h>
#include <stack>
#include <string.h>
#define clr(x,y) memset(x, y, sizeof(x))
#define legal(x,y) (x>=1&&x<=y)
using namespace std;

char che[505][505];
bool vis[505][505];
int x1[4] = {0, 0, -1, 1};
int y1[4] = {-1, 1, 0, 0};
int n, m;

struct node{
    int x, y;
    bool f;
    node(){}
    node(int xx, int yy, bool first){
        x = xx; y = yy; f = first;
    }
};
stack<node>ns;

void dfs(int x, int y)
{
//    printf("%d %d\n", x, y);
    int xx, yy;
    for(int i = 0; i < 4; i++) {
        xx = x + x1[i]; yy = y + y1[i];
        if(legal(xx,n) && legal(yy,m) && !vis[xx][yy] && che[xx][yy]=='.') {
            vis[xx][yy] = true;
            ns.push(node(xx, yy, false));
            dfs(xx, yy);
        }
    }
}

int main()
{
    int k;
    while(~scanf("%d%d", &n, &m)) {
        getchar();
        for(int i = 1; i <= n; i++) {
            gets(che[i]+1);
        }
        clr(vis,false);
        k = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(!vis[i][j] && che[i][j]=='.') {
                    k -= 2;
                    vis[i][j] = true;
                    ns.push(node(i, j, true));
                    dfs(i, j);
                }
            }
        }
        k += 3*ns.size();
        printf("%d\n", k);
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(vis[i][j]) printf("B %d %d\n", i, j);
            }
        }
        node tn;
        while(!ns.empty()) {
            tn = ns.top(); ns.pop();
            if(!tn.f) {
                printf("D %d %d\n", tn.x, tn.y);
                printf("R %d %d\n", tn.x, tn.y);
            }
        }
    }
    return 0;
}
