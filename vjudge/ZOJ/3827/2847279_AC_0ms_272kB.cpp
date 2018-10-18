#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
//    freopen("data.in","r",stdin);
    int T,N,x;
    double ans,p;
    char S[111];
    scanf("%d",&T);
    while(T--){
        scanf("%d %s",&N,S);
        ans=0;
        for(int i=0;i<N;i++){
            scanf("%d",&x);
            if(x!=0){
                p=1.0*x/100;
                if(S[0]=='b')
                    ans+=p*log2(p);
                else if(S[0]=='n')
                    ans+=p*log(p);
                else ans+=p*log10(p);
            }
        }
        printf("%.12lf\n",-ans);
    }
    return 0;
}
