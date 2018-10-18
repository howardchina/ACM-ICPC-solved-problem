#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<vector>
using namespace std;
int board[210]={};
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m,x=0,y=0,a;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++)
        {
            scanf("%d",&a);
            x=x*10+a;
        }
        for(int i=1;i<=m;i++)
        {
            scanf("%d",&a);
            y=y*10+a;
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&board[i]);
            board[i+n]=board[i];
        }
        int ans=0;
        //printf("%d %d %d\n",x,y,ans);
        for(int i=1;i<=n;i++)
        {
            int now=0;
            for(int j=0;j<m;j++)
                now=now*10+board[i+j];
            if(now>=x&&now<=y)ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
