#include<iostream>  
#include<stdio.h>
using namespace std;  

int l[101000],r[101000];

int n;
void print()
{
	int p;
	for(p=r[0];p!=n+1;p=r[p]) cout<<p<<" ";
	cout<<endl;
}

typedef long long ll;
int main()
{  
	int rev;
	int t,lt;
	int m,i;
	int sign,x,y; int temp;

	t=0;
	int p; int cnt=0; ll ans=0;
    while(~scanf("%d%d",&n,&m))
    {  
        t++;   
		rev=0;

		for(i=1;i<=n;i++)
		{
			l[i]=i-1; r[i]=i+1;
		}
		l[n+1]=n; r[0]=1;


		for(i=1;i<=m;i++)
		{
			//cin>>sign; if(sign!=4) cin>>x>>y;
			scanf("%d",&sign); if(sign!=4) scanf("%d%d",&x,&y);

			if(rev&1) { if(sign==1) sign=2; else if(sign==2) sign=1; }
			if(sign==1)
			{
				if(l[y]==x) continue;
				r[l[x]]=r[x];
				l[r[x]]=l[x];
				lt=l[y]; 
				r[lt]=x; l[x]=lt; r[x]=y;
				l[y]=x;
			//	print();
			}else if(sign==2)
			{
				if(r[y]==x) continue;
				r[l[x]]=r[x];
				l[r[x]]=l[x];
				lt=r[y];
				l[lt]=x; l[x]=y; r[x]=lt;
				r[y]=x;
			//	print();
			}else if(sign==3)
			{

				if(l[x]==y)// y x
				{	
					r[l[y]]=x;
					l[r[x]]=y;
				
					l[x]=l[y];
					r[y]=r[x];
					l[y]=x;
					r[x]=y;
			//	print();
					continue;
				}else if(r[x]==y) // x y
				{
					int temp=x; x=y; y=temp;
					r[l[y]]=x;
					l[r[x]]=y;
				
					l[x]=l[y];
					r[y]=r[x];
					l[y]=x;
					r[x]=y;
				//print();
					continue;
				}

				r[l[x]]=y;
				l[r[x]]=y;
				r[l[y]]=x;
				l[r[y]]=x;
				
				temp=l[x]; l[x]=l[y]; l[y]=temp;
				temp=r[x]; r[x]=r[y]; r[y]=temp;
				//print();
			}else
			{
				rev++;
			}
		}

		ans=0; cnt=0;
		for(p=r[0];p!=n+1;p=r[p]) 
		{
			cnt++;
		//	if(cnt>n+1) break;
			if(n&1){ if(cnt&1) { ans+=(ll)p;} }
			else
			{
				if(rev&1) { if(!(cnt&1)) ans+=(ll)p; }
				else if(cnt&1) { ans+=(ll)p;}
			}
		}

		printf("Case %d: %lld\n",t,ans);
    }  
    return 0;  
} 