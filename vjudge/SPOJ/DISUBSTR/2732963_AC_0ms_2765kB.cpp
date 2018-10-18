#include <cstdio>
#include <cstring>
const int maxn=1011;
int wa[maxn],wb[maxn],wv[maxn],ws[maxn];
int cmp(int *r,int a,int b,int l){
    return r[a]==r[b]&&r[a+l]==r[b+l];
}
void da(char *r,int *sa,int n,int m){
    int i,j,p,*x=wa,*y=wb,*t;
    for(i=0;i<m;i++)ws[i]=0;
    for(i=0;i<n;i++)ws[x[i]=r[i]]++;
    for(i=1;i<m;i++)ws[i]+=ws[i-1];
    for(i=n-1;i>=0;i--)sa[--ws[x[i]]]=i;
    for(j=1,p=1;p<n;j<<=1,m=p){
        for(p=0,i=n-j;i<n;i++)y[p++]=i;
        for(i=0;i<n;i++)if(sa[i]>=j)y[p++]=sa[i]-j;
        for(i=0;i<n;i++)wv[i]=x[y[i]];
        for(i=0;i<m;i++)ws[i]=0;
        for(i=0;i<n;i++)ws[wv[i]]++;
        for(i=1;i<m;i++)ws[i]+=ws[i-1];
        for(i=n-1;i>=0;i--)sa[--ws[wv[i]]]=y[i];
        for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
    }
    return;
}
int rank[maxn],height[maxn];
void calheight(char *r,int *sa,int n){
    int i,j,k=0;
    for(i=1;i<=n;i++)rank[sa[i]]=i;
    for(i=0;i<n;height[rank[i++]]=k)
    for(k?k--:0,j=sa[rank[i]-1];r[i+k]==r[j+k];k++);
    return;
}
char a[maxn];
int sa[maxn],n;
void solve(){
    int ans=0;
    for(int i=0;i<=n;i++){
        ans+=n-sa[i]-height[i];
    }
    printf("%d\n",ans);
}
int main()
{
//    freopen("data.in","r",stdin);
    int T;
    scanf("%d",&T);
    gets(a);
    while(T--){
        gets(a);
        n=strlen(a);
        a[n]=0;
        da(a,sa,n+1,128);
        calheight(a,sa,n);
        solve();
    }
    return 0;
}
