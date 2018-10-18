#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

int main()
{
//    freopen("data.in","r",stdin);
    int n,x,pre;
    long long ans;
    while(scanf("%d",&n)!=EOF) {
        scanf("%d",&pre);
        ans = 0;
        for(int i=1;i<n;i++){
            scanf("%d\n",&x);
            if(x<pre) ans+=pre-x;
            pre = x;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
