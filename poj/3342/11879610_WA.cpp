#include <stdio.h>
#include <string.h>

struct Node{
    int child[205];
    int cnt;
} a[205];

int dp[205][2];
bool flag[205][2];
char name[205][2][105];
int dfs(int root, int sta)
{
    if(dp[root][sta]!=-1)return dp[root][sta];
    if(sta==1){
        int chid;
        dp[root][1]=1;
        flag[root][1]=1;
        for(int i=0; i<a[root].cnt; i++){
            chid=a[root].child[i];
            dp[root][1]+=dfs(chid,0);
            if(flag[chid][0]==0)
                flag[root][1]=0;
        }
    }else{//sta==0
        int chi0=0,chi1=0,flg0=1,flg1=1,chid;
        dp[root][0]=0;
        for(int i=0; i<a[root].cnt; i++){
            chid=a[root].child[i];
            chi0+=dfs(chid,0);
            chi1+=dfs(chid,1);
            if(flag[chid][0]==0)
                flg0=0;
            if(flag[chid][1]==0)
                flg1=0;
        }
        if(chi0>chi1){
            dp[root][0]=chi0;
            flag[root][0]=flg0;
        }else if(chi0<chi1){
            dp[root][0]=chi1;
            flag[root][0]=flg1;
        }else{//chi0==chi1
            dp[root][0]=chi0;
            flag[root][0]=0;
        }
    }
    return dp[root][sta];
}

int main()
{
    int i,n,j,res1,res2;
    while(scanf("%d", &n)){
        if(!n)break;
        scanf("%s",name[0][0]);
        for(i=1;i<n;i++){
            scanf("%s %s", name[i][0], name[i][1]);
        }
        memset(dp, -1, sizeof(dp));
        memset(a, 0, sizeof(a));
        for(i=1;i<n;i++){
            for(j=0;j<n;j++){
                if(!strcmp(name[i][1], name[j][0])){
                    a[j].child[a[j].cnt++]=i;
                }
            }
        }
        res1=dfs(0,0);
        res2=dfs(0,1);
        if(res1>res2&&flag[0][0]){
            printf("%d Yes\n", res1);
        }else if(res2>res1&&flag[0][1]){
            printf("%d Yes\n", res2);
        }else{
            printf("%d No\n", ((res1>res2)?res1:res2));
        }
    }
    return 0;
}
