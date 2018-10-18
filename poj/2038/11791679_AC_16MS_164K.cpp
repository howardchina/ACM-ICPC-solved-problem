#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
char ch[110][6];
int charmap[100];
int n;
int Min;
int value;
int Diff(char * str) {
    int cnt = 0;
    for(int i = 0; i < 4; i++) {
        for(int j = i+1; j < 5; j++) {
            if(charmap[str[i]] > charmap[str[j]])
                cnt++;
        }
    }
    return cnt;
}

int main()
{
    char res[6];
    while(scanf("%d", &n) && n != 0) {
        for(int i = 0; i < n; i++) {
            scanf("%s", ch[i]);
        }
        char str[6] = "ABCDE";
        Min = 1000000;
        do {
            for(int i = 0; i < 5; i++) {
                charmap[str[i]] = i;
            }
            value = 0;
            for(int i = 0; i < n; i++) {
                value += Diff(ch[i]);
            }
            if(value < Min) {
                Min = value;
                strcpy(res, str);
            }
        }while(next_permutation(str, str+5));
        printf("%s is the median ranking with value %d.\n", res, Min);
    }
    return 0;
}