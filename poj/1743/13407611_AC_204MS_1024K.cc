#include <cstdio>

const int maxn=20100;
int wa[maxn],wb[maxn],wv[maxn],ws[maxn];
int cmp(int *r,int a,int b,int l){
    return r[a]==r[b]&&r[a+l]==r[b+l];
}
void da(int *r,int *sa,int n,int m)
{
     int i,j,p,*x=wa,*y=wb,*t;
     for(i=0;i<m;i++) ws[i]=0;
     for(i=0;i<n;i++) ws[x[i]=r[i]]++;
     for(i=1;i<m;i++) ws[i]+=ws[i-1];
     for(i=n-1;i>=0;i--) sa[--ws[x[i]]]=i;
     for(j=1,p=1;p<n;j*=2,m=p)
     {
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
void calheight(int *r,int *sa,int n) {
    int i,j,k=0;
    for(i=1;i<=n;i++) rank[sa[i]]=i;
    for(i=0;i<n;height[rank[i++]]=k)
    for(k?k--:0,j=sa[rank[i]-1];r[i+k]==r[j+k];k++);
    return;
}
int n,a[maxn],sa[maxn];
bool check(int mid){
    int i,j,mx,mn;
    for(i=1;i<=n;i=j){
        while(i<=n && height[i]<mid)
            i++;
        j=i;
        mn=n;
        mx=0;
        if(i==n+1)
            break;
        if(sa[i-1]>mx)
            mx=sa[i-1];
        if(sa[i-1]<mn)
            mn=sa[i-1];
        while(j<=n && height[j]>=mid){
            if(sa[j]>mx)
                mx=sa[j];
            if(sa[j]<mn)
                mn=sa[j];
            j++;
        }
        if(mx-mn>=mid)
            return 1;
    }
    return 0;
}
int main()
{
//    freopen("data.in","r",stdin);
    while(scanf("%d",&n)==1 && n){
        if(n<=9){
            for(int i=0;i<n;i++)
                scanf("%d",&a[i]);
            puts("0");
            continue;
        }
        scanf("%d",&a[0]);
        for(int i=1;i<n;i++){
            scanf("%d",&a[i]);
            a[i-1]=a[i-1]-a[i]+89;
        }
        n--;
        a[n]=0;
        da(a,sa,n+1,180);
        calheight(a,sa,n);
        int l=0,r=n-1,mid,ans=0;
        while(l<=r){
            mid=(l+r)>>1;
            if(check(mid)){
                ans=mid,l=mid+1;
            }else
                r=mid-1;
        }
        if(ans<4)puts("0");
        else printf("%d\n",ans+1);
    }
    return 0;
}
