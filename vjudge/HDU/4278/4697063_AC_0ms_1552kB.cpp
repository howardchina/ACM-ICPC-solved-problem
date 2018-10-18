#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int fa[11];
char s[11];

int main()
{
    int n, ans;
    fa[0] = 1;
    for(int i = 1; i < 10; i++){
        fa[i] = fa[i-1] * 8;
    }
    while(scanf("%d", &n) != EOF && n){
        int ans1 = n;
        ans = 0;
        while(n){
            for(int i = 0; n && i < 999999999; i++){
                int x = n%10;
                if(x > 8) ans += (x-2)*fa[i];
                else if(x > 3) ans += (x-1)*fa[i];
                else ans += x*fa[i];
                n /= 10;
            }
        }
        printf("%d: %d\n", ans1, ans);
    }
    return 0;
}
