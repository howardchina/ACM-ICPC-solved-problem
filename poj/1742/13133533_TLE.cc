#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MaxN = 101, MaxV = 100005;
int f[MaxV], q[MaxV], qk[MaxV], V[MaxN], N[MaxN], n, m, ans, head, tail;
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
        for(int i=0; i<n; i++){
            int C = V[i];
            for(int j=0; j<C; j++){
                head = tail = 0;
                int a = (m-j)/C;
                for(int k=0; k<=a; k++){
                    int nowf = f[k*C+j]-k*V[i];
                    while(head < tail && q[tail-1] <= nowf)
                        tail--;
                    q[tail]=nowf; qk[tail++]=k;
                    while(qk[head] + N[i] < k)
                        head++;
                    f[k*C+j]=q[head]+k*V[i];
                }
            }
        }
        ans = 0;
        for(int i = 1; i <= m; i++)
            if(f[i] == i) ans++;
        printf("%d\n", ans);
    }
    return 0;
}
