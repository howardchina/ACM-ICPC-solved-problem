#include <stdio.h>
#include <string.h>
#define max(a,b) ((a)>(b)?(a):(b))
char str[110];
int dp[110][110];
int dfs(int l, int r)
{
    if(l>r) return 0;
    if(l==r) return dp[l][r]=0;
    if(dp[l][r]>=0) return dp[l][r];
    if((str[l]=='('&&str[r]==')')||(str[l]=='['&&str[r]==']'))
        dp[l][r]=max(dp[l][r],dfs(l+1,r-1)+2);
    for(int i=l; i<=r; i++){
        dp[l][r]=max(dp[l][r],dfs(l,i)+dfs(i+1,r));
    }
    return dp[l][r];
}
int main()
{
//    freopen("test.in","r",stdin);
    int len;
    while(gets(str+1)){
        if(str[1]=='e')break;
        len=0;
        while(str[1+len]) len++;
        memset(dp,-1,sizeof(dp));
        printf("%d\n",dfs(1,len));
    }
    return 0;
}
