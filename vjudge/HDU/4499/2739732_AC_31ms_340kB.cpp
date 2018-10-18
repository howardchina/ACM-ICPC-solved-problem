#include<iostream>
#include<iomanip>
using namespace std;
  
int a[10][10];  
int n,m,q,ans;  
  
bool judge(int x,int y)
{
    int i; 
    int cnt;  
    for(cnt=0,i=y-1;i>=1;i--)
	{  
        if(a[x][i]==1&&cnt==1) return false;  
        if(a[x][i]) cnt++;   
    }

    for(cnt=0,i=y+1;i<=m;i++)
	{
        if(a[x][i]==1&&cnt==1) return false;  
        if(a[x][i]) cnt++;   
    }  
    
    for(cnt=0,i=x-1;i>=1;i--)
	{
        if(a[i][y]==1&&cnt==1) return false;  
        if(a[i][y]) cnt++;    
    }  
      
    for(cnt=0,i=x+1;i<=n;i++)
	{
        if(a[i][y]==1&&cnt==1) return false;  
        if(a[i][y]) cnt++;  
    }  
    return true;  
}  
  
void dfs(int x,int y,int tot)
{  
	int i,j;
    if(tot>ans) ans=tot;  
    for(i=x;i<=n;i++)
	{  
        for(x==i?(j=y):(j=1);j<=m;j++)
		{  
            if(!a[i][j] && judge(i,j))
			{  
                a[i][j]=1;  
                dfs(i,j+1,tot+1);  
                a[i][j]=0;
				dfs(i,j+1,tot);
				return ;
            }  
        }  
    }  
}  
  
int main()  
{  
    while(~scanf("%d%d%d",&n,&m,&q))
	{  
        memset(a,0,sizeof(a));  
        int x,y;  
        int i;
		for(i=1;i<=q;i++)
		{  
            scanf("%d%d",&x,&y);  
			x++;
			y++;
            a[x][y]=-1;  
        }  

        ans=0;  
        dfs(1,1,0);  
        printf("%d\n",ans);  
    }  
    return 0;  
}  
