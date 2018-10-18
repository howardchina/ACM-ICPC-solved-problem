#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int MAX=128,MAXN=61111;
#define Clear(x) memset(x,0,sizeof x)
int f[MAXN],last[MAXN],cnt[MAXN],val[MAXN],top,ch[MAXN][MAX];
char P[555][222], text[11111],flag;
void init(){
    top=0;
    Clear(ch);Clear(val);
    Clear(last);Clear(f);
}
int NewNode(){
    return ++top;
}
void insert(char *s, int num){
    int x=0,n=strlen(s);
    for(int i=0;i<n;i++){
        int c=s[i];
        if(!ch[x][c]) ch[x][c]=NewNode();
        x=ch[x][c];
    }
    val[x]=num;
}
void getFail(){
    queue<int>q;
    for(int c=0;c<MAX;c++){
        int u=ch[0][c];
        if(u)q.push(u);
    }
    while(!q.empty()){
        int r=q.front(); q.pop();
        for(int c=0;c<MAX;c++){
            int u=ch[r][c];
            if(!u){ch[r][c]=ch[f[r]][c]; continue;}
            q.push(u);
            int v=f[r];
            while(v && !ch[v][c]) v=f[v];
            f[u]=ch[v][c];
            last[u]=val[f[u]]?f[u]:last[f[u]];
        }
    }
}
void count(int x){
    if(x){
        flag=1;
        cnt[val[x]]++;
        if(last[x]) count(last[x]);
    }
}
void find(char *s){
    int x=0,n=strlen(s);
    Clear(cnt);
    for(int i=0;i<n;i++){
        int c=s[i];
        x=ch[x][c];
        if(val[x]) count(x);
        else if(last[x]) count(last[x]);
    }
}
int main()
{
//    freopen("data.in", "r", stdin);
    int n,m;
    while(scanf("%d",&n)!=EOF){
        init();
        for(int i=1;i<=n;i++){
            scanf("%s",P[i]);
            insert(P[i],i);
        }
        getFail();
        scanf("%d",&m);
        int ans=0;
        for(int i=1;i<=m;i++){
            scanf("%s",text);
            flag=0;
            find(text);
            if(flag){
                printf("web %d:",i);
                for(int j=1;j<=n;j++)
                    if(cnt[j]) printf(" %d",j);
                puts("");
                ans++;
            }
        }
        printf("total: %d\n", ans);
    }
    return 0;
}
