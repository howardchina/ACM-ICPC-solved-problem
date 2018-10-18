#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>
using namespace std;
char mm[100][100];
int mc[100][100];
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%s",&mm[i]);
            for(int j=0;j<n;j++)
            {
                if(mm[i][j]>='a'&&mm[i][j]<='z')
                    mc[i][j]=mm[i][j]-'a';
                if(mm[i][j]=='.')
                    mc[i][j]=26;
                if(mm[i][j]=='#')
                    mc[i][j]=27;
            }
        }
        int ans=0;
        for(int i=0;i<n/2;i++)
        {
            for(int j=i;j<=n/2;j++)
            {
                if(i==j&&j==n/2)break;
                int cnt[30]={};
                cnt[mc[i][j]]++;
                cnt[mc[n-1-i][j]]++;
                cnt[mc[i][n-1-j]]++;
                cnt[mc[n-1-i][n-1-j]]++;
                cnt[mc[j][i]]++;
                cnt[mc[j][n-1-i]]++;
                cnt[mc[n-1-j][i]]++;
                cnt[mc[n-1-j][n-1-i]]++;
                int s=0;
                for(int k=0;k<=27;k++)
                    s=max(s,cnt[k]);
                if(j!=i&&j!=n/2)
                    ans+=(8-s);
                else
                    ans+=((8-s)/2);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
