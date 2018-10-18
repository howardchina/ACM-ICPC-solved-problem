#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

typedef long long LL;

const int maxn = 15;
char s[maxn];
int pre[maxn];
int len;

void pro(){
    for(int m=0;m<len;m++){
        int l = len-1-m;
        int ok=1;
        for(int i=0;i<=m;i++){
            if(s[i]!=s[l+i]){
                ok=0;
                break;
            }
        }
        if(ok){
            pre[m]=1;
        }else{
            pre[m]=0;
        }
    }
}

LL fastpow(LL a,int b){
    LL re=1;
    while(b){
        if(b&1) re*=a;
        a*=a;
        b>>=1;
    }
    return re;
}

int main()
{
//    freopen("data.in","r",stdin);
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++){
        int n;
        scanf("%d",&n);
        scanf("%s",s);
        len = strlen(s);
        LL ans=0;
        pro();
        for(int i=0;i<len;i++){
            if(pre[i]){
                ans += fastpow(n,i+1);
            }
        }
        printf("Case %d:\n%lld\n",cas,ans);
        if(cas<T) puts("");
    }
}
