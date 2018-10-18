#include <stdio.h>
const int maxn = 100000 + 10;
int pre[maxn], dist[maxn], n;

int Find(int a)
{
    if(pre[a] != a)
    {
        int tem = Find(pre[a]);
        dist[a] = dist[pre[a]] + dist[a];
        return pre[a] = tem;
    }
    else
        return a;
}
int main()
{
//    freopen("test.in","r",stdin);
    int i,m,n,a,b,fa,fb,w,cha;
    char op;
    while(~scanf("%d%d",&m,&n)){
        if(m+n==0) break;
        for(i=1;i<=m;i++){
            pre[i]=i;
            dist[i]=0;
        }
        while(n--){
            getchar();
            scanf("%c",&op);
            if(op=='!'){
                scanf("%d%d%d",&a,&b,&w);
                fa=Find(a);
                fb=Find(b);
                if(fa!=fb){
                    pre[fb]=fa;
                    dist[fb]=dist[a]+w-dist[b];
                }
            }else if(op=='?'){
                scanf("%d%d",&a,&b);
                fa=Find(a);
                fb=Find(b);
                if(fa!=fb)
                    puts("UNKNOWN");
                else
                    printf("%d\n",dist[b]-dist[a]);
            }
        }
    }
    return 0;
}
