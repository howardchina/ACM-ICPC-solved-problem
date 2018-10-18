#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
#pragma comment(linker,"/STACK:1024000000,1024000000")
using namespace std;
int n;
double a[61],b[61],k[61];
double F(double x)
{
    double s=100;
    for(int i=1;i<=n;i++)
    {
        double c=k[i]*(x-a[i])*(x-a[i])+b[i];
        //cout<<c<<endl;
        if(s>c)s=c;
    }
    return s;
}
double simpson(double a,double b)
{
    double c=a+(b-a)/2;
    double fa=F(a),fb=F(b),fc=F(c);
    return sqrt((fa-fc)*(fa-fc)+(a-c)*(a-c))+sqrt((fb-fc)*(fb-fc)+(b-c)*(b-c));
}
double asr(double a,double b,double eps,double A)
{
    double c=(a+b)/2;
    double L=simpson(a,c),R=simpson(c,b);
    if(fabs(L+R-A)<=15*eps) return L+R+(L+R-A)/15.0;
    return asr(a,c,eps/2,L)+asr(c,b,eps/2,R);
}
double asr(double a,double b,double eps)
{
    return asr(a,b,eps,simpson(a,b));
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%lf%lf%lf",&k[i],&a[i],&b[i]);
        double s=0;
        double i;
        for(i=0.0;i+0.01<100.0;i+=0.01)
            s+=asr(i,i+0.01,1e-10);
        s+=asr(i,100.0,1e-6);
        printf("%.2lf\n",s);
    }
    return 0;
}
