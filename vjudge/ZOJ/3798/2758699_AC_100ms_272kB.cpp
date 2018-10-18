#include<iostream>
#include<stdio.h>
using namespace std;
int n;
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int mmin,mmax;
        if(n%4>=1&&n%4<=2)mmin=1;
        else mmin=0;
        if((n-1)%4>=1&&(n-1)%4<=2)mmax=n-1;
        else mmax=n;
        printf("%d %d\n",mmin,mmax);
        for(int i=n;i>=2;i--)
            printf("%d ",i);
        printf("1\n");
        for(int i=n-1;i>=1;i--)
            printf("%d ",i);
        printf("%d\n",n);
    }
}
