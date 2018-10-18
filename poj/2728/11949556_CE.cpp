#include<stdio.h>
#include<string.h>
#include<math.h>

#define inf 1000000000.00
#define N 1010
int x[N],y[N],z[N],pre[N],vis[N];
double cst[N][N],len[N][N],maze[N][N],dis[N];
double prim(int n,double mid){
    int i,j,dj;
    double ta=0,tb=0,k;
    for(i=1;i<n;i++)
        for(j=i+1,maze[i][i]=inf;j<=n;j++)
            maze[i][j]=maze[j][i]=cst[i][j]-len[i][j]*mid;
    for(i=1;i<=n;i++)
        pre[i]=1,vis[i]=0,dis[i]=maze[1][i];
    dis[1]=0,vis[1]=1;
    for(i=1;i<n;i++){
        k=inf;
        for(j=1;j<=n;j++)
            if(!vis[j] && k>dis[j]){
                k=dis[j],dj=j;
            }
        ta+=cst[pre[dj]][dj];
        tb+=len[pre[dj]][dj];
        vis[dj]=1;
        for(j=1;j<=n;j++)
            if(!vis[j] && dis[j]>maze[dj][j])
                dis[j]=maze[dj][j],pre[j]=dj;
    }
    return ta/tb;
}
int main(){
//    freopen("test.in","r",stdin);
    int n,i,j;
    double ans,tmp;
    while(scanf("%d",&n)!=-1 && n){
        for(i=1;i<=n;i++)
            scanf("%d%d%d",&x[i],&y[i],&z[i]);
        for(i=1;i<n;i++)
            for(j=i+1,cst[i][i]=len[i][i]=inf;j<=n;j++){
                cst[i][j]=cst[j][i]=(double)fabs(z[i]-z[j]);
                len[i][j]=len[j][i]=sqrt((double)(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
            }
        tmp=1.0,ans=prim(n,tmp);
        while(fabs(ans-tmp)>0.00001){
            tmp=ans,ans=prim(n,tmp);
        }
        printf("%.3lf\n",ans);
    }
    return 0;
}
