#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<algorithm>
#define LL long long
using namespace std;
int n;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
struct rabbit
{
    int x,y;
    int v;
    int w;//dongnanxibei
    int t;
}tom,jerry;
void go(rabbit &a)
{
    a.x+=dx[a.w]*a.v;
    if(a.x<1){a.x=2-a.x;a.w^=2;}
    if(a.x>n){a.x=2*n-a.x;a.w^=2;}
    a.y+=dy[a.w]*a.v;
    if(a.y<1){a.y=2-a.y;a.w^=2;}
    if(a.y>n){a.y=2*n-a.y;a.w^=2;}
}
int main()
{
    int k;
    while(scanf("%d",&n)&&n)
    {
        char s[10];
        scanf("%s%d%d",s,&tom.v,&tom.t);
        if(s[0]=='E')tom.w=0;
        if(s[0]=='S')tom.w=1;
        if(s[0]=='W')tom.w=2;
        if(s[0]=='N')tom.w=3;
        tom.x=tom.y=1;
        scanf("%s%d%d",s,&jerry.v,&jerry.t);
        if(s[0]=='E')jerry.w=0;
        if(s[0]=='S')jerry.w=1;
        if(s[0]=='W')jerry.w=2;
        if(s[0]=='N')jerry.w=3;
        jerry.x=jerry.y=n;
        //printf("tom%d %d\njerry%d %d\n",tom.w,tom.v,jerry.w,jerry.v);
        scanf("%d",&k);
        for(int i=1;i<=k;i++)
        {
            go(tom);
            go(jerry);
            //printf("tom%d %d\njerry%d %d\n",tom.x,tom.y,jerry.x,jerry.y);
            if(tom.x==jerry.x&&tom.y==jerry.y)
                swap(tom.w,jerry.w);
            else
            {
                if(i%tom.t==0)tom.w=(tom.w+3)%4;
                if(i%jerry.t==0)jerry.w=(jerry.w+3)%4;
            }
        }
        printf("%d %d\n%d %d\n",tom.x,tom.y,jerry.x,jerry.y);
    }
    return 0;
}
