#include <cstdio>
#include <cstring>
typedef long long LL;
const int maxn=1001000;
LL h[maxn],p[maxn];
char s[maxn];
int main(){
//    freopen("data.in","r",stdin);
    p[0]=1;
    for(int i=1;i<maxn;i++) p[i]=p[i-1]*7;
    while(gets(s)&&s[0]!='.'){
        int n,m,ans;
        n=strlen(s);
        m=n+1/2;
        h[n]=0;
        for(int i=n-1;~i;i--)
            h[i]=h[i+1]*7+s[i]-'a'+1;
        LL nod;
        bool flag=false;
        for(ans=1;ans<=m;ans++){
            if(n%ans) continue;
            nod=h[0]-h[ans]*p[ans];
            flag=true;
            for(int j=ans;j<=n;j+=ans){
                if(h[j-ans]!=h[j]*p[ans]+nod){
                    flag=false;
                    break;
                }
            }
            if(flag) break;
        }
        if(flag&&ans<=m) printf("%d\n",n/ans);
        else puts("1");
    }
    return 0;
}
