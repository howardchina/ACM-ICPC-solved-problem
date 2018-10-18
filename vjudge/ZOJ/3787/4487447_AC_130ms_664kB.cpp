#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 20000 + 10;
struct Node{
    int h, m, s, id;
    bool operator <(const Node& rhs)const{
        if (h != rhs.h) return h < rhs.h;
        if (m != rhs.m) return m < rhs.m;
        return s < rhs.s;
    }
    int operator -(const Node& rhs)const{
        return h * 3600 + m * 60 + s - (rhs.h * 3600 + rhs.m * 60 + rhs.s);
    }
}a[N];
int ans[N];
int main()
{
//    freopen("data.in", "r", stdin);
    int T, n, l;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &n, &l);
        for(int i=0;i<n;i++){
            scanf("%d:%d:%d", &a[i].h, &a[i].m, &a[i].s);
            a[i].id = i+1;
        }
        sort(a, a+n);
        int p = 0, cnt = 0;
        ans[cnt++] = a[0].id;
        for(int i=1; i < n; i++){
            if (a[i] - a[p] >= l){
                p = i;
                ans[cnt++] = a[i].id;
            }
        }
        sort(ans, ans+cnt);
        printf("%d\n", cnt);
        printf("%d", ans[0]);
        for(int i=1;i < cnt; i++){
            printf(" %d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}
