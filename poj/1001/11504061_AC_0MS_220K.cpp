#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<queue>
#include<cstring>
using namespace std;
char s[7];
int len,len1,i,j,n,point,num;
int ans[200],result[200],a[7],ok,d,m;
void F()                                     //乘法函数
{
 for(i=0;i<len;i++)
  for(j=0;j<len1;j++)
  {
   result[i+j]+=(a[i]*ans[j]%10);
   result[i+j+1]+=(a[i]*ans[j]/10);
  }
 for(i=0;i<len+len1-1;i++)
 {
  if(result[i]>=10)
  {
   result[i+1]+=result[i]/10;
   result[i]%=10;
  }
 }
 if(result[len+len1-1]!=0)                   //判断高位有没进位
  len1=len1+len;
 else len1=len1+len-1;
 for(i=0;i<len1;i++)                            //替换其中一个因子，另一个肯定不变
  ans[i]=result[i];
}
int main()
{
 while(scanf("%s%d",s,&n)!=EOF)
 {
  len=strlen(s);
  if(n==1)
  {
   printf("%g\n",atof(s));                        //n为1，情况特殊，偷懒用了函数库
   continue;
  }
  point=0;
  ok=0;
  i=0;
  j=len-1;
  for(m=0;m<len;m++)                          //没分什么小数部分整数部分，一起计算，只要记录小数点位置就OK
  {
   if(s[m]=='.')
   {
    ok=1;
    break;
   }
  }
  if(ok==1)
  {
   while(s[j]=='0'&&j>=0)
    j--;
   while(s[j]!='.'&&j>=0)
    a[i++]=s[j--]-48;
   point=i;
   j--;
  }

  num=point*n;
  for(m=0;m<=j;m++)
   if(s[m]!='0')
    break;
  while(j>=m)
   a[i++]=s[j--]-48;
  len=i;
  len1=len;
  memset(ans,0,sizeof(ans));
  for(i=0;i<len;i++)
   ans[i]=a[i];
  for(int k=2;k<=n;k++)
  {
   memset(result,0,sizeof(result));
   F();
  }
  d=num-1;
  for(i=len1-1;i>=num;i--)
  {
   if(result[i]!=0)
   {
    d=i;
    break;
   }
  }
  if(d>=num)
  {
   for(i=len1-1;i>=num;i--)
    printf("%d",result[i]);
  }
  if(point!=0&&ok==1)                                   //输出的要求较高
   printf(".");
  for(i=num-1;i>=0;i--)
   printf("%d",result[i]);
  putchar(10);
 }
 system("pause");
 return 0;
}
