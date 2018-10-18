#include <stdio.h>
int a[110];
int b[110];
int max(int a, int b)
{
    return a>b?a:b;
}

int main()
{
    int n, s, ans, MaxBi;
    while(~scanf("%d", &n)) {
        s = 0;
        for(int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            if(a[i]) s++;
            if(a[i]) a[i] = -1;
            else a[i] = 1;
        }
        for(int i = 0; i <= n; i++) {
            if(i == 0) b[0] = 0;
            else {
                b[i] = b[i-1] + a[i-1];
            }
        }
//        for(int i = 0; i < n; i++) {
//            printf("%3d", a[i]);
//        }
//        puts("");
//        for(int i = 0; i <= n; i++) {
//            printf("%3d", b[i]);
//        }
//        puts("");

        ans = b[n] - b[n-1];
        MaxBi = b[n];
        for(int i = n-1; i >= 0; i--) {
            ans = max(ans, MaxBi-b[i]);
            MaxBi = max(b[i],MaxBi);
        }
        printf("%d\n", s+ans);
    }

    return 0;
}