#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char d[][10] =
    {"zero","one","two","three","four",
    "five","six","seven","eight","nine"};
char t[][10] =
    {"ten","twenty","thirty","forty","fifty",
    "sixty","seventy","eighty","ninety"};
char s[][10] =
    {"eleven","twelve","thirteen","fourteen","fifteen",
    "sixteen","seventeen","eighteen","nineteen"};



int main()
{
    int n;
    scanf("%d",&n);
    if(0<=n && n<=9){
        puts(d[n]);
    }else if(n%10==0){
        puts(t[n/10-1]);
    }else if(11<=n && n<=19){
        puts(s[n-11]);
    }else{
        printf("%s-%s\n",t[n/10-1],d[n%10]);
    }
    return 0;
}
