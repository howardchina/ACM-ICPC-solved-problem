#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>
using namespace std;
int gcd(int a,int b)
{
    return b?gcd(b,a%b):a;
}
int H,h,m,s,ansup,ansdown,x,jy,ansm,ansh;
void gx(int up,int down)
{
    //cout<<h<<" "<<m<<" "<<up<<" "<<down<<"cs"<<endl;
    if(up<0||up/down<s)return ;
    if(up/down>=60)
        return;
    if(m*H!=h*60||(up/down)!=m%60)
    {
        if(up>0)
        {
            x=gcd(up,down);
            ansup=up/x;
            ansdown=down/x;
        }
        else
        {
            ansup=0;
            ansdown=1;
        }
        ansm=m;
        ansh=h;
    }
}
int main()
{
    while(scanf("%d%d%d%d",&H,&h,&m,&s)&&H)
    {
        //1  m>h  s>m
        ansup=-1;
            int ansdown1=119*H-1;
            int ansup1=3600*(H+h)+60*m*H+60*m;
            gx(ansup1,ansdown1);
            //2 m>h  s<m

            ansup1=3600*h+60*m*H+60*m;
            gx(ansup1,ansdown1);

            ansup1=3600*(h-H)+60*m*H+60*m;
            gx(ansup1,ansdown1);
        if(ansup>=0)
        printf("%d %d %d %d\n",ansh,ansm,ansup,ansdown);
        else
        {
            m++;
            s=0;
            if(m==60)m=0,h=(h+1)%H;
            ansdown1=119*H-1;
            ansup1=3600*(H+h)+60*m*H+60*m;
            gx(ansup1,ansdown1);
            //2 m>h  s<m
            ansup1=3600*h+60*m*H+60*m;
            gx(ansup1,ansdown1);
            ansup1=3600*(h-H)+60*m*H+60*m;
            gx(ansup1,ansdown1);
            printf("%d %d %d %d\n",ansh,ansm,ansup,ansdown);
        }
    }
    return 0;
}
