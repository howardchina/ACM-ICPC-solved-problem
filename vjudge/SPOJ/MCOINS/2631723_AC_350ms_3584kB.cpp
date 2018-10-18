#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
bool dp[1000010];
int main(){
    int K,L,m;
    scanf("%d%d%d",&K,&L,&m);
    dp[0]=0;
    for(int i=0;i<=1000000;i++)
        if(dp[i]==0)
            dp[i+1]=dp[i+K]=dp[i+L]=1;
    while(m--){
        scanf("%d",&K);
        putchar(dp[K]?'A':'B');
    }
    return 0;
}
