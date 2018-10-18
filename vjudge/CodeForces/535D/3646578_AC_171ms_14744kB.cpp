#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef unsigned long long LL ;
const int maxn = 1000050 ;

char p[maxn];
int N ,P , M;
int a[maxn] , f[maxn], vis[maxn];
void getFail(char *s , int *f) {
    int m = strlen(s) ;
    f[0] = 0 ;
    f[1] = 0 ;
    for(int i=1; i<m;i ++){
        int j = f[i] ;
        while(j && s[i]!=s[j]) j = f[j] ;
        f[i+1] = s[i] == s[j] ? j+1 : 0 ;
    }
}

int main()
{

    scanf("%d%d", &N, &M) ;
    scanf("%s", p+1) ;
    for(int i=1; i<=M; i++) scanf("%d", &a[i]) ;

    P = strlen(p+1) ;
    getFail(p+1 , f) ;
    int x = P ;
    while(x) {
        vis[x] = 1 ;
        x = f[x] ;
    }

    bool flag = true ;
    int last = 0 ;
    for(int i=1; i<=M; i++) {
        if(last >= a[i]) {
            int len = last - a[i] + 1 ;
            if(!vis[len]) {
                flag = false ;
                break ;
            }
        }
        last = a[i] + P - 1 ;
    }

    if(!flag) {
        puts("0");
        return 0 ;
    }

    int sum = 0 ;
    if(M > 0) {
        sum += a[1] - 1 ;
        sum += N - ( a[M] + P - 1) ;
        for(int i=1; i<M; i++) {
            if(a[i+1] > a[i]+P-1) {
                sum += a[i+1] - ( a[i]+P-1 ) - 1 ;
            }
        }
    }
    else sum = N ;

    long long ans = 1 ;
    for(int i=1; i<=sum; i++) {
        ans = ans * 26 % 1000000007 ;
    }
    printf("%I64d\n", ans) ;
    return 0;
}

