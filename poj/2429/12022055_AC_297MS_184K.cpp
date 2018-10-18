#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
using namespace std;
typedef     __int64 u64;
const int MAX = 100;
const int MAXN = 30;
const u64 INF = (u64)1<<62;

 u64 gcd(u64 a, u64 b) {
	if (a < b) return gcd(b,a);
	u64 c;
	while (b) {c=a%b;a=b;b=c;}
	return a;
}

 u64 product_mod(u64 a,u64 b,u64 c)
{
    u64 ret=0,tmp=a%c;
    while(b)
    {
        if(b&0x1)
            if((ret+=tmp)>=c)
                ret-=c;
            if((tmp<<=1)>=c)
                tmp-=c;
            b>>=1;
    }
    return ret;
}

u64 random() {
      u64 a;
      a = rand();
      a *= rand();
      a *= rand();
      a *= rand();
      return a;
}

u64 f(u64 x, u64 n) {
      return (product_mod(x, x, n) + 1) % n;
}
u64 Pollard_Rho(u64 n) {
      if(n <= 2) return 0;
      if(! (n & 1)) return 2;
      u64 i, p, x, xx;
      for(i = 1; i < MAX; i ++) {
           x = random() % n;
           xx = f(x, n);
           p = gcd((xx + n - x) % n, n);
           while(p == 1) {
                x = f(x, n);
                xx = f(f(xx, n), n);
                p = gcd((xx + n - x) % n, n) % n;
           }
           if(p) return p;
      }
      return 0;
}

u64 power_mod(u64 x, u64 c, u64 n) {
      u64 z = 1;
      while(c) {
           if(c & 1) z =product_mod(z, x, n);
           x = product_mod(x, x, n);
           c >>= 1;
      }
      return z;
}

bool Miller_Rabin(u64 n) {
      if(n < 2) return false;
      if(n == 2) return true;
      if(! (n & 1)) return false;
      u64 i, j, k, m, a;
      m = n - 1;
      k = 0;
      while(m % 2 == 0) {
           m >>= 1; k ++;
      }
      for(i = 0; i < MAX; i ++) {
           a = power_mod(random() % (n - 1) + 1, m, n);
           if(a == 1) continue;
           for(j = 0; j < k; j ++) {
                if(a == n - 1) break;
                a = product_mod(a, a, n);
           }
           if(j == k) return false;
      }
      return true;
}



u64 Prime(u64 a) {
      if(Miller_Rabin(a)) return 0;
      u64 t = Pollard_Rho(a);
      u64 p = Prime(t);
      if(p) return p;
      return t;
}


u64 factor[MAXN];
u64 facNum[MAX];
//直接调用即可。因子存在factor中，相应系数存在facNum中，返回素因子个数.
int BigNumRes(u64 a)
{
    int m = 0;
    int time=0;
    u64 t;
    while(a > 1)
    {
        if(Miller_Rabin(a)) break;
        t = Prime(a);
        factor[m ++] = t;
        time=0;
        while (a%t==0 && a!=1) {time++;a/=t;}
        facNum[m-1]=time;
    }
    if(a != 1) {factor[m ++] = a;facNum[m-1]=1;}
    return m;
}

u64 n,res,limi;
int num;
void dfs(int de,u64 v)
{
    if(n/res+res>n/v+v) res=v;
    if(v>limi || de>=num)return;
    dfs(de+1,v);
    v=product_mod(v,power_mod(factor[de],facNum[de],INF),INF);
    dfs(de+1,v);
}


int main()
{
//    freopen("test.in","r",stdin);
    u64 g,l,a,b;
    while(~scanf("%I64d %I64d",&g,&l)){
        n=l/g;
        num=BigNumRes(n);
        limi=sqrt(1.0*n);
        res=1;
        dfs(0,1);
        a=g*res,b=l/res;
        if(a>b)a^=b^=a^=b;
        printf("%I64d %I64d\n",a,b);
    }
    return 0;
}
