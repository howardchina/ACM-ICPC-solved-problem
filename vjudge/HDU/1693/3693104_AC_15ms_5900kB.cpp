#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long LL;
int const maxn = 12;
int g[maxn][maxn];
LL dp[maxn][maxn][1<<maxn];
int n,m;

void read(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&g[i][j]);
        }
    }
}

LL solve(){
    read();
    dp[0][m][0]=1;
    for(int i=1;i<=n;i++){
        for(int k=(1<<m)-1;k>=0;k--){
            dp[i][0][k<<1]=dp[i-1][m][k];
        }
        for(int j=1;j<=m;j++){
            int b=1<<(j-1);
            int r=1<<j;
            for(int k=(1<<(m+1))-1;k>=0;k--){
                if(g[i][j]){
                    if(j!=m){
                        if((r&k) && (b&k)){//下方和右方都有插头
                            dp[i][j][k]=dp[i][j-1][k^b^r];
                        }else if((r&k) || (b&k)){//下方或右方一方有插头
                            dp[i][j][k]=dp[i][j-1][k]+dp[i][j-1][k^b^r];
                        }else{//下方和右方都没插头
                            dp[i][j][k]=dp[i][j-1][k^b^r];
                        }
                    }else if(!(r&k)){
                        if(b&k){
                            dp[i][j][k]=dp[i][j-1][k]+dp[i][j-1][k^b^r];
                        }else{
                            dp[i][j][k]=dp[i][j-1][k^r^b];
                        }
                    }else{
                        dp[i][j][k]=0;
                    }

                }else{
                    if((r&k)||(b&k)){//下方或右方有插头
                        dp[i][j][k]=0;
                    }else{//没有插头
                        dp[i][j][k]=dp[i][j-1][k];
                    }
                }
//                if(dp[i][j][k]){
//                    printf("dp[%d][%d][%d]=%I64d\n",i,j,k,dp[i][j][k]);
//                }
            }
        }
    }
    return dp[n][m][0];
}

int main(){
//    freopen("data.in","r",stdin);
//    freopen("data1.out","w",stdout);
    int T;
    LL ans;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++){
        ans = solve();
        printf("Case %d: There are %I64d ways to eat the trees.\n",cas,ans);
    }
    return 0;
}