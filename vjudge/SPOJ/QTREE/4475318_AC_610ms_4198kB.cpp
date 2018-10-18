/* ***********************************************
Author        :kuangbin
Created Time  :2013-9-3 21:06:05
File Name     :F:\2013ACM练习\专题学习\动态树-LCT\SPOJQTREE.cpp
************************************************ */

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

//对一颗树，进行两个操作：
//1.修改边权
//2.查询u->v路径上边权的最大值
const int MAXN = 10010;
int ch[MAXN][2],pre[MAXN];
int Max[MAXN],key[MAXN];
bool rt[MAXN];
void push_down(int r)
{
    
}
void push_up(int r)
{
    Max[r] = max(max(Max[ch[r][0]],Max[ch[r][1]]),key[r]);
}
void Rotate(int x)
{
    int y = pre[x], kind = ch[y][1]==x;
    ch[y][kind] = ch[x][!kind];
    pre[ch[y][kind]] = y;
    pre[x] = pre[y];
    pre[y] = x;
    ch[x][!kind] = y;
    if(rt[y])
        rt[y] = false, rt[x] = true;
    else 
        ch[pre[x]][ch[pre[x]][1]==y] = x;
    push_up(y);
}
void P(int r)
{
    if(!rt[r])P(pre[r]);
    push_down(r);
}
void Splay(int r)
{
    //P(r);
    while( !rt[r] )
    {
        int f = pre[r], ff = pre[f];
        if(rt[f])
            Rotate(r);
        else if( (ch[ff][1]==f)==(ch[f][1]==r) )
            Rotate(f), Rotate(r);
        else
            Rotate(r), Rotate(r);
    }
    push_up(r);
}
int Access(int x)
{
    int y = 0;
    do
    {
        Splay(x);
        rt[ch[x][1]] = true, rt[ch[x][1]=y] = false;
        push_up(x);
        x = pre[y=x];
    }
    while(x);
    return y;
}
//调用后u是原来u和v的lca,v和ch[u][1]分别存着lca的2个儿子
//(原来u和v所在的2颗子树)
void lca(int &u,int &v)
{
    Access(v), v = 0;
    while(u)
    {
        Splay(u);
        if(!pre[u])return;
        rt[ch[u][1]] = true;
        rt[ch[u][1]=v] = false;
        push_up(u);
        u = pre[v = u];
    }
}

void change(int u,int k)
{
    Access(u);
    key[u] = k;
    push_up(u);
}
void query(int u,int v)
{
    lca(u,v);
    printf("%d\n",max(Max[v],Max[ch[u][1]]));
}

struct Edge
{
    int to,next;
    int val;
    int index;
}edge[MAXN*2];
int head[MAXN],tot;
int id[MAXN];

void addedge(int u,int v,int val,int index)
{
    edge[tot].to = v;
    edge[tot].next = head[u];
    edge[tot].val = val;
    edge[tot].index = index;
    head[u] = tot++;
}
void dfs(int u)
{
    for(int i = head[u];i != -1;i = edge[i].next)
    {
        int v = edge[i].to;
        if(pre[v] != 0)continue;
        pre[v] = u;
        id[edge[i].index] = v;
        key[v] = edge[i].val;
        dfs(v);
    }
}
void init()
{
    tot = 0;
    memset(head,-1,sizeof(head));
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    int n;
    int u,v,w;
    char op[20];
    scanf("%d",&T);
    while(T--)
    {
        init();
        scanf("%d",&n);
        for(int i = 0;i <= n;i++)
        {
            pre[i] = 0;
            ch[i][0] = ch[i][1] = 0;
            rt[i] = true;
        }
        Max[0] = -2000000000;
        for(int i = 1;i < n;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            addedge(u,v,w,i);
            addedge(v,u,w,i);
        }
        pre[1] = -1;
        dfs(1);
        pre[1] = 0;
        while(scanf("%s",&op) == 1)
        {
            if(op[0] == 'D')break;
            scanf("%d%d",&u,&v);
            if(op[0] == 'C')
                change(id[u],v);
            else query(u,v);
        }
    }
    return 0;
}