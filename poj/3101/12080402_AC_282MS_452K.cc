#include <stdio.h>

const int N=1000;
const int maxn=10000;
int t[N+5];
int fac[maxn/3];
int res[maxn+5];
bool flag[maxn+5];
int prim[maxn/3], cnt;
void calc_prim(){
	for(int i = 2; i <= maxn; i ++){
		if(!flag[i]) prim[cnt++] = i;
		for(int j = 0; j < cnt && prim[j]*i <= maxn; j ++){
			flag[i*prim[j]] = 1;
			if(i%prim[j]==0) break;
		}
	}
}

int Abs(int x)
{
    if(x<0) return -x;
    return x;
}

int Gcd(int a,int b)
{
    while(b){
        a%=b;
        a^=b^=a^=b;
    }
    return a;
}

void Getfac(int x)
{
    int i=0,t;
    for(i=0;i<cnt&&x>1;i++)if(x%prim[i]==0){
        t=0;
        while(x%prim[i]==0){
            x/=prim[i];
            t++;
        }
        if(fac[i]<t) fac[i]=t;
    }
}

int main()
{
//    freopen("test.in","r",stdin);
    int i,j,v,n,fm,k,a,b,temp,id;
    calc_prim();
    while(~scanf("%d",&n)){
        for(i=0;i<n;i++)
            scanf("%d",&t[i]);
        for(i=0;i<cnt;i++) fac[i]=0;
        fm=0;
        for(i=1;i<n;i++){
            a=Abs(t[i]-t[0])<<1;
            b=t[i]*t[0];
            k=Gcd(a,b);
            a/=k,b/=k;
            fm=Gcd(fm,a);
            Getfac(b);
        }
        for(i=0;i<maxn;i++) res[i]=0;
        res[0]=1;
        for(i=0;i<cnt;i++){
            for(j=0;j<fac[i];j++){
                temp=0;
                for(v=0;v<=maxn;v++){
                    res[v]=res[v]*prim[i]+temp;
                    temp=res[v]/maxn;
                    res[v]%=maxn;
                }
            }
        }
        id=maxn;
        while(res[id]==0) id--;
        printf("%d",res[id--]);
        while(id>=0)
            printf("%04d",res[id--]);
        printf(" %d\n",fm);
    }
    return 0;
}
