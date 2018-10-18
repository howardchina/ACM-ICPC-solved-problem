#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1111;

struct Node{
    int x,y,r,p,q,d;
}a[maxn];

int n;
int vis[maxn],g[maxn][maxn];

int Abs(int x){
    if(x>0)return x;
    return -x;
}

bool touch(int i,int j){
    int x = Abs(a[i].x-a[j].x);
    int y = Abs(a[i].y-a[j].y);
    int r = a[i].r+a[j].r;
    return x*x+y*y==r*r;
}

void init(){
    memset(vis,0,sizeof vis);
    memset(g,0,sizeof g);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(touch(i,j)) g[i][j]=g[j][i]=1;
        }
    }
}

void dfs(int i,int p,int q,int d){
    vis[i]=1;
    a[i].p=p;
    a[i].q=q;
    a[i].d=d;
    for(int j=0;j<n;j++){
        if(g[i][j] && !vis[j]){
            int gcd = __gcd(p*a[i].r,q*a[j].r);
            dfs(j,p*a[i].r/gcd,q*a[j].r/gcd,-d);
        }
    }

}

int main()
{
//    freopen("data.in","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].r);
        }
        init();
        dfs(0,1,1,1);
        for(int i=0;i<n;i++){
            if(vis[i]){
                if(a[i].q==1){
                    printf("%d ",a[i].p);
                }else{
                    printf("%d/%d ",a[i].p,a[i].q);
                }
                printf("%s\n",a[i].d==1?"clockwise":"counterclockwise");
            }else{
                puts("not moving");
            }
        }
    }
    return 0;
}
