#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char s[2][300];
int n,k,a[300];
int c[201],ch[201][201];

void init()
{
    for(int i=1;i<=n;i++)
    {
        int t=a[i];
        ch[i][0]=i;
        for(int j=1;j<=n;j++)
        {
            ch[i][j]=t;
            if(t==i)
            {
                c[i]=j;
                break;
            }
            t=a[t];
        }
    }
}
void encode(char *s1,char *s2)
{
    for(int i=1;i<=n;i++)
    {
        int tk=k%c[i];
        s2[ch[i][tk]]=s1[i];
    }
}
int main()
{
    while(scanf("%d",&n),n)
    {
        for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
        s[0][n+1]=s[1][n+1]=0;
        init();

        for(;;)
        {
            scanf("%d",&k);
            if(!k)
            break;
            getchar();
            gets(s[0]+1);
            int len=strlen(s[0]+1);
            for(int i=len+1;i<=n;i++)
            s[0][i]=' ';
            encode(s[0],s[1]);
            puts(s[1]+1);
        }
        puts("");
    }
    return 0;
}