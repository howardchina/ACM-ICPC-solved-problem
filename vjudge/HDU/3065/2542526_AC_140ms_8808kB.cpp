#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int MAXN=55555,MAX=26,MAXM=2222222;
#define Clear(x) memset(x,0,sizeof x)
int val[MAXN],last[MAXN],f[MAXN],cnt[MAXN],ch[MAXN][MAX],top;
char text[MAXM],P[1111][55];
void init(){
    top=0;
    Clear(val);Clear(last);
    Clear(f);Clear(ch);
}
int NewNode(){return ++top;}
void insert(char *s,int num){
    int x=0,n=strlen(s);
    for(int i=0;i<n;i++){
        int c=s[i]-'A';
        if(!ch[x][c]) ch[x][c]=NewNode();
        x=ch[x][c];
    }
    val[x]=num;
}
void getFail(){
    queue<int>Q;
    for(int c=0;c<MAX;c++){
        int u=ch[0][c];
        if(u) Q.push(u);
    }
    while(!Q.empty()){
        int r=Q.front();Q.pop();
        for(int c=0;c<MAX;c++){
            int u=ch[r][c];
            int v=f[r];
            if(!u){ch[r][c]=ch[v][c];continue;}
            Q.push(u);
            while(v && !ch[v][c]) v=f[v];
            f[u]=ch[v][c];//!!
            last[u]=val[f[u]]?f[u]:last[f[u]];
        }
    }
}
void count(int x){
    if(x){
        cnt[val[x]]++;
        if(last[x])count(last[x]);
    }
}
void find(char *s){
    Clear(cnt);
    int x=0,n=strlen(s);
    for(int i=0;i<n;i++){
        if(s[i]<'A' || s[i]>'Z'){x=0;continue;};
        int c=s[i]-'A';
        x=ch[x][c];
        if(val[x]) count(x);
        else if(last[x]) count(last[x]);
    }
}
int main()
{
//    freopen("data.in","r",stdin);
    int n;
    while(scanf("%d",&n)!=EOF){
        init();
        for(int i=1;i<=n;i++){
            scanf("%s",P[i]);
            insert(P[i],i);
        }
        scanf("%s",text);
        getFail();
        find(text);
        for(int i=1;i<=n;i++)
            if(cnt[i])
                printf("%s: %d\n",P[i],cnt[i]);
    }
    return 0;
}
