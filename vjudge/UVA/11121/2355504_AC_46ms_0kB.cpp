#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int b[44];
int main()
{
    int T, cas=1, n, i, tmp;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        memset(b, 0, sizeof b);
        i = 0, tmp = -2;
        while(n != 0){
            if(n%tmp){
                b[i] = 1;
                n -= tmp/-2;
            }else
                b[i] = 0;
            i++;
            tmp*=-2;
        }
        for(i = 40; i >= 1; i--)
            if(b[i] == 1) break;
        printf("Case #%d: ", cas++);
        while(i >= 0)
            printf("%d", b[i--]);
        puts("");
    }
    return 0;
}