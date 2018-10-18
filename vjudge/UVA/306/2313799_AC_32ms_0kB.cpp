#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int a[222], mp[222][222], cnt[222];
char src[222], des[222];

int main()
{
//    freopen("data.in", "r", stdin);
//    freopen("data.out", "w", stdout);
    int n, k;
    while(scanf("%d", &n) && n){
        for(int i = 0; i < n; i++){
            scanf("%d", &a[i]);
            a[i]--;
        }

        src[n] = des[n] = 0;

        for(int i = 0; i < n; i++){
            int t = i;
            for(int j = 0; j <= n; j++){
                mp[i][j] = t;
                if(t == i && j){
                    cnt[i] = j;
                    break;
                }
                t = a[t];
            }
        }

        while(scanf("%d", &k) != EOF){
            if(!k) break;
            getchar();
            gets(src);
            int len = strlen(src);
            for(int i = len; i < n; i++) src[i] = ' ';
            for(int i = 0; i < n; i++)
                des[mp[i][k%cnt[i]]] = src[i];
            puts(des);
        }
        puts("");
    }
    return 0;
}
