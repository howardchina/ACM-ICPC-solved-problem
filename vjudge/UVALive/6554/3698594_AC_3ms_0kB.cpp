#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;
#define x first
#define y second
#define mp make_pair
const int maxn = 1111;
int m[2][maxn];
int n[2];
void go(int val){
    int cur=0;
    int tmp=val%n[cur];
    while(m[cur][tmp]!=-1){
        swap(val,m[cur][tmp]);
        cur^=1;
        tmp = val%n[cur];
    }
    m[cur][tmp]=val;
//    printf("m[%d][%d]=%d\n",cur,tmp,m[cur][tmp]);
}

void output(){
    for(int k=0;k<2;k++){
        int fst=1;
        for(int i=0;i<n[k];i++){
            if(m[k][i]!=-1){
                if(fst){
                    printf("Table %d\n",k+1);
                    fst=0;
                }
                printf("%d:%d\n",i,m[k][i]);
            }
        }
    }
}

bool solve(){
    int q,x,re;
    re=scanf("%d%d%d",&n[0],&n[1],&q);
    if(re==EOF || re!=3 || (n[0]==0 && n[1]==0 && q==0)) return false;
    memset(m,-1,sizeof m);
    while(q--){
        scanf("%d",&x);
        go(x);
    }
    return true;
}

int main()
{
//    freopen("data.in","r",stdin);
    int cas=1;
    while(solve()){
        printf("Case %d:\n",cas++);
        output();
    }
    return 0;
}
