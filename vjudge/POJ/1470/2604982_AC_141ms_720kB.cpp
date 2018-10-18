#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN=1111;
struct Edge{
    int from,to,next;
    Edge(){}
    Edge(int f,int t,int n):from(f),to(t),next(n){}
}edge[MAXN];
int n,ans[MAXN],dep[MAXN],fa[MAXN][20],tot,head[MAXN],q[MAXN],fuck[MAXN];
void init(){
    for(int i=1;i<=n;i++){
        head[i]=-1;
        fuck[i]=ans[i]=0;
    }
    tot=0;
}
void add(int f,int t){
    edge[tot]=Edge(f,t,head[f]);
    head[f]=tot++;
}
void bfs(int root){
    fa[root][0]=root;dep[root]=0;
    int tail=0;
    q[tail++]=root;
    for(int i=0;i<tail;i++){
        int u=q[i];
        for(int i=1;i<20;i++)fa[u][i]=fa[fa[u][i-1]][i-1];
        for(int i=head[u];~i;i=edge[i].next){
            int v=edge[i].to;if(v==fa[u][0])continue;
            dep[v]=dep[u]+1;fa[v][0]=u;
            q[tail++]=v;
        }
    }
}
int Lca(int x,int y){
    if(dep[x]<dep[y])swap(x,y);
    for(int i=19;~i;i--)if((dep[x]-dep[y])&(1<<i))x=fa[x][i];
    if(x==y)return x;
    for(int i=19;~i;i--)if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
    return fa[x][0];
}
inline bool get(int &a){
    char c;
    do{
        c=getchar();
    }while(c!= EOF && (c<'0'||c>'9'));
    if(c==EOF)return false;
    a=0;
    while('0'<=c && c<='9') {a=a*10+(c-'0');c=getchar();}
    return true;
}
inline void ot(int a){
    if(a>9)
        ot(a/10);
    putchar(a%10+'0');
}
int main()
{
//    freopen("data.in","r",stdin);
    int u,cnt,v;
    while(get(n)){
        init();
        for(int i=1;i<=n;i++){
            get(u);
            get(cnt);
            for(int j=1;j<=cnt;j++){
                get(v);
                add(u,v);
                fuck[v]++;
            }
        }
        for(int i=1;i<=n;i++)
            if(!fuck[i])bfs(i);
        get(cnt);
        while(cnt--){
            get(u);
            get(v);
            ans[Lca(u,v)]++;
        }
        for(int i=1;i<=n;i++){
            if(ans[i]){
                ot(i);
                putchar(':');
                ot(ans[i]);
                putchar('\n');
            }
        }
    }
    return 0;
}
