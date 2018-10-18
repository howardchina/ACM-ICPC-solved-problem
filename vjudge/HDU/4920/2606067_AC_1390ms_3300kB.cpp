#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include<vector>
#include<bitset>
using namespace std;
#define N 800
#define ll __int64

std::bitset<N> a[N],a1[N],a2[N],b[N],b1[N],b2[N];
int ans[N][N];
int main()
{
	int n,i,j,k;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<N;i++)
		{
			a[i].reset();
			a1[i].reset();
			a2[i].reset();
			b[i].reset();
			b1[i].reset();
			b2[i].reset();
		}
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				scanf("%d",&k);
				k%=3;
				if(k==1)
				{
					a[i][j]=1;
					a1[i][j]=1;
				}
				else if(k==2)
				{
					a[i][j]=1;
					a2[i][j]=1;
				}
			}
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				scanf("%d",&k);
				k%=3;
				if(k==1)
				{
					b[j][i]=1;
					b1[j][i]=1;
				}
				else if(k==2)
				{
					b[j][i]=1;
					b2[j][i]=1;
				}
			}
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				ans[i][j]=0;
				ans[i][j]+=(a[i]&b[j]).count();
				ans[i][j]+=(a1[i]&b2[j]).count();
				ans[i][j]+=(a2[i]&b1[j]).count();
				ans[i][j]%=3;
			}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n-1;j++)
			{
				printf("%d ",ans[i][j]);
			}
			printf("%d\n",ans[i][n-1]);
		}
	}
}