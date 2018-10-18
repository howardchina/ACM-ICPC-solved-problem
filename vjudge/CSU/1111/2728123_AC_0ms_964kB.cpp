#include<stdio.h>

int main()
{
	int t,i;

	double a,b,c;

	scanf("%d",&t);

	for (i=1;i<=t;i++)
	{
		scanf("%lf%lf%lf",&a,&b,&c);

		printf("%.0lf\n",(a-(a+b)/3)*(c/((a+b)/3)));
	}

	return 0;
}
