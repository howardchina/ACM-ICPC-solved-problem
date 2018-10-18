#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 22;

int a[maxn];

int main()
{
//    freopen("data.in","rb",stdin);
//    freopen("data.out","wb",stdout);
    int k;
    scanf("%d",&k);
    if(k&1){
        puts("YES");
        int n=(k+k-1)*2;
        int m=n*k/2;
        printf("%d %d\n",n,m);
        for(int i=1;i<=k-1;i++){
            for(int j=k;j<=2*k-1;j++){
                printf("%d %d\n",i,j);
            }
        }
        for(int j=k;j<=2*k-2;j+=2){
            printf("%d %d\n",j,j+1);
        }
        int nn=k+k-1;
        for(int i=1;i<=k-1;i++){
            for(int j=k;j<=2*k-1;j++){
                printf("%d %d\n",i+nn,j+nn);
            }
        }
        for(int j=k;j<=2*k-2;j+=2){
            printf("%d %d\n",j+nn,j+1+nn);
        }
        printf("%d %d\n",2*k-1,2*k-1+nn);
    }else{
        puts("NO");
    }
    return 0;
}
