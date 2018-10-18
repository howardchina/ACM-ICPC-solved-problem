#include <cstdio>
#include <cstring>
const int maxn=50010;
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
}
int rank[maxn],height[maxn];
void calheight(int *r,int *sa,int n){
    int i,j,k=0;
    for(i=1;i<=n;i++) rank[sa[i]]=i;
    for(i=0;i<n;height[rank[i++]]=k)
        for(k?k--:0,j=sa[rank[i]-1];r[i+k]==r[j+k];k++);
}
int a[maxn],sa[maxn],mm[maxn],best[maxn][20];
void _init(){
    mm[0]=0;
    for(int i=1;i<maxn;i++){
        if((i&(i-1))==0) mm[i]=mm[i-1]+1;
        else mm[i]=mm[i-1];
    }
}
inline int nmin(int a,int b){
    if(a<b)return a;
    return b;
}
void initRMQ(int n){
    for(int i=1;i<=n;i++)
        best[i][0]=height[i];
    for(int j=1;j<20;j++)
        for(int i=1;i<=n;i++)
        best[i][j]=nmin(best[i][j-1],best[nmin(n,i+(1<<(j-1)))][j-1]);
}
int askRMQ(int i,int t){
    int a=best[i][mm[t]];
    int b=best[i+t-mm[t]][mm[t]];
    if(a<b) return a;
    return b;
}
int lcq(int a,int b){
    int t;
    a=rank[a];
    b=rank[b];
    if(a>b){
        t=a;
        a=b;
        b=t;
    }
    a++;
    t=b-a;
    return askRMQ(a,t);
}
int main(){
//    freopen("data.in","r",stdin);
    _init();
    int n,T;
    char s[3];
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%s",s);
            a[i]=s[0]-'a'+1;
        }
        a[n]=0;
        da(a,sa,n+1,3);
        calheight(a,sa,n);
        initRMQ(n);
        int ans=1;
        for(int l=1;l<n;l++){
            for(int i=0;i+l<=n;i+=l){
                int k=lcq(i,i+l);
                int re=k/l+1;
                int t=i-(l-k%l);
                if(t>=0 && k%l && lcq(t,t+l)) re++;
                if(ans<re) ans=re;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
