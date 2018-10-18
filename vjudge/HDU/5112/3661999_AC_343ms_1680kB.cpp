#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 11111;
pair<int,int>a[maxn];

int main()
{
    int T,n;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d%d",&a[i].first,&a[i].second);
        }
        sort(a,a+n);
        double ans=0;
        for(int i=1;i<n;i++){
            ans = max(ans,abs(a[i].second-a[i-1].second)*1.0/(a[i].first-a[i-1].first));
        }
        printf("Case #%d: %.2lf\n",cas,ans);
    }


    return 0;
}
