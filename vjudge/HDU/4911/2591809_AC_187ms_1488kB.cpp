#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN=111111;
int a[MAXN],t[MAXN],b[MAXN],n,k,m;
int query(int x){
    int s=0;
    while(x){
        s+=a[x];
        x-=x&(-x);
    }
    return s;
}
void add(int x){
    while(x<=n){
        a[x]++;
        x+=x&(-x);
    }
}
int bs(int v){
    int l=1,r=m,mid;
    while(l<=r){
        mid=(l+r)>>1;
        if(v==b[mid]) break;
        if(b[mid]>v) r=mid-1;
        else l=mid+1;
    }
    return mid;
}
int main(){
    while(scanf("%d%d",&n,&k)!=EOF){
        for(int i=1;i<=n;i++){
            scanf("%d",&t[i]);
            b[i]=t[i];
            a[i]=0;
        }
        sort(b+1,b+1+n);
        m=unique(b+1,b+1+n)-(b+1);
        LL ans=0;
        for(int i=n,p;i;i--){
            p=bs(t[i]);
            add(p);
            ans+=query(p-1);
        }
        printf("%I64d\n",max(0LL,ans-k));
    }
    return 0;
}
