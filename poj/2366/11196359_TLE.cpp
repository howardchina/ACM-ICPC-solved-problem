#include <cstdio>
#include <cstring>
#define SIZE 50001
#define MAX 32768

bool listOneP[MAX];
bool listOneN[MAX+1];
bool listTwoP[MAX];
bool listTwoN[MAX+1];

bool check()
{
    short n = 0;
    for(short i = 0; i < MAX; i++)
    {
        if(listOneP[i])
        {
            n = 10000 - i;
            if(n < -MAX || n >= MAX) continue;
            if(n < 0)
            {
                if(listTwoN[-n])
                    return true;
            }
            else
            {
                if(listTwoP[n])
                    return true;
            }
        }
    }
    for(short i = 0; i <= MAX; i++)
    {
        if(listOneN[i])
        {
            n = 10000 - i;
            if(n < -MAX || n >= MAX) continue;
            if(n < 0)
            {
                if(listTwoN[-n])
                    return true;
            }
            else
            {
                if(listTwoP[n])
                    return true;
            }
        }
    }
    return false;
}

int main()
{
    short n1, n2, t;
    while(scanf("%hd", &n1) != EOF)
    {
        memset(listOneP, 0, sizeof(listOneP));
        memset(listOneN, 0, sizeof(listOneN));
        memset(listTwoP, 0, sizeof(listTwoP));
        memset(listTwoN, 0, sizeof(listTwoN));
        for(short i = 0; i < n1; i++)
        {
            scanf("%hd", &t);
            if(t<0) listOneN[-t] = true;
            else listOneP[t] = true;
        }
        scanf("%hd", &n2);
        for(short i = 0; i < n2; i++)
        {
            scanf("%hd", &t);
            if(t<0) listTwoN[-t] = true;
            else listTwoP[t] = true;
        }

        if(check()) puts("YES");
        else puts("NO");
    }
}
