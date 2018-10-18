#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

int main()
{
//    freopen("data.in","r",stdin);
    int n,x,mn,cnt,ans;
    while(scanf("%d",&n)!=EOF) {
        mn = 1e9+10;
        for(int i=1;i<=n;i++) {
            scanf("%d",&x);
            if(x<mn) {
                ans = i;
                mn = x;
                cnt = 1;
            }else if(x==mn) {
                cnt++;
            }
        }
        if(cnt==1)printf("%d\n",ans);
        else puts("Still Rozdil");
    }
    return 0;
}
