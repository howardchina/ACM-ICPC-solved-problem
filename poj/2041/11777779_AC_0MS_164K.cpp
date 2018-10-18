#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

int main()
{
    int n = 0;
    scanf("%d", &n);
    char str[10], order[30];
    for(int i = 0; i < n; i++) {
        scanf("%s", str);
        scanf("%s", order);
        int r = strlen(str);
        int len = strlen(order);
        char ch;
        int t;
        for(int i = r-1; i >= 0; i--) {
            switch(str[i]){
                printf("str -- %c\n", str[i]);
                case 'J':
                    ch = order[len-1];
                    for(int j = len-1; j > 0; j--) {
                        order[j] = order[j-1];
                    }
                    order[0] = ch;
                    break;
                case 'C':
                    ch = order[0];
                    for(int j = 0; j < len-1; j++) {
                        order[j] = order[j+1];
                    }
                    order[len-1] = ch;
                    break;
                case 'E':
                    t = len/2;
                    for(int i = 0; i < t; i++) {
                        ch = order[i];
                        if(len%2) {
                            order[i] = order[i+t+1];
                            order[i+t+1] = ch;
                        }
                        else {
                            order[i] = order[i+t];
                            order[i+t] = ch;
                        }
                    }
                    break;
                case 'A':
                    t = len/2;
                    for(int i = 0; i < t; i++) {
                        ch = order[i];
                        order[i] = order[len-1-i];
                        order[len-1-i] = ch;
                    }
                    break;
                case 'P':
                    for(int i = 0; i < len; i++) {
                        if(order[i] >= '0' && order[i] <= '9') {
                            if(order[i] == '0') order[i] = '9';
                            else order[i]--;
                        }
                    }
                    break;
                case 'M':
                    for(int i = 0; i < len; i++) {
                        if(order[i] >= '0' && order[i] <= '9') {
                            if(order[i] == '9') order[i] = '0';
                            else order[i]++;
                        }
                    }
                    break;
            }
        }
        printf("%s\n", order);
    }
    return 0;
}
