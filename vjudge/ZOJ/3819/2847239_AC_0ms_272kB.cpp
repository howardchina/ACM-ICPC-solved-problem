#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
//    freopen("data.in","r",stdin);
    int n,m,t,s0,s1,x,ans0,ans1;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        s0=s1=0;
        for(int i=1;i<n;i++){
            scanf("%d",&x);
            s0+=x;
        }
        for(int i=0;i<m;i++){
            scanf("%d",&x);
            s1+=x;
        }
        ans1=(s0-1)/(n-1);
        ans0=(s1+1)/m+(((s1+1)%m)?1:0);
        printf("%d %d\n",ans0,ans1);
    }
    return 0;
}
