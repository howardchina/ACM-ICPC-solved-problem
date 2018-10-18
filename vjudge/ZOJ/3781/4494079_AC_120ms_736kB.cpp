#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>
using namespace std;
typedef long long LL;
const int N = 40 + 10;
char g[N][N];
int n, m;
int vis[N][N];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

set<int>Map[1600 + 10];
struct Edge{int to, nxt;}e[(1610 * 4) << 1];
int head[1610];
int tot;
void initGraph(){
    tot = 0;
    memset(head, 0, sizeof head);
}
void add(int u, int v){
    e[++tot].to = v; e[tot].nxt = head[u]; head[u] = tot;
    e[++tot].to = u; e[tot].nxt = head[v]; head[v] = tot;
}
int sz;
void dfs(int i, int j, char t){
    int x, y;
    for(int k = 0; k < 4; k++){
        x = i + dx[k]; y = j + dy[k];
        int u = sz, v = vis[x][y];
        if (v && g[x][y] != t && !Map[u].count(v)){
            Map[u].insert(v); Map[v].insert(u);
            add(u, v);
        }else if (!v && g[x][y] == t){
            vis[x][y] = sz;
            dfs(x, y, t);
        }
    }
}

int d[1600 + 10];
int bfs(int k){
    int re = 0;
    queue<int>q;
    int x, y;
    memset(d, 0, sizeof d);
    q.push(k);
    d[k] = 1;
    while(!q.empty()){
        x = q.front(); q.pop();
        for(int i = head[x]; i; i = e[i].nxt){
            y = e[i].to;
            if (d[y]) continue;
            q.push(y);
            d[y] = d[x]+1;
            re = max(re, d[y] - 1);
        }
    }
    return re;
}

int main()
{
//    freopen("data.in", "r", stdin);
//    freopen("data.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++){
            scanf("%s", g[i]+1);
        }
        for(int i = 1; i <= n; i++){
            g[i][0] = g[i][m+1] = '#';
        }
        for(int i = 1; i <= m; i++){
            g[0][i] = g[n+1][i] = '#';
        }
        sz = 0;
        memset(vis, 0, sizeof vis);
        for(int i = 0; i < 1610; i++) Map[i].clear();
        initGraph();
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if (vis[i][j]) continue;
                vis[i][j] = ++sz;
                dfs(i, j, g[i][j]);
            }
        }
        int ans = sz;
        for(int i = 1; i <= sz; i++){
            ans = min(ans, bfs(i));
        }
        printf("%d\n", ans);
    }
    return 0;
}
