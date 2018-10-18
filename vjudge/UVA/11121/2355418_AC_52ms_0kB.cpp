#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int b[44];

int main()
{
//    freopen("data.in", "r", stdin);
    int T, cas=1, n, i;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        memset(b, 0, sizeof b);
        if(n >= 0){
            for(i = 0; (1<<i) <= n; i++){
                if((1<<i)&n){
                    if(i&1) b[i]++, b[i+1]++;
                    else b[i]++;
                }
            }
        }else{
            n = -n;
            for(i = 0; (1<<i) <= n; i++){
                if((1<<i)&n){
                    if(i&1) b[i]++;
                    else b[i]++, b[i+1]++;
                }
            }
        }
        for(i = 0; i < 40; i++){
            if(b[i] == 2)
                b[i] = 0, b[i+1]++, b[i+2]++;
            else if(b[i] == 3)
                b[i] = 1, b[i+1]++, b[i+2]++;
            else if(b[i] == 4)
                b[i] = 0, b[i+1], b[i+2]++;
        }
        for(i = 40; i >= 1; i--){
            if(b[i] == 1) break;
        }
        printf("Case #%d: ", cas++);
        while(i >= 0)
            printf("%d", b[i--]);
        puts("");
    }
    return 0;
}
