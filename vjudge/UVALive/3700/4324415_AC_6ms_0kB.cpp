#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int N = 1111;

typedef long long LL;

int dp[N][N];

int p, n;

int brute(int v){
    int sum = 0, tmp;
    for(int i=1;i<=v;i++){
        for(int j=1;j<=i;j++){
            if (j==1 || j==i) {
                dp[i][j] = 1;
                continue;
            }
            tmp = dp[i-1][j-1] + dp[i-1][j];
            dp[i][j] = (tmp>=p)?tmp-p:tmp;
        }
    }
    for(int j=1;j<=v;j++){
        if (dp[v][j]) sum++;
    }
    return sum;
}

int F(int i, int v){
    int re;
    if(i==1){
        re = brute(v);
    }
    else{

        int m = v/i+1;
        int c = v%i;
        if(c == 0){
            c = i;
            m--;
        }
        re = F(i/p, c) * m;
    }
    return re;
}

void debug(){
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            printf(" ");
        }
        for(int j=1;j<=i;j++){
            printf("%d ", dp[i][j]);
        }
        puts("");
    }
    puts("");

}

int solve(){
    for(LL i=1;i<=n;i*=p){
        if(i<=n && n<i*p){
            return F(i, n);
        }
    }
    return -1;
}

int main()
{
//    freopen("data.in", "r", stdin);
//    freopen("data.out", "w", stdout);
    int ca=1;

//    for(int i=1;i<=100;i++){
//        for(int j=2;j<=100;j++){
//            int flag = 0;
//            for(int k=2;k<j;k++){
//                if(j%k==0) {
//                    flag = 1;
//                }
//            }
//            if (flag ) continue;
//            n = i+1;
//            p = j;
//            if(solve() != brute(n)){
//                printf("%d %d\n", n, p);
//                printf("%d %d\n", solve(), brute(n));
//                puts("!");
//            }
//        }
//    }

    while(scanf("%d%d", &p, &n)!=EOF && p+n){
        n++;
        int ans = solve();
        printf("Case %d: %04d\n", ca++, ans%10000);
//        printf("brute %d\n", brute(n));

//        debug();

    }


    return 0;
}
