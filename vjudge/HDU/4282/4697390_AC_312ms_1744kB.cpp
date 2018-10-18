#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<algorithm>
#define LL long long
using namespace std;
LL ppow(LL x,int b)
{
    LL r=1;
    for(int i=1;i<=b;i++)
        r*=x;
    return r;
}
int main()
{
    int k,ans;
    LL s[33];
    while(scanf("%d",&k)&&k)
    {
        ans=0;
        for(int z=2;z<=30;z++)
        {
            s[z]=(int)pow(k,1.0/z);
            //cout<<"!!!!"<<s[z]<<endl;
            if(s[z]>1)
            for(int x=1;x<=65536&&x<=s[z];x++)
            {
                LL l=1,r=s[z],m,t;
                while(l<r)
                {
                    //cout<<l<<" "<<r<<endl;
                    m=(l+r)>>1;
                    t=ppow(x,z)+ppow(m,z)+x*m*z;
                    if(t>k)r=m-1;
                    if(t<k)l=m+1;
                    if(t==k)l=r=m;
                }
                t=ppow(x,z)+ppow(l,z)+x*l*z;
               // cout<<ppow(x,z)<<" "<<ppow(l,z)<<endl;
                //cout<<z<<" "<<x<<" "<<l<<" "<<t<<endl;
                if(t==k&&l>x){
                        ans++;
                    //cout<<x<<" "<<l<<" "<<z<<endl;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
