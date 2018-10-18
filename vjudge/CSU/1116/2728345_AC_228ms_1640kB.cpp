#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

struct node
{
	int u,v,c;
}e[10000];

int t,i,j,k,m,n;

int no[20];
int g[100][100];
int a[100];

int res;
int inf=0xfffffff;
void mst()
{
	int i,j; int k0=0;

	for(i=1;i<=n;i++) for(j=1;j<=n;j++) g[i][j]=inf;

	for(i=1;i<=m;i++)
	{
		if(no[e[i].u] && no[e[i].v]) 
		{
			if(e[i].c<g[e[i].u][e[i].v])
				g[e[i].u][e[i].v]=g[e[i].v][e[i].u]=e[i].c;
		}
	}

	int n0=0;
	for(i=1;i<=n;i++) if(no[i]) {k0+=a[i]; n0++;}
		
	int dist[30];
	for(i=1;i<=n;i++) dist[i]=g[1][i];
	dist[1]=0;

	int minn=inf; int pos; int used[30];
	memset(used,0,sizeof(used));

	used[1]=1;
	int ans=0;
	for(i=1;i<=n0-1;i++)
	{
		minn=inf;
		pos=0;
		for(j=1;j<=n;j++) if(!used[j] && dist[j]<minn) {minn=dist[j]; pos=j;}

		if(!pos) {return;}
		used[pos]=1;
		ans+=dist[pos];
		for(j=1;j<=n;j++) if(!used[j] && g[pos][j]<dist[j]) dist[j]=g[pos][j];
	}

//	cout<<ans<<endl;
	if(ans<=k)
	{
		if(k0>res) res=k0;
	}
}

void dfs(int k)
{
	if(k>n)
	{
		mst();
		return ;
	}
	if(k!=1) dfs(k+1);

	no[k]=1;
	dfs(k+1);
	no[k]=0;
}

int main()
{
	cin>>t;

	while(t--)
	{
		cin>>n>>m>>k;

		for(i=1;i<=n;i++) cin>>a[i];
		for(i=1;i<=m;i++)
		{
			cin>>e[i].u>>e[i].v>>e[i].c;
		}

		memset(no,0,sizeof(no));
		res=0;
		dfs(1);

		cout<<res<<endl;
	}
	return 0;
}