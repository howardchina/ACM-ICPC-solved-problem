#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define lowbit(x) (x&(-x))
const int N = 100010;
int s[N];
int n;
void add(int x, int v){
    while(x>0){
        s[x] += v;
        x-=lowbit(x);
    }
}

int query(int x){
    int re=0;
    while(x<=n){
        re += s[x];
        x+=lowbit(x);
    }
    return re;
}

int main()
{
//    freopen("data.in","r", stdin);
    int a,b;
    while(scanf("%d", &n)!=EOF && n){
        memset(s,0, sizeof s);
        for(int i=0;i<n;i++){
            scanf("%d%d",&a,&b);
            add(a-1,-1);
            add(b,1);
        }
        for(int i=1;i<=n;i++){
            printf("%d%c", query(i), i<n?' ':'\n');
        }
    }
    return 0;
}
