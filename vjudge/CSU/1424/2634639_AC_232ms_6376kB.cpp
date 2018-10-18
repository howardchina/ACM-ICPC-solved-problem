#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

char a[1001][1001];
int dp[1001][1001];
int main(){
    int n,m;
    char c;
    while(scanf("%d%d",&n,&m)==2){
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++){
                do{
                    c=getchar();
                }while(c!='0' && c!='1');
                a[i][j]=c;
            }
        int ans=0;
        for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++){
            if(a[i][j]=='1'){
                dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
                if(ans<dp[i][j])ans=dp[i][j];
            }else
                dp[i][j]=0;
        }
        printf("%d\n",ans*ans);
    }
    return 0;
}
