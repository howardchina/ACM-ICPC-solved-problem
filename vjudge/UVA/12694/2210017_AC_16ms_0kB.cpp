#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct Node{
    int s, f;
}aa[22];
bool cmp(Node a, Node b){
    if(a.f != b.f) return a.f < b.f;
    return a.s < b.s;
}

int main()
{
//    freopen("data.in", "r", stdin);
    int n;
    scanf("%d", &n);
    while(n--){
        int i = 0;
        while(scanf("%d%d", &aa[i].s, &aa[i].f)){
            if(aa[i].s == 0 && aa[i].f == 0)break;
//            printf("%d=%d\n", aa[i].s, aa[i].f);
            i++;
        }
        sort(aa, aa+i, cmp);
//        for(int j = 0; j < i; j++)
//            printf("%d %d\n", aa[j].s, aa[j].f);
        int ans = 0, last;
        for(int j = 0; j < i; j++){
            if(j == 0){
                ans++;
                last = aa[j].f;
            }else if(aa[j].s >= last){
                ans++;
                last = aa[j].f;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
