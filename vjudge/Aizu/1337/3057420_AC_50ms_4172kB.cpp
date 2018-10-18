#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
const int maxn = 555;
int l[maxn],r[maxn],t[maxn],b[maxn];
int X[maxn],Y[maxn],g[maxn][maxn];
map<int,int>mpx;
map<int,int>mpy;
int N,M;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
void dfs(int i,int j){
    g[i][j]=1;
    for(int k=0;k<4;k++){
        int x=i+dx[k],y=j+dy[k];
        if(x<0 || x>N || y<0 || y>M) continue;
        if(!g[x][y]){
            dfs(x,y);
        }
    }
}

int main()
{
//    freopen("data.in","r",stdin);
    int n;
    while(scanf("%d",&n)!=EOF && n){
        for(int i=0;i<n;i++){
            scanf("%d%d%d%d",&l[i],&t[i],&r[i],&b[i]);
            X[i]=l[i];
            X[i+n]=r[i];
            Y[i]=t[i];
            Y[i+n]=b[i];
        }
        mpx.clear();
        mpx.clear();
        sort(X,X+n*2);
        sort(Y,Y+n*2);
        int t1=unique(X,X+n*2)-X;
        int t2=unique(Y,Y+n*2)-Y;
        for(int i=0;i<t1;i++)
            mpx[X[i]]=(i+1)*2;
        for(int i=0;i<t2;i++)
            mpy[Y[i]]=(i+1)*2;
        t1=(t1+1)*2+2;
        t2=(t2+1)*2+2;
        memset(g,0,sizeof g);
        for(int i=0;i<n;i++){
            int lb=mpx[l[i]],rb=mpx[r[i]],tb=mpy[t[i]],bb=mpy[b[i]];
//            printf("%d %d %d %d\n",lb,rb,tb,bb);
            for(int j=lb;j<=rb;j++)
                g[tb][j]=g[bb][j]=1;
            for(int j=bb;j<=tb;j++)
                g[j][lb]=g[j][rb]=1;
        }
        int ans=0;
        N=t2,M=t1;
        for(int i=0;i<=N;i++){
            for(int j=0;j<=M;j++){
                if(!g[i][j]){
                    dfs(i,j);
                    ans++;
                }
            }
        }
        printf("%d\n",ans);
    }

    return 0;
}
