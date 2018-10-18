#include <iostream>
#include <cstdio>

using namespace std;
typedef unsigned long long type;
int main()
{
    type n;
    while(scanf("%llu", &n) != EOF && n){
        printf("%llu\n", (8*n*n + 12*n*n*n + 3*n*n*n*n + n*n*n*n*n*n)/24ULL);
    }
    return 0;
}
