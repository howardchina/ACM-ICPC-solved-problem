//poj 3101
//公式推导
//0.5*L/abs(L/ti-L/tj)--->相差半周的时间

//(ti*tj) / (2*abs(ti-tj))
//令 (ti*tj)=bi; (2*abs(ti-tj))=ai;

//相邻两个卫星平行的时间间隔di=bi/ai，问题转化为求这n-1个分数的最小公倍数


//分母p=gcd(a1,a2,...,an-1)
//分子q=lcm(b1,b2,...,bn-1)

//q/p 约分即得最终答案

//知识点：大整数乘法+素因子分解

#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

const int N=1000;
const int M=10000;

int n;
int t[N],r[N];

int c[M];

int gcd(int a,int b)
{
	if(!b) return a;
	return gcd(b,a % b);
}

void run()
{
	int i,j;

    for(i=0;i<n;i++) scanf("%d",&t[i]);

    r[0]=1;
    for(i=1;i<N;i++) r[i]=0;

    int a,b,g,d,k;

    d=0;
    for(i=1;i<n;i++) if(t[i]!=t[0])
    {
        b = t[i] * t[0];
        a = abs(t[i] - t[0])<<1;
        g = gcd(a,b);

        a/=g;
        b/=g;
        d=gcd(a,d);

		//分解素因子
        for(j = 2; b > 1; j++ ) if(b % j == 0)
        {
			k=0;
			while(b % j == 0)
			{
				b /= j;
				k++;
			}
			if(k > c[j]) c[j] = k;
        }
    }

	//lrj结论:  lcm(a,b)=p1^max(a1,b1)*p2^max(a2,b2)……pn^max(an,bn)
	//here:		预先计算出 所有bi的素因子个数 max 存放在 c[i] 数组中
	//大整数乘法 r=∏(i^c[i]) {c[i]!=0}
	int tmp;
	for(i = 0; i < M; i++)
	{
		for(j=0; j<c[i]; j++)
		{
			tmp = 0;
			for(k = 0; k < N; k++)
			{
				r[k] = r[k]*i+tmp;
				tmp = r[k] / 10000;
				r[k] %= 10000;
			}
		}
	}

	//ans : (r[i] / d)
	i=999;
	while(i && r[i] == 0) i--;

	printf("%d",r[i]);
	for(--i;i>=0;--i) printf("%04d",r[i]);

	printf(" %d\n",d);	
}

int main()
{
    while(scanf("%d",&n)!=EOF) run();
    return 0;
}
