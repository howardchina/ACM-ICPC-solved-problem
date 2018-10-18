#include <cstdio>
#include <cstring>
const int maxn=2011;
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
int sa[maxn],n,mid;
void solve(){
    int mxlen=1,minpos=0,t;
    for(int i=1;i<=n;i++){
        int a=sa[i-1],b=sa[i];
        if(a>b){t=a;a=b;b=t;}
        if(a>=mid||b<=mid) continue;
        if(a+height[i]+b!=n) continue;
        if(height[i]>mxlen || (height[i]==mxlen && a<minpos)){
            mxlen=height[i];
            minpos=a;
        }
    }
    for(int i=minpos,j=0;j<mxlen;i++,j++)
        putchar(a[i]);
    putchar('\n');
}
bool read(){
    mid=strlen(a);
    if(mid==0)return 0;
    a[mid]=1;
    for(int i=mid-1,j=mid+1;i>=0;i--,j++)
        a[j]=a[i];
    n=mid*2+1;
    a[n]='\0';
    return 1;
}
int main()
{
//    freopen("data.in","r",stdin);
//    while(gets(a)){
    gets(a);
        read();
        da(a,sa,n+1,128);
        calheight(a,sa,n);
        solve();
//    }
    return 0;
}
