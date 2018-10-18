#include<cstdio>
using namespace std;
int main()
{
    int t;
    double p,q,xwolf,xtiger,x,y;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf%lf%lf%lf",&x,&y,&p,&q);
        xtiger=(1-q)*x+q*p*(x+y);
        xwolf=q*y+p*(1-q)*(x+y);
        if(xwolf>xtiger)printf("wolf %.4lf\n",xwolf);
        else printf("tiger %.4lf\n",xtiger);
    }
    return 0;
}
