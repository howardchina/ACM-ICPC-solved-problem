#include<stdio.h>
#include<string.h>

char Haab[19][10] = {
    "pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax",
    "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};
char Tzolkin[20][10] = {
     "imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok",
     "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};

int main(){
    int cnt = 0, d = 0, y = 0, sum = 0, i = 0, m2 = 0, y2 = 0;
    char m[10] = {0}, d2[10] = {0};
    scanf("%d", &cnt);
    while(cnt--) {
        sum = 0;
        scanf("%d. %s %d", &d, m, &y);
//        printf("%d %s %d\n", d, m, y);

        sum += y * 365;
        for(i = 0; i < 19; i++) {
            if(!strcmp(m, Haab[i])) {
                break;
            }
        }
        sum += i * 20;
        sum += d;

//        printf("%d\n", sum);

        y2 = sum / 260;
        m2 = sum % 13 + 1;
        strcpy(d2, Tzolkin[sum % 20]);

        printf("%d %s %d\n", m2, d2, y2);

    }
    return 0;
}
