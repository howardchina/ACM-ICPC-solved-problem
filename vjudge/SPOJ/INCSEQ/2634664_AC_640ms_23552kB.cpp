#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MOD=5000000,MAXN=100005;
int seg[51][MAXN],a[MAXN],b[MAXN],id[MAXN],N,K,n;

void add(int k,int x,int v){
    while(x<=n){
        seg[k][x]+=v;
        if(seg[k][x]>=MOD)seg[k][x]-=MOD;
        x+=x&(-x);
    }
}
int query(int k,int x){
    int s=0;
    while(x){
        s+=seg[k][x];
        if(s>=MOD)s-=MOD;
        x-=x&(-x);
    }
    return s;
}

int main(){
    scanf("%d%d",&N,&K);
    for(int i=0;i<N;i++){
        scanf("%d",a+i);
        b[i]=a[i];
    }
    sort(b,b+N);
    n=1;
    id[b[0]]=n++;
    for(int i=1;i<N;i++){
        if(b[i]!=b[i-1])
            id[b[i]]=n++;
    }
    for(int i=0;i<N;i++)
        b[i]=1;
    for(int j=1;j<=K;j++)
    for(int i=0;i<N;i++){
        add(j,id[a[i]],b[i]);
        b[i]=query(j,id[a[i]]-1);
    }
    printf("%d\n",query(K,n));
    return 0;
}