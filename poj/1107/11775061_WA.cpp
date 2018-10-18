#include<stdio.h>
#include<string.h>
char str[100] = {0};
char str1[100] = {0};
char str2[100] = {0};
char str3[100] = {0};

int main()
{
    int a, b, c, len, alen, blen, clen;
    while(scanf("%d%d%d", &a, &b, &c)) {
        if(a == 0 && b == 0 && c == 0) {
            break;
        }
        scanf("%s", str);
        len = strlen(str);
        alen = blen = clen = 0;
        for(int i = 0; i < len; i++) {
            if(str[i] >= 'a' && str[i] <= 'i') {
                str1[alen] = str[i];
                alen++;
            }
            else if(str[i] >= 'j' && str[i] <= 'r') {
                str2[blen] = str[i];
                blen++;
            }
            else {
                str3[clen] = str[i];
                clen++;
            }
        }
//        puts(str1);
//        puts(str2);
//        puts(str3);

        int t1 = 0, t2 = 0, t3 = 0;
        for(int i = 0; i < len; i++) {
            if(str[i] >= 'a' && str[i] <= 'i') {
                printf("%c", str1[(t1-a+alen)%alen]);
                t1++;
            }
            else if(str[i] >= 'j' && str[i] <= 'r') {
                printf("%c", str2[(t2-b+blen)%blen]);
                t2++;
            }
            else {
                printf("%c", str3[(t3-c+clen)%clen]);
                t3++;
            }
        }
        printf("\n");
    }


    return 0;
}
