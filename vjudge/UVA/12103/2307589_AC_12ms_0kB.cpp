#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char str[30];
int p[60], cnt[30], c[30];

int find(int x){
    return p[x] != x?(p[x] = find(p[x])):x;
}

int main()
{
//    freopen("data.in", "r", stdin);
//    freopen("data.out", "w", stdout);
    int n;
    scanf("%d", &n);
    while(n--){
        scanf("%s", str);
        for(int i = 0; i < 26; i++) {
            p[i] = p[26+i] = 26+i;
        }
        for(int i = 0; i < 26; i++){
            int j = str[i] - 'A';
            int fi = find(i), fj = find(j);
            if(fi != fj){
                p[fj] = fi;
            }
        }
        memset(cnt, 0, sizeof cnt);
        memset(c, 0, sizeof c);
        for(int i = 0; i < 26; i++){
            cnt[find(i)-26]++;
        }
        for(int i = 0; i < 26; i++){
            if(cnt[i] && (cnt[i] & 1) == 0){
                c[cnt[i]]++;
            }
        }
        int ok = 1;
        for(int i = 2; i <= 26; i+=2){
            if(c[i] % 2){
                ok = 0;
                break;
            }
        }
        if(ok) puts("Yes");
        else puts("No");
    }
    return 0;
}
