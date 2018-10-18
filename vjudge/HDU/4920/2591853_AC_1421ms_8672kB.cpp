#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
//typedef
const int MAXN=888;
typedef unsigned long long ULL;
int a[MAXN][MAXN],b[MAXN][MAXN],c[MAXN][MAXN],sum[MAXN];
int main()
{
//    freopen("data.in","r",stdin);
//    freopen("data.out","w",stdout);
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++){
                scanf("%d",&a[i][j]);
                a[i][j]%=3;
            }
        memset(sum,0,sizeof sum);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&b[i][j]);
                b[i][j]%=3;
                sum[j]+=b[i][j];
            }
        }
        for(int i=0;i<n;i++) sum[i]%=3;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                c[i][j]=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++){
                c[i][j]=sum[j];
            }
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(a[i][j]==0){
                for(int k=0;k<n;k++)
                    c[i][k]-=b[j][k];
            }else if(a[i][j]==2){
                for(int k=0;k<n;k++)
                    c[i][k]+=b[j][k];
            }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j!=0) printf(" ");
                printf("%d",((c[i][j])%3+3)%3);
            }
            puts("");
        }
    }
    return 0;
}