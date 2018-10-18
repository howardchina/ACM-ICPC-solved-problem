#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 301;
int dp[333][111];
int dis[111][111];
int Ci[111],Si[111];

struct Node{
    int o;
    bool operator < (const Node&rhs)const{
        return Si[o]<Si[rhs.o];
    }
}mp[111];


int main()
{
//    freopen("data.in","r",stdin);
    int W,cas=1,ans,N,M,T,S,E,u,v,l;
    scanf("%d",&W);
    while(W--){
        scanf("%d%d%d%d%d",&N,&M,&T,&S,&E);
        for(int i=0;i<N;i++)
            scanf("%d",&Ci[i]);
        for(int i=0;i<N;i++)
            scanf("%d",&Si[i]);
        for(int i=0;i<N;i++)
            mp[i].o = i;
        sort(mp,mp+N);

        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++){
                dis[i][j]=INF;
                if(i==j) dis[i][j] = 0;
            }
        while(M--){
            scanf("%d%d%d",&u,&v,&l);
            if(dis[u][v]>l){
                dis[u][v] = l;
                dis[v][u] = l;
            }
        }

        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                for(int k=0;k<N;k++)
                    if(dis[j][i]<=T && dis[i][k]<=T)
                        dis[j][k] = min(dis[j][k],dis[j][i]+dis[i][k]);

        memset(dp,-1,sizeof dp);
        for(int i=0;i<N;i++)
            if(Ci[i]+dis[S][i] <= T)
                dp[Ci[i]+dis[S][i]][i] = Si[i];

//        for(int i=0;i<=T;i++)
//            for(int j=0;j<N;j++){
//                int mj = mp[j].o;
//                for(int k=0;k<N;k++){
//                    int mk = mp[k].o;
//                    if(i - dis[mk][mj] - Ci[mj] >= 0 && dp[i - dis[mk][mj] - Ci[mj]][mk]!=-1){
//                        if(Si[mk] < Si[mj]){
//                            if(dp[i][mj]==-1 || dp[i][mj] < dp[i - dis[mk][mj] - Ci[mj]][mk] + Si[mj]){
//                                dp[i][mj] = dp[i - dis[mk][mj] - Ci[mj]][mk] + Si[mj];
//                            }
//                        }
//                    }
//                }
//            }

        for(int i=0;i<=T;i++)
            for(int j=0;j<N;j++){
                int mj = mp[j].o;
                if(dp[i][mj] == -1) continue;
                for(int k=0;k<N;k++){
                    int mk = mp[k].o;
                    if(Si[mj] < Si[mk] && i + dis[mj][mk] + Ci[mk] <= T){
                        if(dp[i + dis[mj][mk] + Ci[mk]][mk]==-1 || dp[i + dis[mj][mk] + Ci[mk]][mk] < dp[i][mj] + Si[mk]){
                            dp[i + dis[mj][mk] + Ci[mk]][mk] = dp[i][mj] + Si[mk];
                        }
                    }
                }
            }
        ans=0;
        for(int j=0;j<N;j++)
            for(int i=0;i<=T-dis[j][E];i++)
                ans = max(ans,dp[i][j]);
        printf("Case #%d:\n",cas++);
        printf("%d\n",ans);
    }
    return 0;
}