#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN=77, MAXE=222, INF=0x3f3f3f3f;
struct Edge{
    int from, to, next, cap;
    Edge(){}
    Edge(int f, int t, int n, int c):from(f), to(t), next(n), cap(c){}
}edge[MAXE*2];

int src, snk, tot, head[MAXN], dep[MAXN], q[MAXN];

void Init(int s, int t){
    src = s, snk = t;
    tot = 0;
    memset(head, -1, sizeof head);
}
void Add(int u, int v, int c){
    edge[tot] = Edge(u, v, head[u], c);
    head[u] = tot++;
    edge[tot] = Edge(v, u, head[v], 0);
    head[v] = tot++;
}
bool BFS(){
    memset(dep,-1,sizeof dep);
    int rear = 0;
    dep[src] = 0;
    q[rear++] = src;
    for(int i = 0; i < rear; i++){
        int u = q[i];
        for(int p = head[u]; ~p; p=edge[p].next){
            int v = edge[p].to;
            if(dep[v] == -1 && edge[p].cap>0){
                dep[v] = dep[u] + 1;
                q[rear++] = v;
            }
        }
    }
    return dep[snk] != -1;
}
int DFS(int u, int fl){
    int ret;
    if(u == snk) return fl;
    for(int i = head[u]; ~i; i = edge[i].next){
        int v = edge[i].to;
        if(edge[i].cap > 0 && dep[u] != -1 && dep[v] != -1 && dep[v] == dep[u] + 1 && (ret=DFS(v,min(fl,edge[i].cap)))){
            edge[i].cap-=ret;
            edge[i^1].cap+=ret;
            return ret;
        }
    }
    dep[u] = -1;
    return 0;
}
int Dinic(){
    int ret = 0, delta;
    while(BFS()){
        while(1){
            delta = DFS(src,INF);
            if(delta == 0) break;
            ret += delta;
        }
    }
    return ret;
}
int main()
{
//    freopen("data.in", "r", stdin);
    int tcas;
    char str[100], digit[10];
    int score[11],Max[11];
    scanf("%d", &tcas);
    gets(str);
    while(tcas--){
        gets(str);
        int n=0;
        for(int i = 0; str[i] != '\0'; i++){
            int j = 0;
            while('0' <= str[i] && str[i] <= '9'){
                digit[j++] = str[i++];
            }
            digit[j]='\0';
            if(j){
                n++;i--;
                sscanf(digit,"%d",&score[n]);
            }
        }
        sort(score+1, score+n+1);
        memset(Max, 0, sizeof Max);
        for(int i = 1; i <= n; i++)
            for(int j = n; score[j] > score[i]; j--) Max[i]++;
        int source = n*(n-1)/2 + 2*n + 1, sink = n*(n-1)/2 + 2*n + 2;
        int ans = 0;
        for(int sk=n;sk>0;sk--){// sk~n
            Init(source, sink);
            if(score[sk] < Max[sk]) continue;
            for(int i = 1; i <= n; i++){
                Add(i, sink, score[i]);//i 该选手总流量
                if(i>=sk)
                    Add(i+n, i, score[i] - Max[i]);//i' 有这么多流量来自分数小于或等于他的选手
                else
                    Add(i+n, i, score[i]);
            }
            int cnt = n+n+1;
            for(int i = 1; i < n; i++){
                for(int j = i + 1; j <= n; j++){
                    Add(source, cnt, 1);
                    if(i>=sk && score[i]<score[j])
                        Add(cnt++, i, 1);
                    else{
                        Add(cnt, i+n, 1);
                        Add(cnt++, j+n, 1);
                    }
                }
            }
            int tmp = Dinic();
            if(tmp == n*(n-1)/2){
                ans = n-sk+1;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

/*
5
1 2 2 2 3
1 1 3 4 4 4 4
3 3 4 4 4 4 5 6 6 6
0 3 4 4 4 5 5 5 6
0 3 3 3 3 3

2
4
5
3
5
*/
