#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef long long ll;
struct Node{
    int l,r,v;
};
Node q[10000000];
int bi;

int comp(const void *_a,const void *_b)
{
    Node a=*(Node *)_a;
    Node b=*(Node *)_b;
    if(a.v==b.v){
        return a.l-b.l;
    }else{
        return a.v-b.v;
    }
}
const int maxn = 3000000;
bool flag[maxn+5];
int prim[maxn/3], cnt;
void calc_prim(){
	for(int i = 2; i <= maxn; i ++){
		if(!flag[i]) prim[cnt++] = i;
		for(int j = 0; j < cnt && prim[j]*i <= maxn; j ++){
			flag[i*prim[j]] = 1;
			if(i%prim[j]==0) break;
		}
	}
}

bool is_prim(ll n)
{
    ll r=sqrt(1.0*n);
    for(ll i=0;prim[i]<=r;i++){
        if(n==prim[i])
            return 1;
        else if(n%prim[i]==0)
            return 0;
    }
    return 1;
}

int main()
{
    calc_prim();
    ll L,U,pre;
    Node node;
    while(~scanf("%lld%lld",&L,&U)){
        bi=0;
        pre=-1;
        for(ll i=L;i<=U;i++){
            if(is_prim(i)){
                if(pre==-1){
                    pre=i;
                    continue;
                }else{
                    node.l=pre,node.r=i,node.v=i-pre;
                    q[bi++]=node;
                    pre=i;
                }
            }
        }
        if(bi==0||(bi==1 && q[0].l==L && q[0].r==U)){
            puts("There are no adjacent primes.");
        }else{
            qsort(q,bi,sizeof(Node),comp);
            bi--;
            while(q[bi-1].v==q[bi].v) bi--;
            printf("%d,%d are closest, %d,%d are most distant.\n",q[0].l,q[0].r,q[bi].l,q[bi].r);
        }
    }
}
