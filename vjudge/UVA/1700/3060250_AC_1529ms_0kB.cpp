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
    int prest=0,st=1<<u,mn=1<<u,mx=1<<(u+1),lb,rb,l,r,mid,step=0;
    while(st!=prest){
        prest=st;
        step++;
        l=0,r=cnt-1,lb=0;
        while(l<=r){
            mid=(l+r)>>1;
            if(a[mid].st<mn) {
                lb=mid;
                l=mid+1;
            }else r=mid-1;
        }
        l=0,r=cnt-1,rb=cnt-1;
        while(l<=r){
            mid=(l+r)>>1;
            if(a[mid].st>mx) {
                rb=mid;
                r=mid-1;
            }else l=mid+1;
        }
        for(int i=lb;i<=rb;i++){
            if((a[i].st | prest) == prest && ((1<<a[i].u)&prest)==0 && g[a[i].u][u]==-1){
                st |= 1<<a[i].u;
                mn = min(mn,1<<a[i].u);
                mx = max(mx,1<<(a[i].u+1));
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
