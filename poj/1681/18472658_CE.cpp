#include<stdio.h>
#include<string.h>
constint N =17;
constint inf =99999;
bool graph[N][N];//graph[i][j]存储最初的颜色，黄色为0，白色为1
bool swap[N][N];//swap[i][j]存储该格是否进行染色
int main()
{
 int T;
 while(scanf("%d",&T)!=EOF)
 {
  while(T--)
  {
   int n;
   scanf("%d",&n);
   long upper =1<<n;
   long cur,i,j;
   char str[N];
   memset(graph,0,sizeof(graph));
   for(i=1;i<=n;i++)
   {
    scanf("%s",str);
    for(j=0;j<n;j++)
    {
                  if(str[j]=='w')graph[i][j+1]=true;
    }
   }
   int ans = inf;
   for(cur=0;cur<upper;cur++)//枚举第一行按钮状态
   {
    memset(swap,false,sizeof(swap));
    long tcur = cur;
    for(i=1;i<=n;i++)
    {
     swap[1][i]=cur&1;
     cur>>=1;
    }
               cur=tcur;
    for(i=2;i<=n;i++)
    {
                      for(j=1;j<=n;j++)
        swap[i][j]=(graph[i-1][j]^swap[i-1][j]^swap[i-1][j-1]^swap[i-1][j+1]^swap[i-2][j]);
    }

    bool flag =true;
       
    for(i=1;i<=n;i++)
     if(swap[n][i]^swap[n-1][i]^swap[n][i-1]^swap[n][i+1]^graph[n][i]){
     flag=false;
     break;
     }

    if(flag)
    {
                   int step=0;
       for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
         if(swap[i][j])
         step++;

        if(step<ans)ans=step;
    }
   }

            if(ans==inf)printf("inf\n");
   else
    printf("%d\n",ans);
  }
 
 }
 return0;
}