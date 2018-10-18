#include <iostream>  
#include <algorithm>   
#include <cstdio>  
#include <ctime>  
#include <cstdlib>  
#include <cmath>  
using namespace std;  
const int maxn=1005;  
double a[maxn],b[maxn];  
const double eps=1e-6;  
int n,k;  
struct dnode{  
    double x;  
    int index;  
}d[maxn];  
bool cmp(dnode a,dnode b){  
    return a.x>b.x;  
}  
int main()  
{  
    while(scanf("%d%d", &n, &k) != EOF)  
    {  
        if(n+k==0)break;  
        for(int i=0;i<n;i++)  
             scanf("%lf", &a[i]);  
        for(int i=0;i<n;i++)  
            scanf("%lf", &b[i]);   
        double l=0.5,ans;  
        do{  
            ans=l;  
            for(int i=0;i<n;i++)  
                {d[i].x=a[i]-ans*b[i];  
                 d[i].index=i;  
                }  
            sort(d,d+n,cmp);  
            double p=0,q=0;  
            for(int i=0;i<n-k;i++)  
            {  
                p+=a[d[i].index];  
                q+=b[d[i].index];  
            }     
            l=p/q;  
        }while(fabs(ans-l)>=eps);  
          
        printf("%.0f\n", l * 100);    
      
    }  
    return 0;  
} 