#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define Clear(x) memset(x,0,sizeof x)
int sw[222][222],so[222][222],dp[222][222];
char s[222];
int main()
{
//    freopen("data.in","r",stdin);
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        scanf("%s",s);
        Clear(dp);
        Clear(sw);
        Clear(so);
        for(int i=0;i<n;i++){
            sw[i][i]=s[i]=='1';
            so[i][i]=s[i]=='0';
            for(int j=i+1;j<n;j++){
                sw[i][j]=sw[i][j-1]+(s[j]=='1');
                so[i][j]=so[i][j-1]+(s[j]=='0');
            }
        }
        for(int i=0;i<n;i++)
        for(int j=0;j<n-i;j++){//!
            if(sw[j][j+i]>so[j][j+i])
                dp[j][j+i]=i+1;
            else
                for(int k=0;k<i;k++)
                dp[j][j+i]=max(dp[j][j+i],dp[j][j+k]+dp[j+k+1][j+i]);
        }
        printf("%d\n",dp[0][n-1]);
    }
    return 0;
}
