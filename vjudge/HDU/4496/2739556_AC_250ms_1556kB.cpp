#include <iostream>
#include <stdio.h>
using namespace std;

int f[10010];
int ans[100101];
int u[101000];
int v[100100];

int find(int p)
{
	  for(;p!=f[p];p=f[p]) f[p]=f[f[p]];
	  return p;
}

int main()
{
  int n,m,i,j,t;
  while(~scanf("%d%d",&n,&m))
  {
		ans[m]=t=n;
		for(i=0;i<=n;i++) f[i]=i;
 
		for(i=1;i<=m;i++)
		{
			  scanf("%d%d",&u[i],&v[i]);
		}

		for(i=m;i>=2;i--)   
		{
			  int f1=find(u[i]);
			  int f2=find(v[i]);
			  if(f2!=f1)
			  {
				f[f1]=f2;
				t--;    
			  }
			  ans[i-1]=t;
		}

		for(i=1;i<=m;i++)
		{
			  printf("%d\n",ans[i]);
		}

  }
  return 0;
}