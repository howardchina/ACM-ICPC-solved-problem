#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 110;
const int INF = 1e9;

int dp[maxn][maxn], ans[maxn];
char a[maxn], b[maxn];
int main()
{
//    freopen("data.in", "r", stdin);
    int n;
    while(scanf("%s", a)!=EOF){
        scanf("%s", b);
        n = strlen(a);

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                dp[i][j] = j-i+1;
            }
        }
        for(int i=n-2;i>=0;i--){
            for(int j=i+1;j<n;j++){
                dp[i][j] = dp[i+1][j]+1;
                for(int k=i+1;k<=j;k++){
                    if(b[i]==b[k]){
                        dp[i][j] = min(dp[i][j], dp[i+1][k]+dp[k+1][j]);
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            ans[i] = dp[0][i];
            if(a[i]==b[i]){
                if(i==0) ans[i] = 0;
                else ans[i] = ans[i-1];
            }
            for(int j=0;j<i;j++){
                ans[i] = min(ans[i], ans[j]+dp[j+1][i]);
            }
        }
        printf("%d\n", ans[n-1]);
    }

    return 0;
}
