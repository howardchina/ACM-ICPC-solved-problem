#include<iostream>
#include<string.h>
#include<stdio.h>
#define LL long long
#define Max_size 55
using namespace std;
int n;//表示矩阵的大小
LL k,mod;
int a,b,c,t;
struct Mat
{
	LL mat[Max_size][Max_size];
	void Read();

};
Mat A;
Mat E;//全局变量
Mat operator*(Mat a,Mat b)//n是全局变量
{
	Mat c;
	memset(c.mat,0,sizeof(c.mat));
	for (int i=0;i<n;i++)
	    for (int j=0;j<n;j++)
	        for (int k=0;k<n;k++)
	            if (a.mat[i][k] && b.mat[k][j])
	               c.mat[i][j]=(c.mat[i][j]+a.mat[i][k]*b.mat[k][j])%mod;
	return c;
}
Mat operator^(Mat A,LL x)
{
	Mat c;
	c = E;
	for ( ; x; x>>=1)
	{
		if ( x & 1)
		    c = c * A;
		A = A * A;
	}
	return c;
}
void builtE()
{
	memset(E.mat,0,sizeof(E.mat));
	for (int i=0;i<Max_size;i++)
	{
		E.mat[i][i]=1;
	}
}

int main()
{
    //freopen("test.in","r",stdin);
    builtE();
    while(~scanf("%d",&n) && n)
    {
        cin>>mod;
        cin>>a>>b>>c>>t;
        Mat B;
        B.mat[0][0]=0;
        for(int i=1;i<=n;i++)
        {
            int k;
            cin>>k;
            B.mat[0][i]=k;
        }
        B.mat[0][n+1]=0;
        n=n+2;
        memset(A.mat,0,sizeof(A.mat));
        for(int i=1;i<=n-2;i++)
        {
            A.mat[i-1][i]=a;
            A.mat[i][i]=b;
            A.mat[i+1][i]=c;
        }
        Mat ans;
        ans=B*(A^t);
        for(int i=1;i<=n-3;i++)
        cout<<ans.mat[0][i]<<" ";
        cout<<ans.mat[0][n-2]<<endl;
    }


    return 0;
}
