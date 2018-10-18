#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
typedef __int64 LL;

LL MulMod(LL a,LL b,LL m)
{
    LL s=0;
    while(b){
        if(b&1)s=(s+a)%m;
        a<<=1,b>>=1;
        if(a>m)a=a%m;
    }
    return s;
}

LL Miller_Rabin(LL n,LL i)
{
    LL j,k,b=0,a=1;
    j=n/(1<<i);
    while(b%n==0)b=abs(rand())%n;
    while(j){
        if(j&1)a=MulMod(a,b,n);
        b=MulMod(b,b,n);j>>=1;
    }
    for(k=1;k<=i;k++){
        if(a==n-1)return 1;
        if(k<i-1&&MulMod(a,a,n)==1&&a!=1&&a!=n-1) return 0;
        a=MulMod(a,a,n);
    }
    if(a==1)return 1;
    return 0;
}

LL prime(LL n)
{
    LL m,k,i,s;
    if(n==1)return 0;
    for(k=0,m=n-1;m%2==0;m>>=1,k++);
    for(i=0,s=1;i<50;i++) s*=Miller_Rabin(n,k);
    return s;
}

LL Gcd(LL a,LL b)
{
    while(b){
        a%=b;
        a^=b^=a^=b;
    }
    return a;
}

LL Pollard_Rho(LL n)
{
    LL i=1,a,b,p,t=2,c=0;
    a=b=abs(rand())%(n-1)+1;
    while(c==0||c==2)c=abs(rand())%(n-1)+1;
    do{
        i++;
        p=Gcd(n+b-a,n);
        if(p>1&&p<n)return p;
        if(i==t){
            b=1;t<<=1;
        }
        a=(MulMod(a,a,n)+n-c)%n;
    }while(a!=b);
    return n;
}

LL Find(LL n)
{
    LL p,q;
    if(prime(n))return n;
    p=Pollard_Rho(n);
    if(p>1)p=Find(p);
    if(p<n){
        q=n/p;
        q=Find(q);
        if(q<p)p=q;
    }
    return p;
}

//LL Find(LL n)
//{
//    LL p;
//    p=n;
//    while(prime(p)==0)
//        p=Pollard_Rho(n);
//    return p;
//}

int main()
{
//    freopen("test.in","r",stdin);
    LL n,T;
    scanf("%I64d",&T);
    while(T--){
        scanf("%I64d",&n);
        if(prime(n))puts("Prime");
        else printf("%I64d\n",Find(n));
    }
    return 0;
}
