#include <stdio.h>
typedef __int64 u64;
int prm[]={11,23,29,37,41,43,47,53,59};
//k为prm[]中一个
int MesanCom(int k,u64 fac[])
{
	int num =0;
	u64 n = ((u64)(1)<<k)-1;
	for (int j=1; (u64)(2*k*j+1)*(u64)(2*j*k+1) <= n; j++ )
		if (n % (2*k*j+1) == 0)
		{
			fac[num++] = (u64)(2*k*j+1);
			while (n % (2*k*j+1) == 0)
				n/=(2*k*j+1);
		}
	if (n!=1) fac[num++] = n;
	return num;
}
u64 fac[20];
int main()
{
    u64 n,num;
    while(~scanf("%I64d",&n)){
        for(int i=0;i<9;i++){
            if(prm[i]<=n){
                num=MesanCom(prm[i],fac);
                printf("%I64d",fac[0]);
                for(int j=1;j<num;j++){
                    printf(" * %I64d",fac[j]);
                }
                printf(" = %I64d = ( 2 ^ %d ) - 1\n",(u64)(((u64)1)<<prm[i])-1,prm[i]);
            }else
                break;
        }
    }
    return 0;
}
