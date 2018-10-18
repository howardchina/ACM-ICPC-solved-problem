#include <stdio.h>
typedef long long u64;
const int maxn=431;
u64 np[maxn+1][maxn+1];
u64 prim[maxn+1];
int cnt;
void calc_prim()
{
    int i,j;
    cnt=0;
    for(i=2;i<=maxn;i++)if(!prim[i]){
        prim[cnt++]=i;
        for(j=i+i;j<=maxn;j+=i)
            prim[j]=1;
    }
}

void calc_np()
{
    int i,j,x;
    for(i=2;i<=maxn;i++){
        x=i;j=0;
        while(x>1){
            if(x%prim[j]==0){
                while(x%prim[j]==0){
                    np[i][j]++;
                    x/=prim[j];
                }
            }
            j++;
        }
        for(j=0;prim[j]<=i&&j<cnt;j++){
            np[i][j]+=np[i-1][j];
        }

    }
}

void Init()
{
    calc_prim();
    calc_np();
}

u64 calc(int x,int y)
{
    int i,z=x-y;
    u64 res=1;
    for(i=0;prim[i]<=x;i++)
        res*=(np[x][i]-np[y][i]-np[z][i]+1);
    return res;
}

int main()
{
//    freopen("test.in","r",stdin);
    Init();
    int n,k,nk;
    u64 ans;
    while(~scanf("%d%d",&n,&k)){
        ans=calc(n,k);
        printf("%I64d\n",ans);
    }
    return 0;
}
