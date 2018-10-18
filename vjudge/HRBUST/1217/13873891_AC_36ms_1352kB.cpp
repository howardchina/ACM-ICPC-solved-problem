#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int dp[211][41];
int g[211][211];
int h[211];
char str[211];
char w[8][211];

#define update(x,y) x==0?x=k:x=min(k,x)

int main()
{
    int P, K;

    while(scanf("%d%d", &P, &K)!=EOF){

        for(int i = 0; i < P; i++){
            scanf("%s", str+i*20);
        }

        int s;
        scanf("%d", &s);
        for(int i = 0; i < s; i++){
            scanf("%s", w[i]);
        }

        int n = P*20;
        memset(h, 0, sizeof(h));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < s; j++){
                int k = 0;
                while(str[i+k]==w[j][k] && str[i+k]!='\0' && w[j][k]!='\0'){
                    k++;
                }
                if(w[j][k]=='\0'){
                    update(h[i],k);
                }
            }
        }
        memset(g, 0, sizeof(g));
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                for(int k = i; k <= j; k++){
                    if(h[k]>0 && k+h[k]-1<=j){
                        g[i][j]++;
                    }
                }
            }
        }
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < n; i++){
            dp[i][1] = g[0][i];
        }
        for(int k = 2; k <= K; k++){
            for(int i = k-1; i < n; i++){
                for(int j = k-2; j < i; j++){
                    dp[i][k] = max(dp[i][k], dp[j][k-1]+g[j+1][i]);
                }
            }
        }
        printf("%d\n", dp[n-1][K]);
    }
    return 0;
}
