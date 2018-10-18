#include <iostream>
#include <cstdio>

using namespace std;

typedef long long LL;

int Abs(int x){
    return x>0?x:-x;
}


int g[555][555];
int main()
{
//    freopen("data.in","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--){
        int N,M,markx,marky;
        scanf("%d%d",&N,&M);
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                scanf("%d",&g[i][j]);
                if(g[i][j]==-1){
                    markx = i;
                    marky = j;
                }
            }
        }
        int ans = 0;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(i==markx && j==marky)continue;

                int x = Abs(i-markx)+Abs(j-marky);
                if(x&1){
                    ans += g[i][j];
                }else{
                    ans -= g[i][j];
                }
            }
        }
        printf("%d\n",ans);
    }



    return 0;
}
