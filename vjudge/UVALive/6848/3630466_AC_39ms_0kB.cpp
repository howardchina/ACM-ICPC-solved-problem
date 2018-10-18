#include <iostream>
#include <cstdio>

using namespace std;

typedef long long LL;

int v[111][111];
int maxv[111][111][55];
int minv[111][111][111];
int main()
{
//    freopen("data.in","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--){
        int R,C;
        scanf("%d%d",&R,&C);
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                scanf("%d",&v[i][j]);
            }
        }
        int ans = 0;
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(i!=0 && j!=0){
                    maxv[i][j][1]=max(max(maxv[i-1][j][1],maxv[i][j-1][1]),v[i][j]);
                    minv[i][j][1]=min(min(minv[i-1][j][1],minv[i][j-1][1]),v[i][j]);
                }else if(i==0 && j!=0){
                    maxv[i][j][1]=max(maxv[i][j-1][1],v[i][j]);
                    minv[i][j][1]=min(minv[i][j-1][1],v[i][j]);
                }else if(i!=0 && j==0){
                    maxv[i][j][1]=max(maxv[i-1][j][1],v[i][j]);
                    minv[i][j][1]=min(minv[i-1][j][1],v[i][j]);
                }else{
                    maxv[i][j][1]=v[i][j];
                    minv[i][j][1]=v[i][j];
                }
            }
        }
        int K = min(R,C);
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                for(int k=2;k<=K;k++){
                    if(i!=0 && j!=0){
                        minv[i][j][k]=min(min(minv[i-1][j][k],minv[i][j-1][k]),minv[i-1][j-1][k-1]+v[i][j]);
                    }else if(i==0 && j!=0){
                        minv[i][j][k]=minv[i][j-1][k];
                    }else if(i!=0 && j==0){
                        minv[i][j][k]=minv[i-1][j][k];
                    }else{
                        minv[i][j][k]=0x3f3f3f3f;
                    }
                }
            }
        }
        int KK = K/2;
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                for(int k=2;k<=KK;k++){
                    if(i!=0 && j!=0){
                        maxv[i][j][k]=max(max(maxv[i-1][j][k],maxv[i][j-1][k]),maxv[i-1][j-1][k-1]+v[i][j]);
                    }else if(i==0 && j!=0){
                        maxv[i][j][k]=maxv[i][j-1][k];
                    }else if(i!=0 && j==0){
                        maxv[i][j][k]=maxv[i-1][j][k];
                    }else{
                        maxv[i][j][k]=0;
                    }
                }
            }
        }
//        puts("min");
//        for(int i=0;i<R;i++){
//            for(int j=0;j<C;j++){
//                for(int k=0;k<=K;k++){
//                    printf("%d",minv[i][j][k]);
//                }
//                printf(" ");
//            }
//            printf("\n");
//        }
//        puts("max");
//        for(int i=0;i<R;i++){
//            for(int j=0;j<C;j++){
//                for(int k=0;k<=KK;k++){
//                    printf("%d",maxv[i][j][k]);
//                }
//                printf(" ");
//            }
//            printf("\n");
//        }

        for(int k=1;k<=KK;k++){
            if(maxv[R-1][C-1][k]==0 || minv[R-1][C-1][k*2]==0x3f3f3f3f) continue;
            ans = max(ans,maxv[R-1][C-1][k]-minv[R-1][C-1][k*2]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
