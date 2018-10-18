#include<stdio.h>
#include<string.h>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

#define rep(i,s,t) for(int i=s;i<t;i++)
typedef unsigned long long ull;

const ull B1=10000007;
const ull B2=100000007;

int t,n,m,x,y,ans;
char s[2222][2222],a[2222][2222];
ull p;
ull tmp[2222][2222],ttmp[2222][2222];

inline ull Hash(){
	ull c,d=0;
	rep(i,0,x){
		c=0;
		rep(j,0,y){
			c=c*B1+a[i][j];
		}
		d=d*B2+c;
	}
	return d;
}

inline void getAns(){
	ull t,a;
	t=1;rep(i,0,y) t*=B1;
	rep(i,0,n){
		a=0;
		rep(j,0,y) a=a*B1+s[i][j];
		tmp[i][y-1]=a;
		rep(j,y,m){
			tmp[i][j]=tmp[i][j-1]*B1-s[i][j-y]*t+s[i][j];
		}
	}
	t=1;rep(i,0,x) t*=B2;
	rep(i,y-1,m){
		a=0;
		rep(j,0,x) a=a*B2+tmp[j][i];
		ttmp[x-1][i]=a;
		if(a==p) ans++;
		rep(j,x,n){
			ttmp[j][i]=ttmp[j-1][i]*B2-tmp[j-x][i]*t+tmp[j][i];
			if(ttmp[j][i]==p) ans++;
		}
	}
}
int main(){
//    freopen("data.in","r",stdin);
	while(scanf("%d%d%d%d",&x,&y,&n,&m)!=EOF){
		rep(i,0,x) scanf("%s",a[i]);
		rep(i,0,n) scanf("%s",s[i]);
		p=Hash();ans=0;
		getAns();
		printf("%d\n",ans);
	}
	return 0;
}
