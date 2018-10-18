#include<stdio.h>
#include<math.h>
int a,b;
double x;
int main()
{
    while(~scanf("%d%d",&a,&b))
    {
        x = (1+sqrt(5.0)) / 2;
        if(a>b)
        {
            int temp = a;
            a = b ;
            b = temp;
        }
        int n = b - a;
        if(a == (int)(n * x))
            printf("0\n");
        else
            printf("1\n");
    }
    return 0;
}
