#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

char s[10][10] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};

int d[300];

int main()
{
//    freopen("data.in", "r", stdin);
//    freopen("data.out", "w", stdout);
    int T, n;
    int sum = 0;
    for(int i=1;i<=294;i++){
        int x = 1;
        for(int j=1;j<=i;j++){
            x = x*i%7;
        }
        sum = (sum + x)%7;
        d[i] = sum;
    }
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        int x = d[n%294];
        printf("%s\n", s[x]);
    }

    return 0;
}
