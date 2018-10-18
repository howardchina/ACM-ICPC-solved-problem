#include <stdio.h>
const int maxn=20000;
bool hash[maxn+5];

int main()
{
//    freopen("test.in","r",stdin);
    int i,j,t,p,q,mul;
    for(i=1;i<150;i++)
        for(j=0;j<=i;j++)if(i*i+j*j<=maxn)
            hash[i*i+j*j]=true;

    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&p,&q);
        mul=p*p+q*q;
        for(i=2;i<mul;i++)if(hash[i] && mul%i==0 && hash[mul/i]){
            puts("C");
            break;
        }
        if(i==mul)
            puts("P");
    }
    return 0;
}
