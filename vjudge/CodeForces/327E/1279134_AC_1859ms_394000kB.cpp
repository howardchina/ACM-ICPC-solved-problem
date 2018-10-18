#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<cctype>
#include<cassert>
#include<climits>
using namespace std;
#define For(i,n) for(int i=1;i<=n;i++)
#define Rep(i,n) for(int i=0;i<n;i++)
#define Fork(i,k,n) for(int i=k;i<=n;i++)
#define ForD(i,n) for(int i=n;i;i--)
#define Forp(x) for(int p=pre[x];p;p=next[p])
#define RepD(i,n) for(int i=n;i>=0;i--)
#define MEM(a) memset(a,0,sizeof(a))
#define MEMI(a) memset(a,127,sizeof(a))
#define MEMi(a) memset(a,128,sizeof(a))
#define INF (2139062143)
#define F (1000000007)
#define MAXN (1<<24)
#define MAXItem (24+10)
typedef long long ll;
int n,k;
ll f[MAXN]={0},g[MAXN]={0},A[MAXN]={0},a[MAXItem]={0},b[MAXItem]={0};
int main()
{
// freopen("CF327E.in","r",stdin);
   scanf("%d",&n);
   For(i,n) scanf("%d",&a[i]),A[1<<i-1]=a[i];
   cin>>k;
   For(i,k) scanf("%d",&b[i]);Fork(i,k+1,2) b[i]=-1; //除了x=-1，x^-1!=0   
   Rep(i,1<<n) f[i]=f[i-(i&(-i))]+A[i&(-i)];
   g[0]=1;
   Rep(i,1<<n)
      if (f[i]^b[1]&&f[i]^b[2]&&f[i]^b[3])    
      {
         //for(int j=(1<<n)-1;j;j-=j&(-j)) f[i+(j&-j)
         for(int j=i;j;j-=j&(-j)) g[i]=g[i]+g[i-(j&(-j))];
         g[i]%=F;
      }
   
   printf("%I64d",g[(1<<n)-1]%F);
   
// while(1);
   return 0;
}
