#include <stdio.h>
#include <string.h>
const int max = 100000+ 100;
int root, cnt;
struct node{
    int next[26];
    char les[12];
} dic[max*26];
char le1[12], le2[12];
void Insert(char *str, char *re)
{
    int len = strlen(str);
    if(len == 0) return;
    int cur = root;
    for(int i = 0; i < len; i++) {
        if(dic[cur].next[str[i]-'a'] == -1) {
            for(int j = 0; j < 26; j++) {
                dic[cnt].next[j] = -1;
                dic[cnt].les[0] = '\0';
            }
            dic[cur].next[str[i]-'a'] = cnt++;
        }
        cur = dic[cur].next[str[i]-'a'];
    }
    strcpy(dic[cur].les, re);
}

char* Find(char *str)
{
    int cur = root;
    int len = strlen(str);
    if(len == 0) return 0;
    for(int i = 0; i < len; i++) {
        if(dic[cur].next[str[i]-'a'] == -1)
            return NULL;
        cur = dic[cur].next[str[i]-'a'];
    }
    return dic[cur].les;
}

void input(char * str)
{
    int len = strlen(str);
    int i, j;
    for(i = 0; str[i] != ' ' && i < len; i++) {
        le1[i] = str[i];
    }
    i++;
    for(j = 0; i < len; j++, i++) {
        le2[j] = str[i];
    }
    Insert(le2, le1);
}

int main()
{
    char *ans;
    for(int i = 0; i < 26; i++) dic[0].next[i] = -1;
    root = 0; cnt = 1;
    char str[30];
    while(gets(str) && str[0]) {
        input(str);
    }
    while(~scanf("%s", le1)) {
        ans = Find(le1);
        if(ans != NULL && ans[0] != '\0') {
            printf("%s\n", ans);
        } else {
            puts("eh");
        }
    }
    return 0;
}
