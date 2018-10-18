#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN=111111,MOD=3;
int v[4*MAXN][3],lazy[4*MAXN];
int ql,qr;
int ans;
void pushup(int o){
    for(int i=0;i<3;i++)
        v[o][i]=v[o<<1][i]+v[(o<<1)|1][i];
}
void pushdown(int o){
    int ls=o<<1,rs=ls|1,tmp;
    if(lazy[o]){
        lazy[ls]=(lazy[ls]+lazy[o])%MOD;
        lazy[rs]=(lazy[rs]+lazy[o])%MOD;
        if(lazy[o]==1){
            tmp=v[ls][0];
            v[ls][0]=v[ls][2];
            v[ls][2]=v[ls][1];
            v[ls][1]=tmp;
        }else if(lazy[o]==2){
            tmp=v[ls][0];
            v[ls][0]=v[ls][1];
            v[ls][1]=v[ls][2];
            v[ls][2]=tmp;
        }
        if(lazy[o]==1){
            tmp=v[rs][0];
            v[rs][0]=v[rs][2];
            v[rs][2]=v[rs][1];
            v[rs][1]=tmp;
        }else if(lazy[o]==2){
            tmp=v[rs][0];
            v[rs][0]=v[rs][1];
            v[rs][1]=v[rs][2];
            v[rs][2]=tmp;
        }
        lazy[o]=0;
    }
}

void Build(int o,int l,int r){
    lazy[0]=0;
    if(l==r){
        v[o][0]=1;
        v[o][1]=v[o][2]=0;
        return;
    }
    int m=(l+r)>>1;
    Build(o<<1,l,m);
    Build((o<<1)|1,m+1,r);
    pushup(o);
}
void update(int o,int l,int r){
    if(ql<=l && r<=qr){
        lazy[o]=(lazy[o]+1)%MOD;
        int tmp=v[o][0];
        v[o][0]=v[o][2];
        v[o][2]=v[o][1];
        v[o][1]=tmp;
        return;
    }
    pushdown(o);
    int M=(l+r)/2,ls=o<<1,rs=ls|1;
    if(ql<=M) update(ls,l,M);
    if(qr>M) update(rs,M+1,r);
    pushup(o);
}
void Query(int o,int l,int r){
    if(ql<=l && r<=qr){
        ans+=v[o][0];
        return;
    }
    pushdown(o);
    int M=(l+r)>>1;
    if(ql<=M) Query(o<<1,l,M);
    if(qr>M) Query((o<<1)|1,M+1,r);
}
int main()
{
//    freopen("data.in","r",stdin);
    int N,Q,op,a,b;
    while(scanf("%d%d",&N,&Q)!=EOF){
        Build(1,1,N);
        while(Q--){
            scanf("%d%d%d",&op,&a,&b);
            ql=a+1,qr=b+1;
            if(op==1){
                ans=0;
                Query(1,1,N);
                printf("%d\n",ans);
            }else
                update(1,1,N);
        }
    }
    return 0;
}
