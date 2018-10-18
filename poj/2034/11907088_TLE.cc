#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxn 10010

int n,m,d;
bool prim[maxn];
int flag[1010][2];
int check[1010];
int comp(const void *_a, const void *_b)
{
    int *a=(int *)_a;
    int *b=(int *)_b;
    return a[1]-b[1];
}
void GetPrim()
{
    int i,j;
    for(i=0;i<maxn;i++) prim[i]=0;
    prim[0]=prim[1]=1;
    for(i=2;i<105;i++){
        if(!prim[i])
            for(j=i*i; j<maxn; j+=i){
                prim[j]=1;
            }
    }
}
bool dfs(int x,int de)
{
    int i,j,k,sum;
    bool legal=1;
    flag[x][0]=x;flag[x][1]=de;
    for(i=0;i<1000;i++){
        check[i]=check[i+1];
    }
    check[1000]=x;
    for(i=1000-d+1;i<=1000-1;i++)if(!legal)break;else{
        if(check[i]==0) continue;
        for(j=2;j<=d;j++)if(!legal)break;else{
            sum=0;
            for(k=0;k<j;k++){
                if(i+k<=1000)
                    sum+=check[i+k];
            }
            if(!prim[sum]){
                legal=0;break;
            }
        }
    }
    if(de==1 || legal){
        if(de==m-n+1) return 1;
        for(i=n;i<=m;i++) if(!flag[i][0]){
            if(dfs(i,de+1)) return 1;
        }
    }
    flag[x][0]=0;flag[x][1]=0;
    for(i=1000;i>0;i--){
        check[i]=check[i-1];
    }
    return 0;
}

int main()
{
    //freopen("test.in", "r", stdin);
    int i;
    GetPrim();
    while(~scanf("%d%d%d", &n,&m,&d)){
        if(!n && !m && !d) break;
        for(i=n;i<=m;i++){
            memset(check, 0, sizeof(check));
            memset(flag,0,sizeof(flag));
            if(dfs(i,1))break;
        }
        if(i==m+1){
            puts("No anti-prime sequence exists.");
        }else{
            qsort(flag+n, m-n+1, sizeof(flag[0]), comp);
            for(i=n;i<=m;i++){
                if(i!=n) putchar(',');
                printf("%d",flag[i][0]);
            }
            putchar('\n');
        }
    }
return 0;
}