#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef unsigned int UI;
int main()
{
    int cas, a, b;
    scanf("%d", &cas);
    for(int i = 1; i <= cas; i++){
        scanf("%d%d", &a, &b);
        printf("Case %d: %u\n", i, ((UI)a+(UI)b)/__gcd((UI)a, (UI)b));
    }
    return 0;
}
