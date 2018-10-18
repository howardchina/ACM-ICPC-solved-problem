#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 1111;
vector<int> v[maxn];

int d[maxn];
int q[maxn];
int n;
int bfs(int s){
    memset(d, -1, sizeof d);
    d[s] = 0;
    int tail = 0;
    q[tail++] = s;
    int cnt = 0;
    int ans = 0;
    for(int i = 0; i < tail; i++){
        int x = q[i];

        ans = max(ans, d[x]);
        cnt++;

        int sz = v[x].size();
        for(int j = 0; j < sz; j++){
            int y = v[x][j];
            if (d[y] != -1) continue;
            d[y] = d[x] + 1;
            q[tail++] = y;
        }
    }
    if (cnt != n) return -1;
    return ans;
}

int main()
{
//    freopen("data.in", "r", stdin);
    int m, ans;
    while(1){
        scanf("%d", &n);
        if (!n) break;
        map<string, int> mp;
        char s[22], s1[22];
        for(int i = 1; i <= n; i++){
            scanf("%s", s);
            mp[s] = i;
        }
        scanf("%d", &m);
        for(int i = 1; i <= n; i++) v[i].clear();
        int x, y;
        for(int i = 0; i < m; i++){
            scanf("%s%s", s, s1);
            x = mp[s];
            y = mp[s1];
            v[x].push_back(y);
            v[y].push_back(x);
        }
        ans = 1;
        for(int i = 1; i <= n; i++){
            int t = bfs(i);
            if (t == -1){
                ans = -1;
                break;
            }
            else{
                ans = max(ans, t);
            }
        }

        printf("%d\n", ans);
    }


    return 0;
}
