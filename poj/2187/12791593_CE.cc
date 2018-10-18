#include<iostream>
#include<cmath>
#define PI acos(-1.0)
const double eps = 1e-6;
int sgn(double a) {
    return (a>eps) - (a<-eps);
}
struct point{
    int x,y;
    point (int xx=0,int yy=0){ //构造函数
        x=xx;  y=yy;
    }
    point operator -(point b){
        return point(x-b.x,y-b.y);
    }
    int operator *(point b){
        return (x*b.y-y*b.x);
    }
    int len2(){
        return x*x+y*y;
    }
    void input(){
        scanf("%d%d",&x,&y);
    }
}p[50005];
int stack[50005],top,n;
int cmp(const void *a,const void *b) //逆时针排序 返回正数要交换
{
    struct point *c=(struct point *)a;
    struct point *d=(struct point *)b;
    int k=(*c-p[0])*(*d-p[0]);
    if(k<0) return 1;
    else if(k==0 && ((*c-p[0]).len2()-(*d-p[0]).len2())>=0)
        return 1;
    else return -1;
}

void graham(int n) //形成凸包
{
    int i;
    for(i=0;i<=1;i++)
        stack[i]=i;
    top=1;
    for(i=2;i<n;i++)
    {
        while(top>0 && (p[stack[top]]-p[stack[top-1]])*(p[i]-p[stack[top-1]])<=0)
            top--;
        stack[++top]=i;
    }
    int tmp=top;
    for(i=n-2;i>=0;i--)
    {
        while(top>tmp && (p[stack[top]]-p[stack[top-1]])*(p[i]-p[stack[top-1]])<=0)
            top--;
        stack[++top]=i;
    }
/*    for(i=0;i<n;i++)
       printf("**%d %d\n",p[i].x,p[i].y);
    printf("\n%d\n",top);
    for(i=0;i<top;i++)
       printf("**%d %d\n",p[stack[i]].x,p[stack[i]].y);*/
}

int max(int a,int b)
{
    return a>b?a:b;
}
int rotating_calipers()  //卡壳
{
    int q=1;
    int ans=0;
    stack[top]=0;
    for(int i=0;i<top;i++)
    {
        while( (p[stack[i+1]]-p[stack[i]])*(p[stack[q+1]]-p[stack[i]])>
                (p[stack[i+1]]-p[stack[i]])*(p[stack[q]]-p[stack[i]]))
            q=(q+1)%(top);
        ans=max(ans , max((p[stack[i]]-p[stack[q]]).len2(),(p[stack[i+1]]-p[stack[q+1]]).len2()));
       // printf("%d stack[i]=%d stack[q]=%d %d %d %d\n",i,stack[i],stack[q],
          //  (p[stack[i]]-p[stack[q]]).len2(),(p[stack[i+1]]-p[stack[q+1]]).len2(),ans);
    }
    return ans;
}

int main()
{
    int i;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
            p[i].input();
        int u=0;
        for(i=1;i<n;i++) //找左下角的点
            if(p[i].y<p[u].y || (p[i].y==p[u].y&&p[i].x<p[u].x) )
                u=i;
        //swap
        point tmp=p[0];
        p[0]=p[u];
        p[u]=tmp;
        qsort(p+1,n-1,sizeof(p[0]),cmp);
        graham(n);

        printf("%d\n",rotating_calipers());
    }
    return 0;
}