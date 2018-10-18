#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
double dp[52][52][2502];
int main()
{
//    freopen("data.in","r",stdin);
    int T,N,M;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&N,&M);
        memset(dp,0,sizeof dp);
        dp[0][0][0]=1;
        int NM=N*M;
        for(int i=0;i<=N;i++)
            for(int j=0;j<=M;j++){
                int tot=i*j;
                int Nij=(N-i)*j;
                int Mji=(M-j)*i;
                int NiMj=(N-i)*(M-j);
                for(int k=max(i,j);k<=tot;k++){
                    if(NM-k==0) break;
                    if(i==N && j==M) continue;
                    dp[i][j][k+1]+=dp[i][j][k]*(tot-k)/(NM-k);
                    dp[i+1][j][k+1]+=dp[i][j][k]*Nij/(NM-k);
                    dp[i][j+1][k+1]+=dp[i][j][k]*Mji/(NM-k);
                    dp[i+1][j+1][k+1]+=dp[i][j][k]*NiMj/(NM-k);
                }
            }
        double ans=0;
        for(int k=max(N,M);k<=NM;k++)
            ans+=k*dp[N][M][k];
        printf("%.12lf\n",ans);
    }
    return 0;
}