#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
struct Ant{
    int d,p,id,tim;
}ant[22];
int vis[111];
int main()
{
//    freopen("data.in","r",stdin);
    int N,n,l,p;
    char s[11];
    while(scanf("%d%d",&N,&l)!=EOF &&N+l){
        n=N;
        for(int i=0;i<n;i++){
            scanf("%s %d",s,&p);
            ant[i].d = s[0]=='L'?0:1;
            ant[i].p = p;
            ant[i].id = i+1;
            ant[i].tim = 0;
        }
        int when=0,id=-1,d=-1;
        while(n){
            memset(vis,0,sizeof vis);
            for(int i=0;i<n;i++){
                if(ant[i].p==0 || ant[i].p==l){
                    if(ant[i].tim>when || (ant[i].tim == when && ant[i].d==0)){
                        when = ant[i].tim;
                        id = ant[i].id;
                        d = ant[i].d;
                    }
                    ant[i]=ant[n-1];
                    n--;
                    i--;
                    continue;
                }
                if(ant[i].d==0){
                    ant[i].p--;
                    if(vis[ant[i].p]==0 || vis[ant[i].p]==2) vis[ant[i].p]++;
                }else{
                    ant[i].p++;
                    if(vis[ant[i].p]==0 || vis[ant[i].p]==1) vis[ant[i].p]+=2;
                }
                ant[i].tim++;
            }
            for(int i=0;i<n;i++){
                if(vis[ant[i].p]==3)
                    ant[i].d^=1;
            }
        }
        printf("%d %d\n",when,id);
    }
    return 0;
}
