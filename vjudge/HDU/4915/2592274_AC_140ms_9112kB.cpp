#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
char s[1000100];
int l[1000100],r[1000100];
int main()
{
    int len;
    while(scanf("%s",&s)!=EOF)
    {
        len=strlen(s);
        memset(l,0,sizeof l);
        memset(r,0,sizeof r);
        int l1=0,r1=0,getz=0,ans=0,z=0;
        if(len&1)ans=-1;
        else
        for(int i=0;i<len;i++)
        {
            if(s[i]==')')
            {
                if(l[i]==0)
                    l[i]++;
                else
                    l[i]--;
                if(r[i]>0)
                    r[i]--;
                else
                {
                    ans=-1;
                    break;
                }
            }
            else if(s[i]=='(')
            {
                l[i]++;
                r[i]++;
            }
            else if(s[i]=='?')
            {
                if(l[i]>0)
                    l[i]--;
                else
                    l[i]++;
                r[i]++;
            }
            l[i+1]=l[i];
            r[i+1]=r[i];
           // cout<<l[i]<<r[i]<<endl;
        }
        if(ans!=-1)
        for(int i=len-1;i>0;i--)
        {
            if(s[i]=='(')
            {
                if(l1==0)
                    l1++;
                else
                    l1--;
                if(r1>0)
                    r1--;
                else
                {
                    ans=-1;
                    break;
                }
            }
            else if(s[i]==')')
            {
                l1++;
                r1++;
            }
            else if(s[i]=='?')
            {
                if(l1>0)
                    l1--;
                else
                    l1++;
                r1++;
            }
            if(min(r1,r[i-1])-max(l1,l[i-1])==0)
                ans=max(ans,0);
            if(min(r1,r[i-1])-max(l1,l[i-1])>=2)
                ans=max(ans,1);
           // cout<<l1<<r1<<endl;
        }

        if(ans==-1)
        printf("None\n");
        else if(ans==0)
        printf("Unique\n");
        else if(ans==1)
        printf("Many\n");
    }
    return 0;
}