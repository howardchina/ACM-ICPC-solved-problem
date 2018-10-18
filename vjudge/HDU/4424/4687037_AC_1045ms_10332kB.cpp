#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define LL long long
struct Node
{
    LL cnt;
    LL ans;
}node[200010];
int fu[200010];
int findx(int x)
{
    if(fu[x]==x)return x;
    return fu[x]=findx(fu[x]);
}

struct Edg
{
    int a,b,c;
    bool operator < (const Edg &rhs)const{
        return c>rhs.c;
    }
}edge[200010];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
        {
            node[i].cnt=1;
            node[i].ans=0;
            fu[i]=i;
        }
        for(int i=0;i<n-1;i++)
          scanf("%d%d%d",&edge[i].a,&edge[i].b,&edge[i].c);
        sort(edge,edge+n-1);
        for(int i=0;i<n-1;i++)
        {
            int l=findx(edge[i].a);
            int r=findx(edge[i].b);
            LL lans=node[l].ans+node[r].cnt*edge[i].c;
            LL rans=node[r].ans+node[l].cnt*edge[i].c;
            if(lans<rans)
            {
                fu[l]=r;
                node[r].cnt+=node[l].cnt;
                node[r].ans=rans;
            }
            else
            {
                fu[r]=l;
                node[l].cnt+=node[r].cnt;
                node[l].ans=lans;
            }
        }
        printf("%I64d\n",node[findx(1)].ans);
    }
    return 0;
}
