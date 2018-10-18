#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define lowbit(x) (x&(-x))
const int N = 1030;
int s[N][N];
int n;

void add(int x,int y,int v){
    for(int i=x;i<=n;i+=lowbit(i)){
        for(int j=y;j<=n;j+=lowbit(j)){
            s[i][j] += v;
        }
    }
}

int query(int x,int y){
    int re=0;
    for(int i=x;i>0;i-=lowbit(i)){
        for(int j=y;j>0;j-=lowbit(j)){
            re += s[i][j];
        }
    }
    return re;
}

int main()
{
//    freopen("data.in","r", stdin);
    int o,L,B,R,T,X,Y,A;
    while(scanf("%d", &o)!=EOF){
        scanf("%d", &n);
        memset(s,0, sizeof s);
        while(scanf("%d", &o) && o!=3){
            if (o==1){
                scanf("%d%d%d",&X,&Y,&A);
                add(X+1,Y+1,A);
            }else{
                scanf("%d%d%d%d", &L, &B, &R, &T);
                printf("%d\n", query(R+1,T+1)-query(L,T+1)-query(R+1,B)+query(L,B));
            }
        }
    }
    return 0;
}
