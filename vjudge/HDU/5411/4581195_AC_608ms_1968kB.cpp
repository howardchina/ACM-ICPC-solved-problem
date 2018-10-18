#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<stdio.h>
using namespace std;
#define LL long long
#define Max_size 51
int const M=2015;
int n;
using namespace std;
struct Mat
{
	int mat[Max_size][Max_size];
	void show()
	{
	    for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cout<<mat[i][j]<<" ";
            cout<<endl;
        }
	}
};
Mat E;
Mat operator*(Mat a,Mat b)
{
	Mat c;
	memset(c.mat,0,sizeof(c.mat));
	for (int i=0;i<n;i++)
	    for (int j=0;j<n;j++)
	        for (int k=0;k<n;k++)
	            if (a.mat[i][k] && b.mat[k][j])
	               c.mat[i][j]=(c.mat[i][j]+a.mat[i][k]*b.mat[k][j])%M;
	return c;
}
Mat operator+(Mat a,Mat b)
{
	Mat c;
	memset(c.mat,0,sizeof(c.mat));
	for (int i=0;i<n;i++)
	    for (int j=0;j<n;j++)
	        c.mat[i][j]=(a.mat[i][j]+b.mat[i][j])%M;
	return c;
}
void builtE()
{
	memset(E.mat,0,sizeof(E.mat));
	for (int i=0;i<n;i++)
	{
		E.mat[i][i]=1;
	}
}
Mat operator^(Mat A,int x)
{
	Mat c;
	c=E;
	for ( ; x; x>>=1)
	{
		if ( x & 1)
		    c = c * A;
		A = A * A;
	}
	return c;
}
Mat Mat_Sum(Mat A ,int b){//非递归
    int nn = 0 ,s[30]={};
    int i;
    Mat tp1,tp2;
    while(b > 0){
        s[nn++]=b&1;
        b>>=1;
    }
    tp1=tp2=A;
    for(i=nn-2;i>=0;i--){
        tp1=tp1*(tp2+E);
        tp2=tp2*tp2;
        if(s[i]){
            tp2=tp2*A;
            tp1=tp1+tp2;
        }
    }
    return tp1;
}
/*
Mat Mat_Sum(Mat A,int b){//递归
	if(b==1) return A;
 	if(b&1) return Mat_Sum(A,b-1)+(A^b);
 	else
	  return ((A^(b>>1))+E)*Mat_Sum(A,b>>1);
}*/
int main()
{
    int T,m,k,ans;
    scanf("%d",&T);
    while(T--)
    {
        Mat A,B;
        memset(A.mat,0,sizeof A.mat);
        memset(B.mat,0,sizeof B.mat);
        scanf("%d%d",&n,&m);
        builtE();
        for(int i=0;i<n;i++)
            B.mat[0][i]=1;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&k);
            int x;
            for(int j=0;j<k;j++)
            {
                scanf("%d",&x);
                A.mat[i][x-1]=1;
            }
        }
        A=Mat_Sum(A,m-1);

        B=B*(A+E);
        //B.show();
        int ans=1;
        for(int i=0;i<n;i++)
            ans+=B.mat[0][i];
        printf("%d\n",ans%M);
    }
    return 0;
}
