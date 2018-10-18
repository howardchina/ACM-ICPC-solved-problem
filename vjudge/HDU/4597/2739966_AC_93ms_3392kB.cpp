#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int f[25][25][25][25][2];
int a[25],b[25];
int dfs(int u1,int d1,int u2,int d2,int st){
    int &re=f[u1][d1][u2][d2][st];
    if(re!=-1) return re;
    if(u1+1==d1&&u2+1==d2) return re=0;
    if(st==0){
        int mx=0;
        if(u1+1<d1){
            mx=max(dfs(u1+1,d1,u2,d2,1)+a[u1+1],mx);
            mx=max(dfs(u1,d1-1,u2,d2,1)+a[d1-1],mx);
        }
        if(u2+1<d2){
            mx=max(dfs(u1,d1,u2+1,d2,1)+b[u2+1],mx);
            mx=max(dfs(u1,d1,u2,d2-1,1)+b[d2-1],mx);
        }
        return re=mx;
    }
    else{
        int mn=0x3f3f3f3f;
        if(u1+1<d1){
            mn=min(dfs(u1+1,d1,u2,d2,0),mn);
            mn=min(dfs(u1,d1-1,u2,d2,0),mn);
        }
        if(u2+1<d2){
            mn=min(dfs(u1,d1,u2+1,d2,0),mn);
            mn=min(dfs(u1,d1,u2,d2-1,0),mn);
        }
        return re=mn;
    }
}
int main(){
//    freopen("data.in","r",stdin);
    int T,N;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        for(int i=1;i<=N;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<=N;i++)
            scanf("%d",&b[i]);
        memset(f,-1,sizeof f);
        int ans=dfs(0,N+1,0,N+1,0);
        printf("%d\n",ans);
    }
    return 0;
}
