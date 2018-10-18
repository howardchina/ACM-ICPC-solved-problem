#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
const int maxn = 5050 ;

int f[] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};

char a[maxn][10] ;

string toInt(char *s){
    string ret = "" ;
    for(int i=0; s[i] ; i++) {
        ret += '0' + f[ s[i] - 'a' ] ;
    }
    return ret ;
}

int main()
{
    int T ;
    scanf("%d", &T) ;
    while(T--) {
        int N , M ;
        map<string , int> cnt ;
        scanf("%d%d", &N, &M) ;
        for(int i=1; i<=N; i++) scanf("%s" , a[i]) ;
        for(int i=1; i<=M; i++) {
            char buf[10] ;
            scanf("%s",buf) ;
            cnt[toInt(buf)] ++  ;
        }
        for(int i=1; i<=N; i++) {
            printf("%d\n" , cnt[ a[i] ]) ;
        }
    }
    return 0;
}
