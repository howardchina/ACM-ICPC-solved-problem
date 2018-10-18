#include <stdio.h>
#define max(x,y) (x>y?x:y)
int dp[12900];
int v[3500];
int w[3500];
int main()
{
	int i,j,n,m,ans;
	while(~scanf("%d%d",&n,&m)){
		for(i=1;i<=n;i++){
			scanf("%d %d", &w[i], &v[i]);
		}
		for(i=0;i<=n;i++){
			dp[i]=0;
		}
		for(i=1;i<=n;i++){
			for(j=m;~j;j--){
				if(j>=w[i])
					dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
			}
		}
		ans=0;
		for(i=1;i<=m;i++){
			ans=max(dp[i],ans);
		}
		printf("%d\n", ans);
	}
	return 0;
}