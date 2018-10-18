#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int idb[1001],a[1001],b[1001],vis[1001];
int main()
{
//    freopen("data.in","r",stdin);
    int n,cas=1;
    while(scanf("%d",&n)==1 && n){
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
            b[i]=a[i];
        }
        sort(b,b+n);
        for(int i=0;i<n;i++)
            idb[b[i]]=i;
        memset(vis,0,sizeof vis);
        int ans=0;
        for(int i=0;i<n;i++){
            if(vis[b[i]]) continue;
            vis[b[i]]=1;
            int p=i,v=b[i],k=0;
            do{
                v=a[p];
                if(vis[v]) break;
                vis[v]=1;
                ans+=v;
                k++;
                p=idb[v];
            }while(1);
            ans+=min(k*b[i],2*b[i]+b[0]*(k+2));
        }
        printf("Case %d: %d\n\n",cas++,ans);
    }
    return 0;
}
