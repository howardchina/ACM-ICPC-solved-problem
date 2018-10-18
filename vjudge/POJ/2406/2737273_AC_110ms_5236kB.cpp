#include <cstdio>
#include <cstring>
const int maxn=1001000;
char s[maxn];
int f[maxn];
int solve(){
    int i,j,len;
    len=strlen(s);
    i=0;j=f[0]=-1;
    while(i<len){
        while(j!=-1&&s[i]!=s[j]) j=f[j];
        f[++i]=++j;
    }
    if(len%(len-f[len])==0)
        return len/(len-f[len]);
    return 1;
}
int main(){
//    freopen("data.in","r",stdin);
    while(gets(s)&&s[0]!='.'){
        int ans=solve();
        printf("%d\n",ans);
    }
    return 0;
}
