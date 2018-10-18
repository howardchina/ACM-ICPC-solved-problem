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
    int n,l,r,x;
    scanf("%d%d%d%d",&n,&l,&r,&x);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    int sum=0,ans=0,L,R;
    for(int i=(1<<n)-1;i>=0;i--){
        sum=0;
        L=-1,R=-1;
        for(int k=0;k<n;k++){
            if((1<<k)>i) break;
            if((1<<k)&i) {
                if(L==-1){
                    L=k;
                    R=k;
                }else{
                    R=k;
                }
                sum+=a[k];
            }
        }
        if(sum>=l && sum<=r && (L!=-1 && a[R]-a[L]>=x)){
            ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
