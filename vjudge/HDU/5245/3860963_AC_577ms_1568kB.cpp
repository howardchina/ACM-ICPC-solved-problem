#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long LL ;
int N ,M, K ;


int check(int x1 ,int y1, int x2 , int y2 , int x , int y) {
    if(x1 > x2) swap(x1 , x2) ;
    if(y1 > y2) swap(y1 ,y2) ;
    return (x1<=x && x<=x2 && y1<=y && y<=y2) ;
}
int get_cnt(int x , int y) {
    int ret =0 ;
    for(int a=1; a<=N; a++)
    for(int b=1; b<=M; b++)
    for(int c=1; c<=N; c++)
    for(int d=1; d<=M; d++)
    ret += check(a , b, c , d , x , y) ;
    return ret ;
}


double cal(int x , int y) {
//    double sum = N * M ;
//    double num1 = x * y , num2 = (N-x+1) * (M-y+1) ;
//    double num3 = x * (M-y+1), num4 = (N-x+1) * y ;
//    double ret = num1/sum * num2 / sum / 2 ;
//    ret += num3/sum * num4 / sum / 2;
//    ret -= x/sum * (N-x+1)/sum / 2 - y/sum*(M-y+1)/sum/2 ;
//    ret += 1.0/sum*1.0/sum/2;

    LL cnt = 0 , sum = (LL)N*M*N*M;
    cnt += (LL)(x-1)*(y-1)*(N-x+1)*(M-y+1) ;
    cnt += (LL)(x-1)*(N-x+1)*M;
    cnt += (LL)(x-1)*(M-y)*(N-x+1)*y;
    cnt += (LL)(y-1)*N*(M-y+1);
    cnt += (LL)(M-y)*N*y;
    cnt += (LL)(N-x)*(y-1)*x*(M-y+1);
    cnt += (LL)(N-x)*x*M;
    cnt += (LL)(N-x)*(M-y)*x*y;
    cnt += (LL)1*N*M;

//    printf("%d %d %I64d  %d\n" , x, y, cnt , get_cnt(x , y)) ;

    return (double) cnt * 1.0/ sum ;
}

double Pow(double p , int n) {
    double ret = 1.0 ;
    while(n) {
        if(n&1) ret = ret * p ;
        p = p * p ;
        n >>= 1 ;
    }
    return ret ;
}

double solve(int x ,int y){
    double p = cal(x,  y);

    double ret = 1.0 - pow(1.0 - p , K) ;
    return ret ;
}

int main()
{
//    freopen("in.txt", "r", stdin) ;

    int T , cas = 1;
    scanf("%d", &T) ;
    while(T--){
        scanf("%d%d%d", &N, &M, &K) ;
        double ans = 0 ;
        for(int i=1; i<=N; i++)
            for(int j=1; j<=M; j++)
                ans += solve(i , j) ;
        int res = (int)(ans + 0.500000001);
//        printf("%.12f\n", ans);
        printf("Case #%d: %d\n", cas++ , res);
    }
    return 0;
}
