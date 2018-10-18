#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MaxN = 101, MaxV = 100005;
int  qk[MaxV], V[MaxN], N[MaxN], n, m, ans, head, tail;
bool f[MaxV], q[MaxV];
int main()
{
//    freopen("data.in", "r", stdin);
    while(scanf("%d%d", &n, &m) != EOF && n!=0){
        if(m<0)m=0;
        for(int i=0; i<n; i++)
            scanf("%d", &V[i]);
        for(int i=0; i<n; i++){
            scanf("%d", &N[i]);
            if(N[i]>m/V[i])
                N[i]=m/V[i];
        }
        memset(f, 0, sizeof f);
        f[0] = 1;
        for(int i=0; i<n; i++){
            int maxi = N[i]*V[i];
            //0-1
            if(N[i] == 1){
                for(int j = m; j>=V[i]; j--)
                    f[j] = max(f[j], f[j-V[i]]);
            //complete pack
            }else if(maxi >= m-V[i]+1){
                for(int j = V[i]; j <= m; j++)
                    f[j] = max(f[j], f[j-V[i]]);
            }else{
                for(int j=0; j<V[i]; j++){
                    head = tail = 0;
                    for(int k=j; k<=m; k+=V[i]){
                        if(head != tail && k-qk[head] > maxi) head++;
                        if(f[k]){
                            q[tail] = f[k];
                            qk[tail] = k; tail++;
                        }else if(tail != head) f[k] = 1;
                    }
                }
            }
        }
        ans = 0;
        for(int i = 1; i <= m; i++)
            if(f[i]) ans++;
        printf("%d\n", ans);
    }
    return 0;
}
