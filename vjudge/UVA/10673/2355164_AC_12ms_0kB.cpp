#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
//    freopen("data.in", "r", stdin);
    int T, n, k, g, a, b;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &n, &k);
        b = n-n/k*k;
        a = k-b;
        printf("%d %d\n", a, b);
    }
    return 0;
}
