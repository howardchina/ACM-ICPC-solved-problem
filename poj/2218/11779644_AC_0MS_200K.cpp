#include<iostream>
#include<stdio.h>
#include<string.h>
#include<cstdlib>
#include<algorithm>
using namespace std;
struct People
{
       char name[30];
       int w;
}p[120];

bool cmp(const People & p1,const People & p2)
{
     return p1.w>p2.w;
}

int main()
{
    char ss[10];
    int i,m,t,n;
    while(scanf("%s",ss)!=EOF)
    {
       n=0;
       while(scanf("%s",p[n].name)!=EOF)
       {
           if(strcmp(p[n].name,"END")==0)
              break;
           scanf("%d%d",&t,&m);
           p[n++].w=m-t;
       }
       sort(p,p+n,cmp);
       for(i=0;i<n;i++)
        printf("%s\n",p[i].name);
       printf("\n");
    }
    system("pause");
    return 0;
}
