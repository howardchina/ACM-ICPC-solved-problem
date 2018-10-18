#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 111111;

int a[maxn];

int main()
{
//    freopen("data.in","rb",stdin);
//    freopen("data.out","wb",stdout);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    if(n>=3){
        if(a[n-2]==1 && a[n-1]==0){
            puts("YES");
            for(int i=0;i<n;i++){
                //直接输出
                printf("%d%s",a[i],i!=n-1?"->":"\n");
            }
        }else if(a[n-2]==0 && a[n-1]==0){
            int pos=-1;
            for(int i=n-3;i>=0;i--){
                if(a[i]==0){
                    pos=i;
                    break;
                }
            }
            if(pos!=-1){
                puts("YES");
                //0~pos-1 ->(pos->(pos+1~n-2))->n-1
                for(int i=0;i<pos;i++){
                    printf("%d->",a[i]);
                }
                printf("(%d->(",a[pos]);
                for(int i=pos+1;i<=n-2;i++){
                    printf("%d%s",a[i],i<n-2?"->":"");
                }
                printf("))->%d\n",a[n-1]);
            }else{
                puts("NO");
            }
        }else{
            puts("NO");
        }
    }else{
        if(n==1){
            if(a[0]==0) puts("YES\n0");
            else puts("NO");
        }else{
            if(a[0]==1 && a[1]==0) puts("YES\n1->0");
            else puts("NO");
        }
    }
    return 0;
}
