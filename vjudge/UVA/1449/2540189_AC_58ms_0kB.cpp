#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <map>
using namespace std;
#define Clear(x) memset(x,0,sizeof x)
const int MAX=26,MAXN=20000;

int ch[MAXN][MAX],last[MAXN],f[MAXN],val[MAXN];
int cnt[MAXN],top;
map<string,int>mp;
char str[200][100];
char text[1000001];

void init(){
    top=0;
    Clear(ch[0]);
    mp.clear();
    val[0]=last[0]=f[0]=0;
    Clear(cnt);
}
int NewNode(){
    int x=++top;
    Clear(ch[x]);
    val[x]=last[x]=f[x]=0;
    return x;
}
void insert(char *T,int num){
    int x=0,n=strlen(T);
    for(int i=0;i<n;i++){
        int c=T[i]-'a';
        if(!ch[x][c]) ch[x][c]=NewNode();
        x=ch[x][c];
    }
    val[x]=num;
}
void getFail(){
    queue<int>q;
    f[0]=0;
    for(int c=0;c<MAX;c++){
        int u=ch[0][c];
        if(u){f[u]=last[u]=0;q.push(u);}
    }
    while(!q.empty()){
        int r=q.front(); q.pop();
        for(int c=0;c<MAX;c++){
            int u=ch[r][c];
            if(!u){ch[r][c]=ch[f[r]][c];continue;}
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
//        printf("%d: %d\n",j,val[j]);
        cnt[val[x]]++;
        count(last[x]);
    }
}
void find(char *T){
    int x=0,n=strlen(T);
    for(int i=0;i<n;i++){
        int c=T[i]-'a';
        x=ch[x][c];//!!!
        if(val[x])count(x);
        else if(last[x]) count(last[x]);
    }
}


int main()
{
    int n;
    while(scanf("%d",&n)!=EOF && n){
        init();
        int tot=0;
        for(int i =1;i<=n;i++){
            scanf("%s",str[i]);
            if(mp.count(str[i])==0) mp[str[i]]=++tot;
            insert(str[i],mp[str[i]]);
        }
        getFail();
        scanf("%s",text);
        find(text);

        int k=0;
        for(int i=1;i<=tot;i++)
            k=max(k,cnt[i]);
        printf("%d\n", k);
        for(int i=1;i<=n;i++){
            if(cnt[mp[str[i]]] == k)
                printf("%s\n",str[i]);
        }
    }
    return 0;
}
