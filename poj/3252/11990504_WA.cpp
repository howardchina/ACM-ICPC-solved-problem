#include <stdio.h>
int C[32][32]={{0}};
void Init()
{
    int i,j;
    C[0][0]=1;
    for(i=1; i<32; i++){
        C[i][0]=1;
        for(j=1; j<32; j++){
            C[i][j]=C[i-1][j-1]+C[i-1][j];
        }
    }
}

int count(int n)
{
    int i,j,L=0,zer=0,one=1,res=0;
    bool d[32]={0};
    while(n){
        d[L]=n&1;
        n>>=1,L++;
    }
    for(i=1;i<=L-1;i++)for(j=(i+1)/2;j<=i-1;j++)
        res+=C[i-1][j];
    for(i=L-1;i>=1;i--){
        if(d[i-1]){
            for(j=i/2-(zer-one+1);j<=i;j++)
                res+=C[i-1][j];
            one++;
        }else{
            zer++;
        }
    }
    return res+(zer>=one);
}

int main()
{
    int s,f;
    Init();
    scanf("%d%d",&s,&f);
    printf("%d",count(f)-count(s-1));
    return 0;
}
