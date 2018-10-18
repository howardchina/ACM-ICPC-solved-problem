#include<stdio.h>
#include<string.h>

#define maxn 20011
int wa[maxn],wb[maxn],wv[maxn],ws[maxn];
int cmp(int *r,int a,int b,int l)
{
	return r[a]==r[b]&&r[a+l]==r[b+l];
}
void da(int *r,int *sa,int n,int m)
{
     int i,j,p,*x=wa,*y=wb,*t;
     for(i=0;i<m;i++) ws[i]=0;
     for(i=0;i<n;i++) ws[x[i]=r[i]]++;
     for(i=1;i<m;i++) ws[i]+=ws[i-1];
     for(i=n-1;i>=0;i--) sa[--ws[x[i]]]=i;
     for(j=1,p=1;p<n;j*=2,m=p)
     {
       for(p=0,i=n-j;i<n;i++) y[p++]=i;
       for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
       for(i=0;i<n;i++) wv[i]=x[y[i]];
       for(i=0;i<m;i++) ws[i]=0;
       for(i=0;i<n;i++) ws[wv[i]]++;
       for(i=1;i<m;i++) ws[i]+=ws[i-1];
       for(i=n-1;i>=0;i--) sa[--ws[wv[i]]]=y[i];
       for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)
       x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
     }
     return;
}
int rank[maxn],height[maxn];
void calheight(int *r,int *sa,int n)
{
     int i,j,k=0;
     for(i=1;i<=n;i++) rank[sa[i]]=i;
     for(i=0;i<n;height[rank[i++]]=k)
     for(k?k--:0,j=sa[rank[i]-1];r[i+k]==r[j+k];k++);
     return;
}

int n, a[maxn], sa[maxn];

int check(int mid)
{
	int i, j, mn, mx;
	for(i=1; i<=n; i=j)
	{
		while(i<=n && height[i]<mid)
			i++;
		j=i;
		mn = n;
		mx = 0;
		if(i==n+1)
			break;
		if(sa[i-1]>mx)
			mx = sa[i-1];
		if(sa[i-1]<mn)
			mn = sa[i-1];
		while(j<=n && height[j]>=mid)
		{
			if(sa[j]>mx)
				mx = sa[j];
			if(sa[j]<mn)
				mn = sa[j];
			j++;
		}
		if(mx-mn>=mid)
			return 1;
	}
	return 0;
}

int main()
{
	int i, l, r, mid, ans;
	while(scanf("%d", &n)!=EOF)
	{
		if(n==0)
			break;
		if(n<=9)
		{
			for(i=0; i<n; i++)
				scanf("%d", &a[i]);
			printf("0\n");
			continue;
		}
		scanf("%d", &a[0]);
		for(i=1; i<n; i++)
		{
			scanf("%d", &a[i]);
			a[i-1] = a[i]-a[i-1]+89;
		}
		n--;
		a[n] = 0;
		da(a, sa, n+1, 180);
		calheight(a, sa, n);
		l=0, r=n-1;
		while(l<=r)
		{
			mid = (l+r)>>1;
			if(check(mid))
				l = mid+1;
			else
				r = mid-1;
		}
		ans = r;
		if(ans>=4)
			printf("%d\n", ans+1);
		else
			printf("0\n");
	}

	return 0;
}