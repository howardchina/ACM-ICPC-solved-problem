#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char ba[70] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";


void solve(char* a,char* b){
    int n=strlen(a);
    int bn=0;
    int tmp[4];
    for(int i=0;i<n;i+=3){
        if(i<n-2){
            tmp[0]=(a[i]>>2)&(0b111111);
            tmp[1]=(a[i]<<4)&(0b111111);tmp[1]|=(a[i+1]>>4)&(0b111111);
            tmp[2]=(a[i+1]<<2)&(0b111111);tmp[2]|=(a[i+2]>>6)&(0b111111);
            tmp[3]=(a[i+2])&(0b111111);
            for(int j=0;j<4;j++){
                b[bn+j]=ba[tmp[j]];
            }
        }else if(i==n-1){
            tmp[0]=(a[i]>>2)&(0b111111);
            tmp[1]=(a[i]<<4)&(0b111111);

            b[bn+0]=ba[tmp[0]];
            b[bn+1]=ba[tmp[1]];
            b[bn+2]='=';
            b[bn+3]='=';
        }else if(i==n-2){
            tmp[0]=a[i]>>2;
            tmp[1]=(a[i]<<4)&(0b111111);tmp[1]|=(a[i+1]>>4)&(0b111111);
            tmp[2]=(a[i+1]<<2)&(0b111111);

            b[bn+0]=ba[tmp[0]];
            b[bn+1]=ba[tmp[1]];
            b[bn+2]=ba[tmp[2]];
            b[bn+3]='=';
        }
        bn+=4;
    }
    b[bn]='\0';
}

char s[11111],s2[11111];

int main()
{
//    freopen("data.in","r",stdin);
    int T,k;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++){
        scanf("%d%s",&k,s);
        while(k){
            solve(s,s2);
            strcpy(s,s2);
            k--;
        }
        printf("Case #%d: %s\n",cas,s);
    }
    return 0;
}
