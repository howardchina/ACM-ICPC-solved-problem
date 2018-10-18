#include <cstdio>

int main(){
//    freopen("data.in","r",stdin);
    int T,l,g,ans,n,p,t;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&l,&g);
        if(g%l)ans=0;
        else{
            n=g/l;
            p=0;
            ans=1;
            for(int i=2;i<=n;i++){
                if(n%i==0){
                    t=0;
                    do{
                        n/=i;
                        t++;
                    }while(n%i==0);
                    p++;
                    ans*=2*t;
                }
            }
            for(int i=0;i<p;i++)
                ans*=3;
        }
        printf("%d\n",ans);
    }
    return 0;
}
