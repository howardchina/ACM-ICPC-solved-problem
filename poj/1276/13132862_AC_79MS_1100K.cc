#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int  MaxV=100005;
int dp[MaxV], q[MaxV], qk[MaxV], head, tail, nowf, N, C, V, n, m, cur;

int main()
{
//    freopen("data.in", "r", stdin);
    while(scanf("%d%d", &m, &n) != EOF){
        cur=0;
        memset(dp, 0, sizeof dp);
        for(int i=0; i<n; i++){
            scanf("%d%d", &N, &V);
            C = V;
            N = min(N, m/C);
            for(int j = 0; j < C; j++){
                head = tail = 0;
                for(int k = 0; k <= (m-j)/C; k++){
                    nowf = dp[k*C+j]-k*V;
                    while(head < tail && (q[tail-1] <= nowf || qk[tail-1]+N < k))
                        tail--;
                    q[tail]=nowf; qk[tail++]=k;
                    while(head < tail && qk[head]+N < k)
                        head++;
                    dp[k*C+j] = q[head]+k*V;
                }
            }
        }
        printf("%d\n", dp[m]);
    }
    return 0;
}
