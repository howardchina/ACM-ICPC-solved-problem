#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    char s[1100];
    scanf("%d",&t);
    for(int ca=1;ca<=t;ca++)
    {
        scanf("%s",s);
        int w[30],l=strlen(s);
        memset(w,-1,sizeof w);
        int ans=1001;
        for(int i=0;i<l;i++)
        {
            if(w[s[i]-'a']!=-1)
                ans=min(ans,i-w[s[i]-'a']);
            w[s[i]-'a']=i;
        }
        if(ans==1001)ans=-1;
        printf("Case #%d: %d\n",ca,ans);
    }
    return 0;
}
