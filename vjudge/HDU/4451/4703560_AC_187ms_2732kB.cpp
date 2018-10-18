#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<algorithm>
#define LL long long
using namespace std;
bool ct[1010][1010];
int nk[1010];
char s1[10],s2[10];
int main()
{
    int n,m,k,p;
    while(scanf("%d%d%d",&n,&m,&k)&&n)
    {
        int ans=0;
        memset(ct,0,sizeof ct);
        scanf("%d",&p);
        for(int i=1;i<=m;i++)
            nk[i]=k;
        for(int i=1;i<=p;i++)
        {
            int x,y;
            scanf("%s%d%s%d",s1,&x,s2,&y);
            if(s1[0]=='c')ct[x][y]=1;
            else nk[x]--;
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            if(!ct[i][j])
            ans+=nk[j];
        printf("%d\n",ans);
    }
    return 0;
}
