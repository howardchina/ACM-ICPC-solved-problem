#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define LL long long
char s[110000];
LL a[110000];
int main()
{
    int t;
    scanf("%d",&t);
    a[0]=0;
    for(int ca=1;ca<=t;ca++)
    {
        scanf("%s",s);
        int l=strlen(s),la=0,lw=-1;
        LL ans=0,cnt=0;
        for(int i=1;i<=l;i++)
        {
            if(i==l||s[i]!=s[i-1])
            {
                a[++la]=i-1-lw;
                ans+=a[la]*a[la];
                lw=i-1;
            }
        }
        a[++la]=0;
        LL lans=ans;
        for(int i=1;i<la;i++)
        {
            if(a[i]==1)
            {
                LL len=a[i-1]+a[i+1]+1;
                lans=max(lans,ans+len*len-a[i-1]*a[i-1]-a[i+1]*a[i+1]-1);
            }
            else
            {
                lans=max(lans,ans+2*a[i-1]-2*a[i]+2);
                lans=max(lans,ans+2*a[i+1]-2*a[i]+2);
            }
            //cout<<i<<" "<<lans<<endl;
        }
        printf("Case #%d: %I64d\n",ca,lans);
    }
    return 0;
}
