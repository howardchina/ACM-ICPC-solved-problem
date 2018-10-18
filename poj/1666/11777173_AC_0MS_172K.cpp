#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

int n, stu[1000], give[1000];


int main()
{
    while(scanf("%d", &n)) {
        if(!n) break;
        for(int i = 0; i < n; i++) {
            scanf("%d", &stu[i]);
        }
        int time = 0;
        while(true) {
            bool flag = 0;
            for(int i = 0; i < n; i++) {
                if(i > 0 && stu[i] != stu[0]) {
                    flag = 1;
                    break;
                }
            }
            if(!flag) break;

            time++;

            for(int i = 0; i < n; i++) {
                give[i] = stu[i]/2;
            }

            for(int i = 0; i < n; i++) {
                stu[i] = give[i] + give[(i+1)%n];
                if(stu[i]%2) {
                    stu[i]++;
                }
            }

        }

        printf("%d %d\n", time, stu[0]);

    }

    return 0;
}
