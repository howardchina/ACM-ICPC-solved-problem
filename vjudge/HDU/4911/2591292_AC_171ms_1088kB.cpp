#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN=111111;
int a[MAXN],t[MAXN];
typedef long long LL;
LL ans;

void merge(int l,int mid,int r){
    int p=l,q=mid+1,cur=l;
    for(int i=l;i<=r;i++)
        t[i]=a[i];
    while(p<=mid&&q<=r){
        if(t[p]<=t[q]){
            a[cur++]=t[p++];
        }else{
            a[cur++]=t[q++];
            ans+=mid-p+1;
        }
    }
    while(p<=mid)
        a[cur++]=t[p++];
    while(q<=r)
        a[cur++]=t[q++];
}
void mergesort(int l,int r){
    if(l>=r)return;
    int m=(l+r)>>1;
    mergesort(l,m);
    mergesort(m+1,r);
    merge(l,m,r);
}
int main(){
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF){
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        ans=0;
        mergesort(1,n);
        printf("%I64d\n",max(0LL,ans-k));
    }
    return 0;
}
