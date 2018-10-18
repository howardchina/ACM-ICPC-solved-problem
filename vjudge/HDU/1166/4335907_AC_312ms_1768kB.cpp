#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define lowbit(x) (x&(-x))
const int N = 50010;
int s[N];
int n;
void add(int x, int v){
    while(x<=n){
        s[x] += v;
        x+=lowbit(x);
    }
}

int query(int x){
    int re=0;
    while(x>0){
        re += s[x];
        x-=lowbit(x);
    }
    return re;
}

int main()
{
//    freopen("data.in","r", stdin);
    int v,a,b,cas=1, T;
    char str[11];
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        printf("Case %d:\n", cas++);
        memset(s,0, sizeof s);
        for(int i=1;i<=n;i++){
            scanf("%d",&v);
            add(i, v);
        }
        while(scanf("%s", str)!=EOF && str[0]!='E'){
            scanf("%d%d",&a,&b);
            if (str[0]=='Q'){
                printf("%d\n", query(b)-query(a-1));
            }else{
                if(str[0] == 'S') b=-b;
                add(a,b);
            }
        }
    }
    return 0;
}
