#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int ans[500]={};
int mr[10]={-1,2,3,-1,5,6,-1,8,9,-1};
int md[10]={-1,4,5,6,7,8,9,-1,0,-1};
void dfs(int i,int x)
{
    //cout<<i<<" "<<x<<"!!!!!";
    if(ans[x]==0)
        ans[x]=1;
    if(x==0&&i==0)return ;
    if(x*10+i<=200)
    dfs(i,x*10+i);
    if(mr[i]!=-1)
    dfs(mr[i],x);
    if(md[i]!=-1)
    dfs(md[i],x);
}
int main()
{
    int T ;
    scanf("%d", &T) ;
    dfs(1,0);
    //for(int i=0;i<=200;i++)
    //if(ans[i])cout<<i<<endl;
    while(T--) {
        int n ;
        scanf("%d", &n) ;
        for(int d=0;d<=200;d++)
        {
            if(ans[n+d])
            {
                printf("%d\n",n+d);
                break;
            }
            if(ans[n-d])
            {
                printf("%d\n",n-d);
                break;
            }
        }
    }
    return 0;
}