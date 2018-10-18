#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#define clr(x,k) memset((x),(k),sizeof(x))
#define MAX(a,b) ((a)>(b)?(a):(b))
using namespace std;

char s[505][505];
int n,m;
struct node{
    int x,y;
    bool f;   //表示是否为一个块的开头
    node(){};
    node(int xx,int yy,bool first){
        x=xx,y=yy,f=first;
    };
};
stack<node> sn;
bool visit[505][505];
int k;
int x1[4]={0,0,1,-1};
int y1[4]={1,-1,0,0};
#define legal(x,a) (1<=x&&x<=a)
void dfs(int xx,int yy){
    int _x,_y,i;
    for(i=0;i<4;i++){
        _x=xx+x1[i],_y=yy+y1[i];
        if(legal(_x,n)&&legal(_y,m)&&!visit[_x][_y]&&s[_x][_y]=='.'){
            visit[_x][_y]=true;
            sn.push(node(_x,_y,false));
            dfs(_x,_y);
        }
    }
}
int main(){
    int i,j;
    while(scanf("%d %d",&n,&m)!=EOF){
        getchar();
        for(i=1;i<=n;i++)
            gets(s[i]+1);
        sn.empty();
        k=0;
        clr(visit,false);
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++){
                if(!visit[i][j]&&s[i][j]=='.'){
                    k-=2;
                    visit[i][j]=true;
                    sn.push(node(i,j,true));
                    dfs(i,j);
                }
            }
        k+=sn.size()*3;
        printf("%d\n",k);
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                if(visit[i][j])
                    printf("B %d %d\n",i,j);
        node t;
        while(!sn.empty()){
            t = sn.top(); sn.pop();
            if(!t.f){
                printf("D %d %d\n",t.x,t.y);
                printf("R %d %d\n",t.x,t.y);
            }
        }
    }
    return 0;
}
