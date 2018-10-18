#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
//    freopen("data.in","r",stdin);
    int n,x,ans;
    char s[6];
    while(scanf("%d",&n)==1 && n){
        ans=65536;
        while(n--){
            scanf("%s %d",s,&x);
            if(s[0]=='M' && ans!=-1){
                if(x==0){ans=-1;}
                while(!(x&1) && x)
                    ans>>=1,x>>=1;
            }
        }
        if(ans>1)printf("%d\n",ans);
        else puts("1");
    }
    return 0;
}
