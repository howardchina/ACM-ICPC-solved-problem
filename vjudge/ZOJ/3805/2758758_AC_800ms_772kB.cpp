#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
int n;
vector<int>son[10010];
int dfs(int x)
{
    int l,r;
    if(son[x].size()==0)return 1;
    if(son[x].size()==1)return dfs(son[x][0]);
    else
    {
        l=dfs(son[x][0]),r=dfs(son[x][1]);
        if(l>r)swap(l,r);
        return max(l+1,r);
    }
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int x;
        son[1].clear();
        for(int i=2;i<=n;i++)
        {
            son[i].clear();
            scanf("%d",&x);
            son[x].push_back(i);
        }
        printf("%d\n",dfs(1));
    }
}
