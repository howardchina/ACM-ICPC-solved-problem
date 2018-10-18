#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int n,m,p;
int cal(char c)
{
    if(c=='A')return 16;
    if(c=='B'){m++;return 7;}
    if(c=='C'){p++;return 8;}
    if(c=='D')return 1;
    if(c=='E')return 1;
    if(c=='F')return 2;
    if(c=='G')return 3;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int cr=0,cb=0;
        scanf("%d", &n);
        m=p=0;
        char s[10];
        for(int i = 0; i < n; i++){
            scanf("%s", &s);
            cr+=cal(s[0]);
        }
        if(m*p==0)cr--;
        if(cr==0)cr++;
        scanf("%d", &n);
        m=p=0;
        for(int i = 0; i < n; i++){
            scanf("%s", &s);
            cb+=cal(s[0]);
        }
        if(m*p==0)cb--;
        if(cb==0)cb++;
        if(cr>cb)printf("red\n");
        if(cr<cb)printf("black\n");
        if(cr==cb)printf("tie\n");

    }
    return 0;
}
