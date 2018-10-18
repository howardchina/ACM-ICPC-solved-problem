#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
const double eps=1e-10;
double dp[2][2010];
int main()
{
    int n,m,k;
    double p1,p2,p3,p4,tp3,tp4;
    while(scanf("%d%d%d", &n,&m,&k)!=EOF)
    {
        scanf("%lf%lf%lf%lf", &p1,&p2,&p3,&p4);
        double ans=0,win=0,bj=0;
        if(p2<=1.0-eps&&p1<=1.0-eps)
        {
            p2/=1-p1;
            p3/=1-p1;
            p4/=1-p1;
            tp3=p3/(p3+p4);
            tp4=p4/(p3+p4);
            if(p2>eps)
            p2=log10(p2);
            else p2=-500;
            if(p3>eps)
            p3=log10(p3);
            else p3=-500;
            if(p4>eps)
            p4=log10(p4);
            else p4=-500;
            if(tp3>eps)
            tp3=log10(tp3);
            else tp3=-500;
            if(tp4>eps)
            tp4=log10(tp4);
            else tp4=-500;
            double s;
            for(int i=1;i<=n;i++)dp[(n+1)&1][(i+1)]=-500;
            dp[(n+1)&1][(m+1)]=-tp3;
            for(int i=n;i>=1;i--)
            {
                s=-log10(1-pow(10,i*p2));
                int thi=i&1,lai=(i+1)&1;
                double c=-500;
                for(int j=i;j>=1;j--)
                    if(dp[lai][j+1]>-30)
                        c=log10(pow(10,dp[lai][j+1]+tp3)+pow(10,c+p2));
                    else
                       c+=p2;
                for(int j=i;j>=1;j--)
                {
                    if(dp[lai][j+1]>-30)
                        c=log10(pow(10,dp[lai][j+1]+tp3+log10(1-pow(10,i*p2)))+pow(10,c+p2));
                    else
                        c+=p2;
                    if(c>-30)
                        dp[thi][j]=c+log10(1-pow(10,p2))+s;
                    else dp[thi][j]=-500;
                    //cout<<i<<" "<<j<<" "<<pow(10,c)<<" "<<pow(10,dp[thi][j])<<endl;
                    if(dp[thi][j]>-30&&j<=k)ans+=pow(10,dp[thi][j]+tp4);
                }
            }
        }
        printf("%.5lf\n", ans);
        //printf("win:%.5lf\n", win);
        //printf("bj:%.5lf\n", bj);
    }
    return 0;
}
