#include <stdio.h>
const int maxn=100000;
bool flag[maxn+5];
int prim[maxn/3], cnt;
//时间复杂度O(n), 空间复杂度为O(n), 不宜直接开prim[maxn]
//这样会由于开比较大的内存，使得时间复杂度提高，由于素数分布的比较少
//所以，只需要开maxn的1/3或者1/4就可以了
void calc_prim(){
	for(int i = 2; i <= maxn; i ++){
		if(!flag[i]) prim[cnt++] = i;
		for(int j = 0; j < cnt && prim[j]*i <= maxn; j ++){
			flag[i*prim[j]] = 1;
			if(i%prim[j]==0) break;
		}
	}
}

int num[50];
int p[50];
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
    int i,j,n,res;
    calc_prim();
    while(scanf("%d",&n)){
        if(n==0)break;
        getfac(n);
        res=1;
        for(i=0;i<L;i++){
            res*=(num[i]-1);
            for(j=0;j<p[i]-1;j++){
                res*=num[i];
            }
        }
        printf("%d\n",res);
    }


    return 0;
}
