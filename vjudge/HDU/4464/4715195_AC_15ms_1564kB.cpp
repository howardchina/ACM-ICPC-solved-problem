#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;


char s[110];
int main()
{
//    freopen("data.in", "r", stdin);

    int n, cas = 1, t, ans;

    while(scanf("%d", &n)!=EOF){
        ans = 0;
        for(int i = 0; i < n; i++){
            scanf("%s", s);
            t = 0;
            for(int j = strlen(s)-1; j >= 0; j--){
                t += s[j];
                if (ans < t) ans = t;
            }
        }
        printf("Case %d: %d\n", cas++, ans);

    }
    return 0;
}
