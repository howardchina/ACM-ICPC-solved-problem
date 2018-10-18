#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 111;

char s[maxn];
int a[maxn];

int main()
{
//    freopen("data.in","rb",stdin);
//    freopen("data.out","wb",stdout);
    scanf("%s",s);
    int n=strlen(s);
    int ok=0;
    int ans;
    for(int i=0;i<n;i++){
        a[i]=s[i]-'0';
    }
    for(int i=0;i<n;i++){
        if(a[i]==0||a[i]==8){
            ok=1;
            ans=a[i];
            break;
        }
    }
    if(!ok){
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if((a[i]*10+a[j])%8==0){
                    ok=1;
                    ans=a[i]*10+a[j];
                    break;
                }
            }
        }
        if(!ok){
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    for(int k=j+1;k<n;k++){
                        if((a[i]*100+a[j]*10+a[k])%8==0){
                            ok=1;
                            ans=a[i]*100+a[j]*10+a[k];
                            break;
                        }
                    }
                }
            }
        }
    }
    if(ok){
        printf("YES\n%d\n",ans);
    }else{
        puts("NO");
    }
    return 0;
}
