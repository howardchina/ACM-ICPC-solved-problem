#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 50050 ;
struct edge
{
    int dis;
    int len;
    int to;
    bool operator <(const edge &rhs)const{
        return dis>rhs.dis;
    }
};
vector<edge>edg[maxn];
struct Solver{
    int mi[20][maxn] , ma[20][maxn] ;
    int N ;
    int A[maxn] ,Log[maxn];

    void rmq_init(int n) {
        Log[0] = -1;
        for(int i=1; i<maxn; i++)
            Log[i] = (i&(i-1)) ?  Log[i-1] : Log[i-1] + 1 ;

        N = n ;
        for(int i=1; i<=n; i++) mi[0][i] = ma[0][i] = A[i] ;
        for(int j=1; (1<<j) <=n ;j++) {
            for(int i=1; i+(1<<j)-1 <= n; i++) {
                ma[j][i] = max( ma[j-1][i] , ma[j-1][i + (1<<(j-1)) ] )  ;
                mi[j][i] = min( mi[j-1][i] , mi[j-1][i + (1<<(j-1)) ] )  ;
            }
        }
    }
    int getmax(int L ,int R) {
        int k = Log[ R-L+1 ] ;
        return max( ma[k][L] , ma[k][R-(1<<k)+1] ) ;
    }

    int getmin(int L ,int R) {
        int k = Log[ R-L+1 ] ;
        return min( mi[k][L] , mi[k][R-(1<<k)+1] ) ;
    }


    int query(int Q) {
        int ret = 0 ;
        int p=1;
        for(int q=1; q<=N; q++) {
            //cout<<"val = " << getmax(p , q)<<" " << getmin(p , q) << endl;
            while(getmax(p , q) - getmin(p , q) > Q) p ++ ;
            ret = max(ret , q - p + 1) ;
        }
        return ret ;
    }

}sol;

int fa[maxn],fal[maxn],dd[maxn],df[maxn],ans[maxn];
void dfs(int x)
{
    int l=edg[x].size();
    dd[x]=0;
    for(int i=0;i<l;i++)
    {
        if(edg[x][i].to!=fa[x])
        {
            fa[edg[x][i].to]=x;
            fal[edg[x][i].to]=edg[x][i].len;
            dfs(edg[x][i].to);
            edg[x][i].dis=edg[x][i].len+dd[edg[x][i].to];
        }
    }
    if(l>0){
    sort(edg[x].begin(),edg[x].end());
    dd[x]=edg[x][0].dis;
    }
}
void dfs2(int x)
{
    int l=edg[x].size();
    df[x]=0;
    if(x!=1)
    {
        df[x]=df[fa[x]]+fal[x];
        for(int i=0;i<edg[fa[x]].size()&&i<3;i++)
        if(edg[fa[x]][i].to!=x)df[x]=max(df[x],fal[x]+edg[fa[x]][i].dis);
        //cout<<x<<" "<<df[x]<<endl;
    }
    for(int i=0;i<l;i++)
    {
        if(edg[x][i].to!=fa[x])
            dfs2(edg[x][i].to);
    }
    ans[x]=df[x];
    if(l>1||x==1)
        ans[x]=max(ans[x],edg[x][0].dis);
}
int main()
{
//    freopen("data.in", "r", stdin) ;

    int n,m;
    while(scanf("%d%d",&n,&m)&&n)
    {
        for(int i=1;i<=n;i++)edg[i].clear();
        for(int i=1;i<n;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            edge a;
            a.to=y;a.len=z;a.dis=0;
            edg[x].push_back(a);
            a.to=x;
            edg[y].push_back(a);
        }
        fa[1]=-1;
        memset(ans,0,sizeof ans);
        dfs(1);
        df[1]=0;
        dfs2(1);
        for(int i=1;i<=n;i++){
            //cout<<i<<" "<<ans[i]<<endl;
            sol.A[i] = ans[i]  ;

        }


        sol.rmq_init(n) ;

        //cout<<sol.getmax(2 ,3) <<endl;

        for(int i=1; i<=m; i++) {
            int Q ;
            scanf("%d",&Q) ;
            printf("%d\n" , sol.query(Q)) ;
        }


    }



    return 0;
}
