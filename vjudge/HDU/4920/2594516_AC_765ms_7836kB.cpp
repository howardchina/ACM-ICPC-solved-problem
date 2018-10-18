#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
inline void rd(int &ret)
{
	char c;
	do { c = getchar();
	} while(c < '0' || c > '9');
	ret = c - '0';
	while((c=getchar()) >= '0' && c <= '9')
		ret = ret * 10 + ( c - '0' );
}
inline void ot(int a)    //输出外挂
{
    if(a>9)
        ot(a/10);
    putchar(a%10+'0');
}
const int MAX_N = 807;

int n;
int a[MAX_N][MAX_N], b[MAX_N][MAX_N];
int c[MAX_N][MAX_N];

int main() {
    while (1 == scanf("%d", &n)) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int x;
                rd(x);
                a[i][j] = x % 3;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int x;
                rd(x);
                b[i][j] = x % 3;
            }
        }
        memset(c, 0, sizeof(c));
        for (int i = 0; i < n; ++i) {
            for (int k = 0; k < n; ++k) {
                if (a[i][k] == 0) continue;
                for (int j = 0; j < n; ++j) {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j == 0) ot(c[i][j]%3);
				else {putchar(' '); ot(c[i][j]%3);}
            }
            puts("");
        }
    }
    return 0;
}
