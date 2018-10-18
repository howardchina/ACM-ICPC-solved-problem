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
    int n = 0;
    for(int i = 0; i < MAX; i++)
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
    for(int i = 0; i <= MAX; i++)
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
    int n1, n2, t;
    while(scanf("%d", &n1) != EOF)
    {
        memset(listOneP, 0, sizeof(listOneP));
        memset(listOneN, 0, sizeof(listOneN));
        memset(listTwoP, 0, sizeof(listTwoP));
        memset(listTwoN, 0, sizeof(listTwoN));
        for(int i = 0; i < n1; i++)
        {
            scanf("%d", &t);
            if(t<0) listOneN[-t] = true;
            else listOneP[t] = true;
        }
        scanf("%d", &n2);
        for(int i = 0; i < n2; i++)
        {
            scanf("%d", &t);
            if(t<0) listTwoN[-t] = true;
            else listTwoP[t] = true;
        }

        if(check()) puts("YES");
        else puts("NO");
    }
}
