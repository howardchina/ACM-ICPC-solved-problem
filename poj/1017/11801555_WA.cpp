#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int main()
{
    int n[7], ans, space;
    while(~scanf("%d%d%d%d%d%d", &n[1], &n[2], &n[3], &n[4], &n[5], &n[6])) {
        if(!n[1] && !n[2] && !n[3] && !n[4] && !n[5] && !n[6]) break;
        ans = 0;
        //6*6
        if(n[6]) {
            ans = n[6];
            n[6] = 0;
        }
        //5*5
        if(n[5]) {
            ans += n[5];
            n[5] = 0;
            space = 11 * n[5];
            if(space >= n[1]) {
                n[1] = 0;
            } else {
                n[1] -= space;
            }
        }
        //4*4
        if(n[4]) {
            ans += n[4];
            n[4] = 0;
            space = n[4]*20;
            if(space >= n[2]*4) {
                n[2] = 0;
                space -= n[2]*4;
                if(n[1]) {
                    if(n[1] >= space) {
                        n[1] -= space;
                    } else {
                        n[1] = 0;
                    }
                }
            } else {
                n[2] -= space/4;
            }
        }
        //3*3
        if(n[3]) {
            space = 0;
            ans += n[3]/4;
            n[3] %= 4;
            if(n[3]) ans++;
            if(n[3] == 1) {
                space = 27;
                if(n[2] >= 5) {
                     n[2] -= 5;
                } else {
                    space -= n[2]*4;
                }
            } else if(n[3] == 2) {
                space = 18;
                if(n[2] >= 3) {
                    n[2] -= 3;
                } else {
                    space -= n[2]*4;
                }
            } else if(n[3] == 3) {
                space = 9;
                if(n[2] >= 1) {
                    n[2] -= 1;
                } else {
                    space -= n[2]*4;
                }
            }
            n[3] = 0;
            if(space && n[1]) {
                if(space >= n[1]) {
                    n[1] = 0;
                } else {
                    n[1] -= space;
                }
            }

        }
        //2*2
        if(n[2]) {
            ans += n[2]/9;
            n[2] %= 9;
            space = 36 - n[2]*4;
            if(space && n[1]) {
                if(space >= n[1]) {
                    n[1] = 0;
                } else {
                    n[1] -= space;
                }
            }
        }
        //1*1
        if(n[1])
            ans += n[1]/36 + 1;
        printf("%d\n", ans);
    }
    return 0;
}
