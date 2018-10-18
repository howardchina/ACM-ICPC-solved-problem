#include<iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define MAXV 105
#define MAXM 100005

int weight[MAXV],c[MAXV],f[MAXM],user[MAXM];

int main(){
	int i,j,n,m,ans;
	while(scanf("%d%d",&n,&m) && n && m){
		for(i=1;i<=n;i++)
			scanf("%d",&weight[i]);
		for(i=1;i<=n;i++)
			scanf("%d",&c[i]);

		memset(f,0,sizeof(f));
		f[0]=1;ans=0;
		for(i=1;i<=n;i++){
			memset(user,0,sizeof(user));
			for(j=weight[i];j<=m;j++){
				if(!f[j] && f[j-weight[i]] && user[j-weight[i]]+1<=c[i]){
					f[j]=1;
					user[j]=user[j-weight[i]]+1;
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
