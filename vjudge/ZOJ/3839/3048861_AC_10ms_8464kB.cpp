#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char g[8][1024][1024];

void draw(int b,int srcX,int srcY,int rev){
    int N=1<<(b+3);
    int n=b;
    for(int i=0;i<N;i++)
        g[n][0][i]=g[n][N-1][i]='*';
    for(int i=0;i<N;i++)
        g[n][i][0]=g[n][i][N-1]='*';

    int b1=1<<b,b11=1<<(b+1),b111=b11+1;
    for(int i=0;i<b11;i++)
        g[n][b1][b1+i]=g[n][b1+b11][b1+i]='*';
    for(int i=0;i<b111;i++)
        g[n][b1+i][b1]=g[n][b1+i][b1+b11-1]='*';
    for(int i=0;i<b11;i++)
        g[n][b1][N-1-(b1+i)]=g[n][b1+b11][N-1-(b1+i)]='*';
    for(int i=0;i<b111;i++)
        g[n][b1+i][N-1-b1]=g[n][b1+i][N-1-(b1+b11-1)]='*';

    int N1=1<<(b+2);
    if(b){
        for(int i=0;i<N1;i++)
            for(int j=0;j<N1;j++)
                g[n][N-1-i][N-1-b11-j]=g[n-1][i][j];
    }else{
        for(int i=0;i<N1;i++)
            g[n][N-1][N-1-b11-i]=g[n][N-1-N1+1][N-1-b11-i]='*';
        for(int i=0;i<N1;i++)
            g[n][N-1-i][N-1-b11]=g[n][N-1-i][N-1-b11-N1+1]='*';
    }
}

int main()
{
//    freopen("data.in","r",stdin);
//    freopen("data.out","w",stdout);
    int N;
    memset(g,0,sizeof g);
    for(int i=0;i<8;i++)
        draw(i,0,0,0);
    while(scanf("%d",&N)!=EOF && N>=8){
        int n=0;
        int t=N;
        t>>=4;
        while(t){
            n++;
            t>>=1;
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++)
                if(g[n][i][j]) putchar('*');
                else putchar(' ');
            puts("");
        }
        puts("");
    }
    return 0;
}
