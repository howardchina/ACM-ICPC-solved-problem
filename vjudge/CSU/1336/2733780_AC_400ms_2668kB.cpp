#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
const LL INF=0x3f3f3f3f3f3fLL;
LL f[101111];
int ap[11],ad[11],mu[11],ff[101111];
int main()
{
//    freopen("data.in","r",stdin);
    int x,y,cas=1,t1,t2;
    while(scanf("%d%d",&x,&y)!=EOF){
        for(int i=0;i<10;i++)
            scanf("%d",&ap[i]);
        for(int i=0;i<10;i++)
            scanf("%d",&ad[i]);
        for(int i=0;i<10;i++)
            scanf("%d",&mu[i]);
        for(int i=0;i<=y;i++){
            f[i]=INF;
            ff[i]=0x3f3f3f3f;
        }
        f[x]=0;
        ff[x]=0;

        t1=f[x]+mu[0],t2=ff[x]+1;
        if(f[0]>t1||(f[0]==t1 && ff[0]>t2)){
            f[0]=t1;
            ff[0]=t2;
        }

        for(int i=0;i<=y;i++){
            t1=f[i/10]+ap[i%10],t2=ff[i/10]+1;
            if(f[i]>t1||(f[i]==t1 && ff[i]>t2)){
                f[i]=t1;
                ff[i]=t2;
            }
            for(int j=0;j<10;j++){
                if(i-j<0) break;
                t1=f[i-j]+ad[j],t2=ff[i-j]+1;
                if(f[i]>t1||(f[i]==t1 && ff[i]>t2)){
                    f[i]=t1;
                    ff[i]=t2;
                }
            }
            for(int j=1;j<10;j++){
                if(i%j==0){
                    t1=f[i/j]+mu[j],t2=ff[i/j]+1;
                    if(f[i]>t1||(f[i]==t1 && ff[i]>t2)){
                        f[i]=t1;
                        ff[i]=t2;
                    }
                }
            }
        }
        printf("Case %d: %lld %d\n",cas++,f[y],ff[y]);
    }
    return 0;
}
