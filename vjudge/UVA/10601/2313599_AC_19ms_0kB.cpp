#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define clr(a) memset(a,0,sizeof a)

int fact[13],cnt[7];

int cal(int n, int m){
    int ret = fact[n];
    for(int i = 1; i <= 6; i++){
        if(cnt[i]%m) return 0;
        ret /= fact[cnt[i]/m];
    }
    return ret;
}

int main()
{
//    freopen("data.in", "r", stdin);
    int T, x, i, j;
    int ans;
    fact[0] = 1;
    for( i = 1; i <= 12; i++)
        fact[i] = fact[i-1]*i;

    scanf("%d", &T);
    while(T--){
        clr(cnt);
        for( i = 0; i < 12; i++){
            scanf("%d", &x);
            cnt[x]++;
        }

        ans = cal(12,1) + 6*cal(3,4) + 3*cal(6,2) + 8*cal(4,3);
        for( i = 1; i <= 6; cnt[i]++,i++)
            for( j = 1, cnt[i]--; cnt[i] >= 0 && j <= 6; j++)
                if(cnt[j]){
                    cnt[j]--;
                    ans+=6*cal(5,2);
                    cnt[j]++;
                }
        printf("%d\n", ans/24);
    }
    return 0;
}
