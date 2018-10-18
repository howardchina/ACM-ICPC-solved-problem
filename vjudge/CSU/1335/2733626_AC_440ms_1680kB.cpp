#include<iostream>  
#include<algorithm>  
#include<string.h>  
using namespace std;  

int cmp(void const *a,void const *b){return *(int*)a-*(int*)b;}

int h[10100];
int l0[10100],r0[10100];
int a[10010],b[10010];  
int main()
{  
    int n,m,k,t=0;
	int i,j;
	int l,r,acc,ans;
    while(cin>>n>>m>>k)
    {  
        t++;   
        for(i=0;i<n;i++) { cin>>h[i];  a[i]=b[i]=0;}
        
		qsort(h,n,sizeof(h[0]),cmp);
		l0[0]=1;  
        for(i=0;i<m;i++)
		{  
            cin>>r0[i]>>l0[i+1];  
            l0[i+1]++;  
        }  
        
        for(i=0;i<m;i++)
		{  
            l=lower_bound(h,h+n,l0[i])-h;  
            r=upper_bound(h,h+n,r0[i])-h-1;  
            a[l]++;  
            b[r]++;  
        }  
        acc=ans=0;
		
        for(i=0;i<n;i++){  
            acc+=a[i];  
            if(acc>=k) ans++;  
			acc-=b[i];
        }  

        cout<<"Case "<<t<<": "<<ans<<endl;  
    }  
    return 0;  
} 