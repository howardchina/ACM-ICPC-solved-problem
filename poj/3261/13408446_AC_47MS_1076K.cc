#include <cstdio>
#include <cstring>
const int maxn=1001000;
int wa[maxn],wb[maxn],wv[maxn],ws[maxn];
int cmp(int *r,int a,int b,int l){
    return r[a]==r[b]&&r[a+l]==r[b+l];
}
void da(int *r,int *sa,int n,int m){
    int i,j,p,*x=wa,*y=wb,*t;
    for(i=0;i<m;i++) ws[i]=0;
    for(i=0;i<n;i++) ws[x[i]=r[i]]++;
    for(i=1;i<m;i++) ws[i]+=ws[i-1];
    for(i=n-1;i>=0;i--) sa[--ws[x[i]]]=i;
    for(j=1,p=1;p<n;j<<=1,m=p){
        for(p=0,i=n-j;i<n;i++) y[p++]=i;
        for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
        for(i=0;i<n;i++) wv[i]=x[y[i]];
        for(i=0;i<m;i++) ws[i]=0;
        for(i=0;i<n;i++) ws[wv[i]]++;
        for(i=1;i<m;i++) ws[i]+=ws[i-1];
        for(i=n-1;i>=0;i--) sa[--ws[wv[i]]]=y[i];
        for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
    }
    return;
}
int rank[maxn],height[maxn];
void calheight(int *r,int *sa,int n){
    int i,j,k=0;
    for(i=1;i<=n;i++) rank[sa[i]]=i;
    for(i=0;i<n;height[rank[i++]]=k)
    for(k?k--:0,j=sa[rank[i]-1];r[i+k]==r[j+k];k++);
    return;
}
int N,K,mx;
int a[maxn],sa[maxn];
bool check(int mid){
    int i,j;
    for(i=1,j=1;i<=N;i++){
        if(height[i]<mid)
            j=1;
        else
            j++;
        if(j>=K) return 1;
    }
    return 0;
}
void solve(){
    int l=0,r=N-K,mid,ans=0;
    while(l<=r){
        mid=(l+r)>>1;
        if(check(mid))
            ans=mid,l=mid+1;
        else
            r=mid-1;
    }
    printf("%d\n",ans);
}
int main(){
//    freopen("data.in","r",stdin);
    while(scanf("%d%d",&N,&K)==2){
        mx=0;
        for(int i=0;i<N;i++){
            scanf("%d",&a[i]);
            if(mx<a[i])mx=a[i];
        }
        a[N]=0;
        da(a,sa,N+1,mx+1);
        calheight(a,sa,N);
        solve();
    }
    return 0;
}
