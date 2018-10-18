#include <stdio.h>
typedef long long u64;
const int maxn=1000000;
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

u64 num[70];
int p[70];
int L;
void getfac(int n)
{
    int i=0;
    L=0;
    while(n>1&&i<=cnt){
        if(!(n%prim[i])){
            num[L]=prim[i];
            p[L]=0;
            while(!(n%prim[i])){
                n/=prim[i];
                p[L]++;
            }
            L++;
        }
        i++;
    }
    if(n>1){
        num[L]=n;
        p[L++]=1;
    }
}

int main()
{
//    freopen("test.in","r",stdin);
    int i,j;
    u64 n,res;
    calc_prim();
    while(scanf("%lld",&n)){
        if(n==0)break;
        getfac(n);
        res=1;
        for(i=0;i<L;i++){
            res*=(num[i]-1);
            for(j=0;j<p[i]-1;j++){
                res*=num[i];
            }
        }
        printf("%lld\n",res);
    }


    return 0;
}
