#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<vector>
using namespace std;
vector <int> prime;
int ok[1010]={},two[1010][2],ans[1010][3];
int main()
{
    int T;
    scanf("%d",&T);
    prime.push_back(2);
    for(int i=3;i<1000;i+=2)
    {
        int f=1;
        for(int j=3;j*j<=i&&f;j+=2)
            if(i%j==0)f=0;
        if(f==1)prime.push_back(i);
    }
    int l=prime.size();
    for(int i=0;i<l;i++)
        for(int j=i;j<l&&prime[i]+prime[j]<1000;j++)
            if(ok[prime[i]+prime[j]]==0)
            {
                ok[prime[i]+prime[j]]=1;
                two[prime[i]+prime[j]][0]=prime[i];
                two[prime[i]+prime[j]][1]=prime[j];
            }
    for(int i=4;i<=997;i++)
    {
        if(ok[i])
        {
            for(int j=0;j<l&&prime[j]+i<=999;j++)
            {
                if(ans[i+prime[j]][0]==0)
                {
                    ans[i+prime[j]][0]=two[i][0];
                    ans[i+prime[j]][1]=two[i][1];
                    ans[i+prime[j]][2]=prime[j];
                    sort(ans[i+prime[j]],ans[i+prime[j]]+3);
                }
            }
        }
    }
    while(T--)
    {
        int K;
        scanf("%d",&K);
        if(ans[K][0]==0)printf("0\n");
        else printf("%d %d %d\n",ans[K][0],ans[K][1],ans[K][2]);
    }
    return 0;
}
