#include <stdio.h>
typedef long long u64;
const int maxn=900000;
bool flag[maxn+5];
u64 prim[maxn/3], cnt;
void calc_prim(){
	for(int i = 2; i <= maxn; i ++){
		if(!flag[i]) prim[cnt++] = i;
		for(int j = 0; j < cnt && prim[j]*i <= maxn; j ++){
			flag[i*prim[j]] = 1;
			if(i%prim[j]==0) break;
		}
	}
}

u64 Eular(u64 n)
{
    u64 i,res=n;
    for(i=0;i<cnt&&prim[i]<=n;i++)if(n%prim[i]==0){
            res-=res/prim[i];
            while(n%prim[i]==0)
                n/=prim[i];
    }
    if(i==cnt)
        res--;
    return res;
}

int main()
{
//    freopen("test.in","r",stdin);
    u64 n;
    calc_prim();
    while(scanf("%lld",&n)){
        if(n==0)break;
        printf("%lld\n",Eular(n));
    }
    return 0;
}
