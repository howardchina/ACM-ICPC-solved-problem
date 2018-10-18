#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define clr(x,y) memset(x,y,sizeof(x))
using namespace std;
const int N = 220;
const int M = 10010;
const int maxnode = 100000 + 10;
const int SIGMA_SIZE = 128;

char T[M],P[N];
int sz;
int ch[maxnode][SIGMA_SIZE];
int val[maxnode],f[maxnode],last[maxnode];

void init(){ sz=1;clr(ch[0],0); clr(val,0); clr(last,0); }

void insert(char* s, int num){
    int n = strlen(s);
    int u = 0;
    for(int i = 0; i < n; i++){
        int c = s[i];
        if (!ch[u][c]){
            clr(ch[sz], 0);
            val[sz] = 0;
            ch[u][c] = sz++;
        }
        u = ch[u][c];
    }
    val[u] = num;
}

void getFail(){
    queue<int> Q;
    f[0] = 0;
    for(int c = 0; c < SIGMA_SIZE; c++){
        int u = ch[0][c];
        if (u) { Q.push(u); f[u] = 0; }
    }
    while(!Q.empty()){
        int r = Q.front(); Q.pop();
        for(int c = 0; c < SIGMA_SIZE; c++){
            int u = ch[r][c];
            if (!u) { ch[r][c] = ch[f[r]][c]; continue;}
            f[u] = ch[f[r]][c];
            last[u] = val[f[u]] ? f[u] : last[f[u]];
            Q.push(u);
        }
    }
}

int cnt[510];

int solve(char* s){
    clr(cnt,0);
    int n = strlen(s);
    int u = 0, ans = 0;
    for(int i = 0; i < n; i++){
        int c = s[i];
        u = ch[u][c];
        int v = u;
        while(v && !cnt[val[v]]) {
            if (val[v]){
                ans++;
                cnt[val[v]] = 1;
            }
            v = f[v];
        }
    }
    return ans;
}

int main()
{
//    freopen("data.in","r",stdin);
    int n;
    while(scanf("%d",&n) != EOF){
        init();
        for(int i = 1; i <= n;i++){ scanf("%s",P); insert(P,i); };
        getFail();
        int m, re, tot=0; scanf("%d",&m);
        for(int i = 1; i <= m;i++){
            scanf("%s",T);
            re = solve(T);
            if (re){
                tot++;
                printf("web %d:", i);
                for(int j = 0; j < 510; j++){
                    if (cnt[j]) printf(" %d", j);
                }
                printf("\n");
            }
        }
        printf("total: %d\n",tot);
    }
    return 0;
}
