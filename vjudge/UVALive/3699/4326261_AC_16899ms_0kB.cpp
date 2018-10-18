#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int a[40040];
int id[500050];

int main()
{
//    freopen("data.in", "r", stdin);
    int T, X, ca=1;
    char s[5];
    while(scanf("%d", &T)!=EOF && T){
        if(ca>1) puts("");
        printf("Case %d:\n", ca++);
        int cnt = 0, m = 0;
        memset(id, 0, sizeof id);
        for(int i=1;i<=T;i++){
            scanf("%s %d", s, &X);
            if(s[0]=='A'){
                int mn=-1;
                for(int i=1;i<=m;i++){
                    if(mn==-1){
                        mn = a[i];
                    }
                    else if(a[i]%X < mn%X){
                        mn = a[i];
                    }else if(a[i]%X == mn%X && id[a[i]]>id[mn]){
                        mn = a[i];
                    }
                }
                if(mn != -1) mn = id[mn];
                printf("%d\n", mn);
            }else{
                if(!id[X]){
                    a[++m] = X;
                }
                id[X] = ++cnt;
            }
        }
    }


    return 0;
}
