#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1500 ;

int N ,M ;
char s[20] ;
bool infect[maxn] ;

int get_val()
{
    int ret = 0;
    for(int i=0; i<N; i++)
    {
        ret = ret * 2 + s[i] - '0' ;
    }
    return ret ;
}

void readin()
{
    scanf("%s", s);
    int id = -1 ;
    for(int i=0; i<N; i++)
    {
        if(s[i] == '*') id = i ;
    }
    if(id == -1)
    {
        infect[get_val()] = true ;
    }
    else
    {
        s[id] = '1' , infect[get_val()] = true ;
        s[id] = '0' , infect[get_val()] = true ;
    }
}


const int MAXN = 1030;
int uN,vN;//u,v的数目，使用前面必须赋值
int g[MAXN][MAXN];//邻接矩阵
int linker[MAXN];
bool used[MAXN];
bool dfs(int u)
{
    for(int v = 0; v < vN; v++)
        if(g[u][v] && !used[v])
        {
            used[v] = true;
            if(linker[v] == -1 || dfs(linker[v]))
            {
                linker[v] = u;
                return true;
            }
        }
    return false;
}
int hungary()
{
    int res = 0;

    memset(linker,-1,sizeof(linker));
    for(int u = 0; u < uN; u++)
    {
        memset(used,false,sizeof(used));
        if(dfs(u))res++;
    }
    return res;
}


int main()
{

//    freopen("data.in", "r", stdin) ;

    while(scanf("%d%d",&N, &M) == 2 && N+M)
    {
        memset(infect , 0 ,sizeof(infect)) ;
        for(int i=1; i<=M; i++)
        {
            readin() ;
        }


        uN = vN = (1<<N) ;

        int sum = 0;

        for(int i=0; i<(1<<N) ; i++) {
            if(infect[i]) sum ++ ;
            for(int j=0; j<(1<<N); j++) {
                if(i==j || !infect[i] || !infect[j]) g[i][j] = 0 ;
                else {
                    int tmp = i ^ j;
                    if(tmp & (tmp-1)) g[i][j] = 0 ;
                    else g[i][j] = 1 ;
                }
            }
        }


        int ans = sum - hungary() / 2 ;

        printf("%d\n" , ans);

    }
    return 0;
}
