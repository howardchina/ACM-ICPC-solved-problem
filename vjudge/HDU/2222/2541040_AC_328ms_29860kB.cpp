#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <map>
using namespace std;
#define Clear(x) memset(x,0,sizeof x)
const int MAXN=550011,MAX=26,MAXM=1000111;
char P[MAXN][55],text[MAXM];
int f[MAXN],val[MAXN],cnt[MAXN],last[MAXN],ch[MAXN][MAX],top;
map<string,int>mp;
void init(){
    mp.clear();
    top=0;
    Clear(ch[0]);
    val[0]=cnt[0]=last[0]=0;
}
int NewNode(){
    int x=++top;
    Clear(ch[x]);
    val[x]=cnt[x]=last[x]=0;
    return x;
}
void insert(char *s,int id){
    int x=0,n=strlen(s);
    for(int i=0;i<n;i++){
        int c=s[i]-'a';
        if(!ch[x][c]) ch[x][c]=NewNode();
        x=ch[x][c];
    }
    val[x]=id;
}
void getFail(){
    queue<int>q;
    for(int c=0;c<MAX;c++){
        int u=ch[0][c];
        if(u) f[u]=0,last[u]=0,q.push(u);
    }
    while(!q.empty()){
        int r=q.front();q.pop();
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
        cnt[val[x]]++;
        if(last[x]) count(last[x]);
    }
}
void find(char *s){
    int x=0,n=strlen(s);
    for(int i=0;i<n;i++){
        int c=s[i]-'a';
        x=ch[x][c];
        if(val[x]) count(x);
        else if(last[x]) count(last[x]);
    }
}
int main()
{
    int ca,n;
    scanf("%d",&ca);
    while(ca--){
        scanf("%d",&n);
        int tot=0;
        init();
        for(int i=1;i<=n;i++){
            scanf("%s",P[i]);
            if(mp.count(P[i])==0){
                mp[P[i]]=++tot;
                insert(P[i],tot);
            }
        }
        scanf("%s",text);
        getFail();
        find(text);
        int ans=0;
        for(int i=1;i<=n;i++){
            if(cnt[mp[P[i]]]) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
