#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
int main()
{
    int n,m,t;
    int b[17][18];
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        memset(b,0,sizeof b);
        for(int i=1;i<=n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            for(int j=0;j<x;j++)
                b[y][j]++;
        }
        int ans[110000]={};
        for(int i=0;i<m;i++)
        {
            int tot=0;
            for(int k=1;k<=16;k++)
                tot+=b[k][i%k];
            ans[tot]++;
        }
        for(int i=0;i<=n;i++)
            printf("%d\n",ans[i]);
    }
    return 0;
}
