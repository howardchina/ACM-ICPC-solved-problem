#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include <math.h>
#include<algorithm>
#define eps 1e-7
#define zero(x) (((x)>0?(x):-(x))<eps)
#define _sign(x) ((x)>eps?1:((x)<-eps?2:0))
using namespace std;
struct point
{
    double x,y;
}p[220];
struct line
{
    point a,b;
}xl[210];
//计算 cross product (P1-P0)x(P2-P0)
double xmult(point p1,point p2,point p0)
{
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
double xmult(double x1,double y1,double x2,double y2,double x0,double y0)
{
    return (x1-x0)*(y2-y0)-(x2-x0)*(y1-y0);
}
//计算 dot product (P1-P0).(P2-P0)
double dmult(point p1,point p2,point p0)
{
return (p1.x-p0.x)*(p2.x-p0.x)+(p1.y-p0.y)*(p2.y-p0.y);
}
double dmult(double x1,double y1,double x2,double y2,double x0,double y0)
{
return (x1-x0)*(x2-x0)+(y1-y0)*(y2-y0);
}
///两点距离
double distance1(point p1,point p2)
{
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
int dots_inline(point p1,point p2,point p3)
{
    return zero(xmult(p1,p2,p3));
}
int same_side(point p1,point p2,line l)
{
    return xmult(l.a,p1,l.b)*xmult(l.a,p2,l.b)>eps;
}
int same_side(point p1,point p2,point l1,point l2)
{
    return xmult(l1,p1,l2)*xmult(l1,p2,l2)>eps;
}
int dot_online_in(point p,line l)
{
    return zero(xmult(p,l.a,l.b))&&(l.a.x-p.x)*(l.b.x-p.x)<eps&&(l.a.y-p.y)*(l.b.y-p.y)<eps;
}
int dot_online_in(point p,point l1,point l2)
{
    return zero(xmult(p,l1,l2))&&(l1.x-p.x)*(l2.x-p.x)<eps&&(l1.y-p.y)*(l2.y-p.y)<eps;
}
int opposite_side(point p1,point p2,line l)
{
return xmult(l.a,p1,l.b)*xmult(l.a,p2,l.b)<-eps;
}
int intersect_in(line u,line v)
{
    if (!dots_inline(u.a,u.b,v.a)||!dots_inline(u.a,u.b,v.b))
    return !same_side(u.a,u.b,v)&&!same_side(v.a,v.b,u);
    return dot_online_in(u.a,v)||dot_online_in(u.b,v)||dot_online_in(v.a,u)||dot_online_in(v.b,u);
}
int intersect_ex(line u,line v)
{
    return opposite_side(u.a,u.b,v)&&opposite_side(v.a,v.b,u);
}
int inside_convex(point q,int n)
{
    int i,s[3]={1,1,1};
    for (i=0;i<n&&s[1]|s[2];i++)
    s[_sign(xmult(p[(i+1)%n],q,p[i]))]=0;
    return s[0]|s[1]|s[2];
}
int inside_polygon(point q,int n)
{
    point q2;
    int on_edge=2,offset=10010;
    int i=0,coun;
    while (i<n)
    for (coun=i=0,q2.x=rand()+offset,q2.y=rand()+offset;i<n;i++)
    {
        if (zero(xmult(q,p[i],p[(i+1)%n]))&&(p[i].x-q.x)*(p[(i+1)%n].x-q.x)<eps&&(p[i].y-q.y)*(p[(i+1)%n].y-q.y)<eps)
            return on_edge;
        else if (zero(xmult(q,q2,p[i]))) break;
            else if (xmult(q,p[i],q2)*xmult(q,p[(i+1)%n],q2)<-eps&&
        xmult(p[i],q,p[(i+1)%n])*xmult(p[i],q2,p[(i+1)%n])<-eps)
        coun++;
    }
    return coun&1;
}
int ok[210][210];
double dp[210][210];
int main()
{
    int n;
    double ans;
    int ca=1;
    while( scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        p[0]=p[n];
        memset(ok,0,sizeof ok);
        for(int i=1;i<=n;i++)
        p[i+n]=p[i];
        for(int i=0;i<n;i++)
            xl[i].a=p[i],xl[i].b=p[i+1];
        xl[n]=xl[0];
        for(int i=1;i<n;i++)
            for(int j=i+1;j<=n;j++)
            {
                int tot=0;
                line f;
                f.a=p[i];
                f.b=p[j];
                for(int k=1;k<=n;k++)
                {
                    if(k==i||k%n==i-1||k==j||k%n==j-1)continue;
                    if(intersect_in(f,xl[k]))
                    {
                        //cout<<k<<endl;
                        //cout<<f.a.x<<" "<<f.a.y<<" "<<f.b.x<<" "<<f.b.y<<endl;
                        //cout<<xl[k].a.x<<" "<<xl[k].a.y<<" "<<xl[k].b.x<<" "<<xl[k].b.y<<endl;
                        tot++;
                    }
                }
                //cout<<i<<j<<" "<<tot<<endl;
                if(tot==0)
                {
                    point nimei;
                    nimei.x=(p[i].x+p[j].x)/2;
                    nimei.y=(p[i].y+p[j].y)/2;
                    //cout<<nimei.x<<" "<<nimei.y<<endl;
                    if(inside_polygon(nimei,n))
                    {
                       // cout<<i<<j<<endl;
                        ok[i][j%n]=ok[j%n][i]=1;
                    }
                }
            }
        memset(dp,0,sizeof 0);
        for(int i=1;i<=2*n;i++)
            for(int j=1;j<=2*n;j++)
            ok[i][j]=ok[i%n][j%n];
        for(int l=2;l<n;l++)
            for(int i=1;i<=n*2-l;i++)
                if(ok[i][i+l])
                {
                    dp[i][i+l]=0;
                    for(int k=i+1;k<=i+l-1;k++)
                    if(ok[i][k]&&ok[k][i+l])
                    {
                            //cout<<i<<l<<k<<" "<<dp[i][k]<<" "<<dp[k][i+l]<<endl;
                            if(dp[i][i+l]>0) dp[i][i+l]=min(dp[i][i+l],dp[i][k]+dp[k][i+l]);
                            else dp[i][i+l]=dp[i][k]+dp[k][i+l];
                    }
                    dp[i][i+l]+=distance1(p[i],p[i+l]);
                    //cout<<dp[i][i+l]<<" "<<i<<" "<<l<<endl;
                }
        ans=99999999;
        for(int i=1;i<n;i++)
        //cout<<dp[i][i+n-1]<<endl;
            if(dp[i][i+n-1])ans=min(ans,dp[i][i+n-1]-distance1(p[i],p[i+n-1]));
        printf("Case %d: %.4lf\n",ca++,ans);
    }
    return 0;
}
/*
4
0 0
3 0
1 1
0 3
4
0 0
10 0
10 1
0 1
5
0 0
2 0
2 2
1 1
0 2
*/
