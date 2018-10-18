#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int a[1001000];
int main()
{
    int t,n;
    scanf("%d",&t);
    for(int ca=1;ca<=t;ca++)
    {
        int ans=0,d;
        scanf("%d",&n);
        d=n+1;
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=n;i>=1;i--)
            if(a[i]<d)d=a[i];
            else
                ans++;
        printf("Case #%d: %d\n",ca,ans);
    }
}
