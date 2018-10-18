#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 111111;

char s[maxn];

int main()
{
//    freopen("data.in","rb",stdin);
//    freopen("data.out","wb",stdout);
    scanf("%s",s);
    int n=strlen(s);
    int x=-1,y=-1;
    int ok=0;
    for(int i=0;i<n-1;i++){
        if(s[i]=='A' && s[i+1]=='B'){
            x=i;
            break;
        }
    }
    for(int i=n-2;i>=0;i--){
        if(s[i]=='B' && s[i+1]=='A'){
            y=i;
            break;
        }
    }
    if(x!=-1 && y!=-1 && abs(x-y)>1){
        ok=1;
    }
    x=-1,y=-1;
    for(int i=0;i<n-1;i++){
        if(s[i]=='B' && s[i+1]=='A'){
            x=i;
            break;
        }
    }
    for(int i=n-2;i>=0;i--){
        if(s[i]=='A' && s[i+1]=='B'){
            y=i;
            break;
        }
    }
    if(x!=-1 && y!=-1 && abs(x-y)>1){
        ok=1;
    }
    printf("%s\n",ok?"YES":"NO");
    return 0;
}
