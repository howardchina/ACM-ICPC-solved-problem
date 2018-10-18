#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 1000050 ;
const LL MOD = 1e9 + 9 ;

char s[3][maxn] ;
int len[3] , N ;
int trans[30][30][30][4][4];
LL dp[maxn][4];

inline int id(char c) {
    if(c == 0) return 0 ;
    if(c == '?') return 27 ;
    return c - 'a' + 1 ;
}

int get_sta(int a, int b  , int c) {
    int ret =0 ;
    if(a < b) ret |= 1 ;
    if(b < c) ret |= 2 ;
    return ret ;
}

void init() {
    int lx,rx,ly,ry,lz,rz;
    for(int X=0; X<28; X++) for(int Y=0; Y<28; Y++) for(int Z=0; Z<28; Z++) {
        if(X == 27) lx = 1 , rx = 26 ; else lx = rx = X ;
        if(Y == 27) ly = 1 , ry = 26 ; else ly = ry = Y ;
        if(Z == 27) lz = 1 , rz = 26 ; else lz = rz = Z ;
        for(int x=lx; x<=rx; x++) for(int y=ly; y<=ry; y++) for(int z=lz;z<=rz; z++) {
            trans[X][Y][Z][3][3] ++ ;
            if(x == y) trans[X][Y][Z][2][2]++;
            else if(x<y) trans[X][Y][Z][2][3] ++ ;
            if(y == z) trans[X][Y][Z][1][1] ++;
            else if(y<z) trans[X][Y][Z][1][3]++;
            if(x == y && y==z) trans[X][Y][Z][0][0] ++;
            else if(x <y && y==z) trans[X][Y][Z][0][1] ++ ;
            else if(x==y && y<z) trans[X][Y][Z][0][2] ++ ;
            else if(x<y && y<z) trans[X][Y][Z][0][3]++ ;
        }
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
   // freopen("out.txt", "w", stdout);

    init() ;
    int T;
    scanf("%d", &T);
    while(T--){
        memset(dp ,0 ,sizeof(dp));
        memset(s , 0,  sizeof(s));
        N = 0 ;
        for(int i=0; i<3; i++) {
            scanf("%s", s[i]+1) ;
            len[i] = strlen(s[i]+1) ;
            N = max(N , len[i]) ;
        }
        dp[0][0]= 1;
        for(int i=1;i<=N; i++){
            int x = id(s[0][i]);
            int y = id(s[1][i]) ;
            int z = id(s[2][i]) ;
            for(int v=0; v<4; v++){
                for(int u=0; u<4; u++){
                    dp[i][v] += dp[i-1][u] * trans[x][y][z][u][v];
                    dp[i][v] %= MOD ;
                }
            }
        }

        LL ans = dp[N][3];
        //cout<<dp[7][3]<<endl;

        printf("%lld\n" , ans) ;

    }
    return 0;
}
