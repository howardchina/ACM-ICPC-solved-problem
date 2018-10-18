#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
#define LL long long
const LL MOD=1e9+7;
LL dp[55][10];
int mton[55][55];
int main()
{
    int t,n;
    scanf("%d",&t);
    for(int ca=1;ca<=t;ca++)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        memset(mton,0,sizeof mton);
        for(int i=1;i<=m;i++)
        {
            int num,x;
            scanf("%d",&num);
            for(int j=1;j<=num;j++)
            {
                scanf("%d",&x);
                mton[i][x]=1;
            }
        }
        LL ans=0;
        for(int i=1;i<=n;i++)
        {
            memset(dp,0,sizeof dp);
            dp[0][0]=1;
            for(int j=1;j<=m;j++)
            if(mton[j][i])
            {
                dp[j][0]=(dp[j][0]+dp[j-1][1]+dp[j-1][0])%MOD;
                dp[j][1]=(dp[j][1]+dp[j-1][0]+dp[j-1][1])%MOD;
            }
            else
            {
                dp[j][0]+=dp[j-1][0]*2%MOD;
                dp[j][1]+=dp[j-1][1]*2%MOD;
                dp[j][0]%=MOD;
                dp[j][1]%=MOD;
            }
            ans=(ans+dp[m][1])%MOD;
        }
        //cout<<"1"<<ans<<endl;
        for(int i=1;i<=n;i++)
            for(int i2=i+1;i2<=n;i2++)
        {
            memset(dp,0,sizeof dp);
            dp[0][0]=1;
            for(int j=1;j<=m;j++)
            {

                bool flag=true;
                dp[j][0]+=dp[j-1][0]%MOD;
                dp[j][1]+=dp[j-1][1]%MOD;
                dp[j][2]+=dp[j-1][2]%MOD;
                dp[j][3]+=dp[j-1][3]%MOD;
            if(mton[j][i]&&mton[j][i2]==0)
            {
                dp[j][0]+=dp[j-1][1];
                dp[j][1]+=dp[j-1][0];
                dp[j][2]+=dp[j-1][3];
                dp[j][3]+=dp[j-1][2];
                flag=false;
            }
            if(mton[j][i2]&&mton[j][i]==0)
            {
                dp[j][0]+=dp[j-1][2];
                dp[j][1]+=dp[j-1][3];
                dp[j][2]+=dp[j-1][0];
                dp[j][3]+=dp[j-1][1];
                flag=false;
            }
            if(mton[j][i2]&&mton[j][i])
            {
                dp[j][0]+=dp[j-1][3];
                dp[j][3]+=dp[j-1][0];
                dp[j][1]+=dp[j-1][2];
                dp[j][2]+=dp[j-1][1];
                flag=false;
            }
            if(flag)
            {
                dp[j][0]+=dp[j-1][0]%MOD;
                dp[j][1]+=dp[j-1][1]%MOD;
                dp[j][2]+=dp[j-1][2]%MOD;
                dp[j][3]+=dp[j-1][3]%MOD;
            }
            dp[j][0]%=MOD;
            dp[j][1]%=MOD;
            dp[j][2]%=MOD;
            dp[j][3]%=MOD;
            }
            ans=(ans+dp[m][3]*6)%MOD;
        }
        //cout<<"2"<<ans<<endl;
        for(int i=1;i<=n;i++)
            for(int i2=i+1;i2<=n;i2++)
                for(int i3=i2+1;i3<=n;i3++)
        {
            memset(dp,0,sizeof dp);
            dp[0][0]=1;
            for(int j=1;j<=m;j++)
            {
                bool flag=true;
                dp[j][0]+=dp[j-1][0]%MOD;
                dp[j][1]+=dp[j-1][1]%MOD;
                dp[j][2]+=dp[j-1][2]%MOD;
                dp[j][3]+=dp[j-1][3]%MOD;
                dp[j][4]+=dp[j-1][4]%MOD;
                dp[j][5]+=dp[j-1][5]%MOD;
                dp[j][6]+=dp[j-1][6]%MOD;
                dp[j][7]+=dp[j-1][7]%MOD;
            if(mton[j][i]&&mton[j][i2]==0&&mton[j][i3]==0)
            {
                dp[j][0]+=dp[j-1][1];
                dp[j][1]+=dp[j-1][0];
                dp[j][2]+=dp[j-1][3];
                dp[j][3]+=dp[j-1][2];
                dp[j][4]+=dp[j-1][5];
                dp[j][5]+=dp[j-1][4];
                dp[j][6]+=dp[j-1][7];
                dp[j][7]+=dp[j-1][6];
                flag=false;
            }
            if(mton[j][i2]&&mton[j][i]==0&&mton[j][i3]==0)
            {
                dp[j][0]+=dp[j-1][2];
                dp[j][1]+=dp[j-1][3];
                dp[j][2]+=dp[j-1][0];
                dp[j][3]+=dp[j-1][1];
                dp[j][4]+=dp[j-1][6];
                dp[j][5]+=dp[j-1][7];
                dp[j][6]+=dp[j-1][4];
                dp[j][7]+=dp[j-1][5];
                flag=false;
            }
            if(mton[j][i3]&&mton[j][i2]==0&&mton[j][i]==0)
            {
                dp[j][0]+=dp[j-1][4];
                dp[j][1]+=dp[j-1][5];
                dp[j][2]+=dp[j-1][6];
                dp[j][3]+=dp[j-1][7];
                dp[j][4]+=dp[j-1][0];
                dp[j][5]+=dp[j-1][1];
                dp[j][6]+=dp[j-1][2];
                dp[j][7]+=dp[j-1][3];
                flag=false;
            }
            if(mton[j][i3]&&mton[j][i2]&&mton[j][i])
            {
                dp[j][0]+=dp[j-1][7];
                dp[j][1]+=dp[j-1][6];
                dp[j][2]+=dp[j-1][5];
                dp[j][3]+=dp[j-1][4];
                dp[j][4]+=dp[j-1][3];
                dp[j][5]+=dp[j-1][2];
                dp[j][6]+=dp[j-1][1];
                dp[j][7]+=dp[j-1][0];
                flag=false;
            }
            if(mton[j][i]&&mton[j][i2]&&mton[j][i3]==0)
            {
                dp[j][0]+=dp[j-1][3];
                dp[j][1]+=dp[j-1][2];
                dp[j][2]+=dp[j-1][1];
                dp[j][3]+=dp[j-1][0];
                dp[j][4]+=dp[j-1][7];
                dp[j][5]+=dp[j-1][6];
                dp[j][6]+=dp[j-1][5];
                dp[j][7]+=dp[j-1][4];
                flag=false;
            }
            if(mton[j][i]&&mton[j][i2]==0&&mton[j][i3])
            {
                dp[j][0]+=dp[j-1][5];
                dp[j][1]+=dp[j-1][4];
                dp[j][2]+=dp[j-1][7];
                dp[j][3]+=dp[j-1][6];
                dp[j][4]+=dp[j-1][1];
                dp[j][5]+=dp[j-1][0];
                dp[j][6]+=dp[j-1][3];
                dp[j][7]+=dp[j-1][2];
                flag=false;
            }
            if(mton[j][i]==0&&mton[j][i2]&&mton[j][i3])
            {
                dp[j][0]+=dp[j-1][6];
                dp[j][1]+=dp[j-1][7];
                dp[j][2]+=dp[j-1][4];
                dp[j][3]+=dp[j-1][5];
                dp[j][4]+=dp[j-1][2];
                dp[j][5]+=dp[j-1][3];
                dp[j][6]+=dp[j-1][0];
                dp[j][7]+=dp[j-1][1];
                flag=false;
            }
            if(flag)
            {
                dp[j][0]+=dp[j-1][0]%MOD;
                dp[j][1]+=dp[j-1][1]%MOD;
                dp[j][2]+=dp[j-1][2]%MOD;
                dp[j][3]+=dp[j-1][3]%MOD;
                dp[j][4]+=dp[j-1][4]%MOD;
                dp[j][5]+=dp[j-1][5]%MOD;
                dp[j][6]+=dp[j-1][6]%MOD;
                dp[j][7]+=dp[j-1][7]%MOD;
            }
            dp[j][0]%=MOD;
            dp[j][1]%=MOD;
            dp[j][2]%=MOD;
            dp[j][3]%=MOD;
            dp[j][4]%=MOD;
            dp[j][5]%=MOD;
            dp[j][6]%=MOD;
            dp[j][7]%=MOD;
            }
            ans=(ans+dp[m][7]*6)%MOD;
        }
        printf("Case #%d: %I64d\n",ca,ans%MOD);
    }
    return 0;
}
