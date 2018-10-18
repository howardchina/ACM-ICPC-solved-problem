#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int cell[1010][1010],ans[1010][1010],n,m;

void get(int i,int j)
{
    int sum=cell[i][j]-ans[i][j-1]-ans[i+1][j-1];
    ans[i][j]=sum>3?1:0;
    if (i==n) return;
    if (j>1)
        ans[i+1][j]=cell[i][j-1]-(ans[i][j-1]?4:0)-ans[i][j-2]-ans[i+1][j-2]-ans[i+1][j-1]-ans[i][j];
    else
    {
        int sum=cell[i+1][j]-cell[i][j]+(ans[i][j]?3:0);
        ans[i+1][j]=sum>=3?1:0;
    }
    if (ans[i+1][j]&&i+1<n)
        for (int k=max(1,j-1);k<=min(m,j+1);k++) cell[i+2][k]--;
}

int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                scanf("%d",&cell[i][j]);
        for (int i=0;i<=m;i++) ans[n+1][i]=0;
        for (int i=1;i<=n;i+=2)
            for (int j=1;j<=m;j++)
                get(i,j);
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
                putchar(ans[i][j]?'L':'-');
            puts("");
        }
    }
    return 0;
}