#include <stdio.h>

int count(int n)
{
    int res=0;
    while(n){
        n/=2;
        res+=n;
    }
    return res;
}

int main()
{
    int t,m,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m)
        if(count(n-m-(m-1)/2)==count(n-m)+count((m-1)/2))
            puts("1");
        else
            puts("0");
    }
    return 0;
}
