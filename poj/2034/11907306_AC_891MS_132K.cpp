#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxn 10010
int n,m,d,p,ans[1010];
bool prim[maxn],vis[1010];
bool dfs()
{
    if(p>=2){
        int sum=ans[p-1];
        int k=(p>d?(p-d):0);
        for(int i=p-2; i>=k;i--){
            sum+=ans[i];
            if(prim[sum]) return 0;
        }
    }
    if(p==m-n+1) return 1;
    for(int i=n;i<=m;i++)if(!vis[i]){
        vis[i]=1;
        ans[p++]=i;
        if(dfs())return 1;
        vis[i]=0;
        p--;
    }
    return 0;
}

int main()
{
//    freopen("test.in", "r", stdin);
    int i,j;
    memset(prim,1,sizeof(prim));
    prim[0]=prim[1]=0;
    for(i=2;i<105;i++)
        if(prim[i])
            for(j=i*i; j<maxn; j+=i)
                prim[j]=0;
    while(~scanf("%d%d%d", &n,&m,&d)){
        memset(vis,0,sizeof(vis));
        if(!n && !m && !d) break;
        p=0;
        if(dfs()){
            printf("%d",ans[0]);
            for(i=1;i<=m-n;i++){
                printf(",%d",ans[i]);
            }
            putchar('\n');
        }else
            puts("No anti-prime sequence exists.");
    }
    return 0;
}
