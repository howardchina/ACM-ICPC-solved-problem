#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int val[101];
int main()
{
    int N;
    for(int i=1;i<=100;i++)
        for(int j=i;j<=100;j++)
            val[j]+=(j-i+1)*(j-i+1);
    while(scanf("%d",&N)==1 && N)
        printf("%d\n",val[N]);
    return 0;
}
