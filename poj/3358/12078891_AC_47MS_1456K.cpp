#include <stdio.h>
typedef __int64 LL;
const int maxn = 1000000;
bool flag[maxn+5];
int prim[maxn/3], cnt;
void calc_prim(){
    int i,j;
	for(i=2; i<=maxn; i++){
		if(!flag[i]) prim[cnt++]=i;
		for(j=0; j<cnt && prim[j]*i<=maxn; j++){
			flag[i*prim[j]]=1;
			if(i%prim[j]==0) break;
		}
	}
}

LL Eular(LL n)
{
    LL res=n;
    if(n==1)return 0;
    for(int i=0;i<cnt;i++)if(n%prim[i]==0){
        res=res/prim[i]*(prim[i]-1);
        while(n%prim[i]==0)
            n/=prim[i];
        if(n==1)break;
    }
    if(n!=1) res=res/n*(n-1);
    return res;
}

int Gcd(LL a,LL b)
{
    if(a<b)a^=b^=a^=b;
    while(b){
        a%=b;
        a^=b^=a^=b;
    }
    return a;
}

LL PowMod(LL n,LL mod)
{
    LL res=1,x=2%mod;
    while(n){
        if(n&1) res=res*x%mod;
        x=x*x%mod;
        n>>=1;
    }
    return res;
}

LL Femat(LL phi,LL p)
{
    LL i,i0,mini=(LL)1<<60;
    for(i=1;i*i<=phi;i++)if(phi%i==0){
        if(PowMod(i,p)==1) return i;
        i0=phi/i;
        if(PowMod(i0,p)==1&&i0<mini) mini=i0;
    }
    return mini;
}

int main()
{
//    freopen("test.in","r",stdin);
    calc_prim();
    LL p,q,x,a,eu;
    int kase=0;
    while(~scanf("%I64d/%I64d",&p,&q)){
        if(p==0){
            printf("Case #%d: %d,%d\n",++kase,1,1);
            continue;
        }
        x=Gcd(p,q);
        p/=x;
        q/=x;
        a=0;
        while(q%2==0){
            q/=2;
            ++a;
        }
        ++a;
        eu=Eular(q);
        if(eu!=0)eu=Femat(eu,q);
        printf("Case #%d: %I64d,%I64d\n",++kase,a,eu);
    }
    return 0;
}
