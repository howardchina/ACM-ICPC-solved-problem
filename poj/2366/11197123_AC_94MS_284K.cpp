#include <cstdio>
#include <cstdlib>
#define SIZE 50001
#define LOW -32768
#define MAX 32767
short list1[SIZE];
short list2[SIZE];

bool check(short * a, int l, int r, int v)
{
    if(v < LOW || v > MAX) return false;
    int mid;
    while(l < r)
    {
        mid = (l + r) >> 1;
        if(a[mid] < v)
            l = mid + 1;
        else
            r = mid;
    }
    if(a[l] == v)
        return true;
    else
        return false;
}

int main()
{
    int n1, n2;
    while(scanf("%d", &n1) != EOF)
    {
        for(int i = 0; i < n1; i++)
        {
            scanf("%hd", list1+i);
        }
        scanf("%d", &n2);
        for(int i = 0; i < n2; i++)
        {
            scanf("%hd", list2+i);
        }
        bool find = false;
        for(int i = 0; i < n2; i++)
        {
            if(find = check(list1, 0, n1 - 1, 10000 - list2[i])) break;
        }
        if(find) puts("YES");
        else puts("NO");


    }
}
