#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<queue>
#include <vector>
using namespace std;

const int maxn=7;

int N,M,K,gotans;

int ans[maxn][maxn];
int col[maxn*maxn];

void dfs(int r,int c){
    if(r>N){
        gotans=true;
        return;
    }
    if(c>M) {
        dfs(r+1,1);
        return;
    }

    int res = N*M-(r-1)*M+(c-1);

    int top = ans[r-1][c];
    int left = ans[r][c-1];
    for(int i=1;i<=K;i++)
        if(col[i]*2-1>res) return;
    for(int i=1;i<=K;i++){
        if(gotans) return;
        if(col[i]){
            if(top!=i && left!=i){
                ans[r][c]=i;
                col[i]--;
                dfs(r,c+1);
                col[i]++;
            }
        }
    }
}

int main()
{
//    freopen("data.in","r",stdin);
    int t;
    scanf("%d",&t);
    for(int ca=1; ca<=t; ca++)
    {
        scanf("%d%d%d",&N,&M,&K);

        for(int i=1;i<=K;i++){
            scanf("%d",&col[i]);
        }
        gotans=false;
        dfs(1,1);
        printf("Case #%d:\n",ca);
        if(gotans){
            puts("YES");
            for(int i=1;i<=N;i++){
                for(int j=1;j<=M;j++){
                    printf("%d%c",ans[i][j],j!=M?' ':'\n');
                }
            }
        }else{
            puts("NO");
        }
    }
}
