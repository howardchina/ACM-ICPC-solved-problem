#include <iostream>
#include <cstring>
#include <cstdio>
#include <math.h>
#include <cstdlib>
using namespace std;
#define ll long long
#define N 1000
#define M 10000
int t[N+5];
int c[M+5];
int res[M+5];
int n;
int prime[M],vis[M],cnt;
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}

void cal(int s)
{
	for(int i=0;i<cnt && s>1;++i)
		if(s%prime[i]==0)
		{
			int k=0;
			while(s%prime[i]==0)
			{
				s/=prime[i];
				k++;
			}
			if(k>c[prime[i]])
				c[prime[i]]=k;
		}
}
void init(int n)
{
	int m=sqrt(n+0.5);
	cnt=0;
	for(int i=2;i<=m;++i)
		if(!vis[i])
		{
			for(int j=i*i;j<=n;j+=i)
				vis[j]=1;
		}
	for(int i=2;i<=n;++i)
		if(!vis[i])
			prime[cnt++]=i;
}
int main ()
{
	init(M);
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=1;i<=n;++i)
			scanf("%d",&t[i]);
		memset(c,0,sizeof(c));

		int nn=0;
		for(int i=2;i<=n;++i)
		{
			int b=t[i]*t[1];
			int a=abs(t[i]-t[1])<<1;
			int d=gcd(a,b);

			a/=d; // 分数化简
			b/=d;
			nn=gcd(a,nn); // 分母部分不断求最大公约数
			cal(b);
		}

		memset(res,0,sizeof(res));
		res[1]=1;

		// 压4位的高精度大整数乘法
		for(int i=1;i<=M;++i)
			for(int j=1;j<=c[i];++j)
			{
				int temp=0;
				for(int k=1;k<=N;++k)
				{
					res[k]=res[k]*i+temp;
					temp=res[k]/M;
					res[k]%=M;
				}
			}
		int index=N;
		for( ; res[index]==0 ;--index) ;
		printf("%d",res[index--]);
		for(;index>=1;--index)
			printf("%04d",res[index]);
		printf(" %d\n",nn);
	}
	return 0;
}
