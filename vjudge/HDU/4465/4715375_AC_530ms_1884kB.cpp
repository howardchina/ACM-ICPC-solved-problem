#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <math.h>
using namespace std;
double c[100010];
int main()
{
    int n,ca=1;
    double p;
    //cout<<pow(10,log10(10))<<endl;
    while(scanf("%d%lf",&n,&p)!=EOF)
    {
        double ans=0;
        double p1=log10(p);
        double p2=log10(1-p);
        c[0]=log10(1);
        for(int i=1;i<=n;i++)
            c[i]=c[i-1]-log10(i)+log10(n+i);
        for(int i=0;i<=n;i++)
        {
            double k=(pow(10,c[i]+(n+1)*p1+i*p2)+pow(10,c[i]+(n+1)*p2+i*p1))*(n-i);
            ans+=k;
            //cout<<i<<" "<<k<<endl;
        }
        printf("Case %d: %.6lf\n" ,ca++, ans) ;
    }
    return 0;
}
