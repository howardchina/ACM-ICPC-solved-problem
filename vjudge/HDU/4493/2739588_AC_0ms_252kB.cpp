#include <cstdio>
#include <cstdlib>
#include <cmath>
typedef long long LL;
int main(){
//    freopen("data.in","r",stdin);
    int T;
    double ans,x;
    scanf("%d",&T);
    while(T--){
        ans=0;
        for(int i=0;i<12;i++){
            scanf("%lf",&x);
            ans+=x;
        }
//        ans=0.08*12;
        LL ot=round(ans*100/12);
        LL x=ot/100;
        LL y=ot%100/10;
        LL z=ot%10;
        printf("$%I64d",x);
        if(y||z){
            printf(".%I64d",y);
            if(z)printf("%I64d",z);
        }
        puts("");
    }
    return 0;
}
