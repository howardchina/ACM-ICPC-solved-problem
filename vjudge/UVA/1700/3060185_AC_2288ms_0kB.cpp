#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1111111;
struct Node{
    int st,u;
    bool operator <(const Node&rhs)const{
        return st<rhs.st;
    }
}a[maxn];

int in(){
    int x=0;
    char c;
    do{
        c=getchar();
    }while(c<'a' || c>'z');
    if(c==EOF)return 0;
    while('a'<=c && c<='z'){
        x|=1<<(c-'a');
        c=getchar();
    }
    return x;
}

int g[25][25],n,cnt;
void bfs(int u){
    for(int i=0;i<n;i++)
        g[i][u]=-1;
    g[u][u]=0;
    int prest=0,st=1<<u,mn=1<<u,mx=1<<u,step=0;
    while(st!=prest){
        prest=st;
        step++;
        for(int i=0;i<cnt;i++){
            if((a[i].st | prest) == prest && ((1<<a[i].u)&prest)==0 && g[a[i].u][u]==-1){
                st |= 1<<a[i].u;
                mn = min(mn,1<<a[i].u);
                mx = max(mx,1<<a[i].u);
                g[a[i].u][u]=step;
            }
        }
    }
}
int main()
{
//    freopen("data.in","r",stdin);
    int m;
    while(scanf("%d",&n)!=EOF && n){
        cnt=0;
        for(int i=0;i<n;i++){
            scanf("%d",&m);
            while(m--){
                a[cnt].st=in();
                a[cnt++].u=i;
            }
        }
        sort(a,a+cnt);
        for(int i=0;i<n;i++)
            bfs(i);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                printf("%d%c",g[i][j],(j!=n-1)?' ':'\n');
    }
    return 0;
}
