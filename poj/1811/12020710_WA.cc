#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
__int64 mult(__int64 a,__int64 b,__int64 n)// a*b % n
{
    __int64 s=0;
    while(b){
        if(b&1)s=(s+a)%n;
        a<<=1;b>>=1;
        if(a>n)a=a%n;
    }
    return s;
}
__int64 miller_rabin(__int64 n,__int64 i)//素数测定，错误机率为1/4
{
    __int64 j,k,b=0,a=1;
    j=n/(1<<i);
    while(b%n==0)b=abs(rand())%n;
    while(j)
    {
        if(j&1)a=mult(a,b,n);
        b=mult(b,b,n);j>>=1;
    }
    for(k=1;k<=i;k++){
        if(k<i-1&&mult(a,a,n)==1&&a!=1&&a!=n-1)return 0;
        a=mult(a,a,n);
    }
    if(a==1)return 1;
    return 0;
}
__int64 prime(__int64 n)
{//调用miller_rabin素数测试100次,正确概率为1 - (1/4)^100,几乎为1
    __int64 m,k,i,s=1;
    if(n==1)return 0;
    for(k=0,m=n-1;m%2==0;m/=2,k++);
    for(i=0,s=1;i<30;i++)s*=miller_rabin(n,k);
    return s;//对2的31次方，100组数据，I=100大约1S
}
__int64 gcd(__int64 a,__int64 b)//求最大公约数
{
    return b?gcd(b,a%b):a;
}
__int64 pollard_rho(__int64 n)//pollard_rho随机算法求n的一个约数
{
    __int64 i=1,a,b,p,t=2,c=0;
    a=b=abs(rand())%(n-1)+1;
    while(c==0||c==2)c=abs(rand())%(n-1)+1;
    do{
        i++;
        p=gcd(n+b-a,n);
        if(p>1&&p<n)return p;
        if(i==t){
            b=a;t<<=1;
        }
        a=(mult(a,a,n)+n-c)%n;
    }while(a!=b);
    return n;
}
unsigned __int64 find(__int64 n)
{
    unsigned __int64 p,q;
    if(prime(n))return n;//如果n为素数，返回n
    p=pollard_rho(n);//如果n不为素数，继续拆分n
    if(p>1)p=find(p);//尝试拆分n的一个约数p
    if(p<n){//如果p!=n则尝试拆分n的另一个约数n/p
        q=n/p;
        q=find(q);//尝试拆分n的一个约数n/p
        if(q<p)p=q;//取两个p、q的较小值
    }
    return p;
}
/*
unsigned __int64 find(__int64 n)//取任意素数约数
{
    unsigned __int64 p,q;
    p=n;
    while(prime(p)==0)
    p=pollard_rho(n);
    return p;
}*/
int main()
{
    __int64 n,T;
    //srand((unsigned)time(NULL));//G++ 会导致RE!!!!!!!
    scanf("%I64d",&T);
    while(T--){
        scanf("%I64d",&n);
        if(prime(n))puts("Prime");//如果是素数，则直接输出
        else printf("%I64d\n",find(n));//否则查找出最小素因子
    }
    return 0;
}
