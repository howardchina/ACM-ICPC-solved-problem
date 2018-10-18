#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 111111;
int a[maxn],b[maxn],c[maxn*2];
int n;
int check(int v) {
    int re=0,sum=0;
    for(int i=0;i<n;i++) {
        if(a[i]==v) sum++;
    }
    for(int i=0;i<n;i++) {
        if(sum*2>=n) break;
        if(a[i]!=v && b[i]==v) {
            re++;
            sum++;
        }
    }
    if(sum*2>=n) return re;
    return -1;
}
int main()
{
 //   freopen("data.in","r",stdin);
    int ans,cnt;
    while(scanf("%d",&n)!=EOF) {
        for(int i=0;i<n;i++){
            scanf("%d%d",&a[i],&b[i]);
            c[i]=a[i];c[i+n]=b[i];
        }
        sort(c,c+n*2);
        ans=1e9;
        cnt = 1;
        for(int i=1;i<2*n;i++) {
            if(c[i]==c[i-1]) cnt++;
            else {
                int re;
                if(cnt*2>=n && -1 != (re=check(c[i-1]))){
                    ans = min(ans,re);
                }
                cnt=1;
            }
            if(i==2*n-1) {
                int re;
                if(cnt*2>=n && -1!=(re=check(c[i-1]))){
                    ans = min(ans,re);
                }
            }
        }
        printf("%d\n",ans==1e9?-1:ans);
    }
    return 0;
}
