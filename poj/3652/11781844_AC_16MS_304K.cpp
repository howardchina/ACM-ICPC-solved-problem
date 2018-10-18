#include <stdio.h>
#include <string.h>
#include <bitset>
#include <iostream>
using namespace std;
bool visit[(1<<16)];
bitset<16>save;
bitset<16>cur;
bitset<16>flag;
int main()
{
    unsigned int A = 0, B = 0, C = 0, S = 0, i = 0;
    while(~scanf("%u", &A)) {
        if(!A) break;
        memset(visit, 0, sizeof(visit));
        save.reset();
        cur.reset();
        flag.reset();
        scanf("%u%u%u", &B, &C, &S);
        save = S;
        while(!visit[S]) {
            cur = S;
            for(i = 0; i < 16; i++) {
                if(save.test(i) != cur.test(i)) {
                    flag.set(i);
                }
            }
            visit[S] = true;
            S = (A*S+B)%C;
        }
        for(int i = 15; i >= 0; i--) {
            if(flag.test(i)) {
                printf("?");
            }
            else {
                cout<<save.test(i);
            }
        }
        printf("\n");
    }
    return 0;
}
