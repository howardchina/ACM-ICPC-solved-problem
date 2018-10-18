#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int money[10010];
string name[10010];
int main()
{
//    freopen("data.in","r",stdin);
    int t;
    scanf("%d",&t);
    for(int ca=1;ca<=t;ca++)
    {
        int u,m;
        memset(money,0,sizeof money);
        scanf("%d%d",&u,&m);
        for(int i=1;i<=m;i++)
        {
            int k;
            //cout<<"?"<<endl;
            string nm;
            cin>>nm;
//            cout<<nm<<endl;
            scanf("%d",&k);
            //cout<<s<<k<<endl;
            if(money[k]>0)
            {
                //name[k]=s;
                money[k]++;
            }
            //cout<<s<<k<<endl;
            if(money[k]==0)
            {
                name[k]=nm;
                money[k]=1;
            }
            //cout<<s<<k<<endl;
        }
        int ok=1;
        for(int i=1;i<=u;i++)
        {
            if(money[i]==1)
            {
                printf("Case %d:\nThe winner is %s.\nThe price is %d.\n",ca,name[i].c_str(),i);
                ok=0;
                break;
            }
        }
        int bans=m,ans;
        if(ok==1)
        {
        for(int i=1;i<=u;i++)
        {
            if(money[i]>0&&money[i]<bans)
            {
                bans=money[i];
                ans=i;
            }
        }
        printf("Case %d:\nThe winner is %s.\nThe price is %d.\n",ca,name[ans].c_str(),ans);
        }
        if(ca!=t) puts("");
    }
}
