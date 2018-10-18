#include <stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
const int maxn=10005;
int mul[maxn];
int flg[maxn];
long long C[maxn][5];
int main()
{
    int i,j,n,top,t;
    long long ans;
    for(i=0;i<maxn;i++)flg[i]=-1;
    for(i=2; i<maxn; i++) if(flg[i]==-1){
        for(j=i; j<maxn; j+=i){
            if(flg[j]==-1) flg[j]=1;
            else if(flg[j]) ++flg[j];
            if(j%(i*i)==0) flg[j]=0;
        }
    }
    C[0][0]=1;
    for(i=1; i<maxn; i++){
        C[i][0]=1;
        for(j=1; j<5; j++){
            C[i][j]=C[i-1][j-1]+C[i-1][j];
        }
    }
    while(~scanf("%d",&n)){
        top=0;
        for(i=0;i<maxn;i++) mul[i]=0;
        for(i=1;i<=n;i++){
            scanf("%d",&t);
            top=max(top,t);
            for(j=1;j*j<=t;j++){
                if(!(t%j)){
                    mul[j]++;
                    if(t!=j*j) mul[t/j]++;
                }
            }
        }
        ans=C[n][4];
        for(i=2;i<=top;i++){
            if(flg[i]==0) continue;
            if(flg[i]&1) ans-=C[mul[i]][4];
            else ans+=C[mul[i]][4];
        }
        printf("%I64d\n",ans);
    }
}
