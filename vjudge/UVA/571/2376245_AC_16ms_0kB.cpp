#include <cstdio>
inline int min(int a, int b){return a<b?a:b;}
int main()
{
    int a, b, c, e, f;
    while(scanf("%d%d%d", &a, &b, &c) != EOF){
        e = f = 0;
        while(f != c){
            if(e == 0){
                e = a;
                puts("fill A");
            }else if(f == b){
                f = 0;
                puts("empty B");
            }else{
                int u = min(b - f, e);
                e -= u;
                f += u;
                puts("pour A B");
            }
        }
        puts("success");
    }
    return 0;
}
