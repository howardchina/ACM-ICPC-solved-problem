#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 110
int main(){
	int i,j,k,n,res,mx;
	while(~scanf("%d",&n)){
		for(i=1,k=mx=res=0;i<=n;i++){
			scanf("%d",&j);
			res+=j;
			if(j==1){if(k>0)k--;}
			else k++;
			mx=max(mx,k);
		}
		res+=mx;
		if(mx<=0)res--;
		printf("%d\n",res);
	}
return 0;
}