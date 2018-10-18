#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 1000010;
const int M = 10010;

int nxt[M];
int P[N], T[M];
int n,m;
void getnext(){
    int j, k;
    j = 0; k = -1; nxt[0] = -1;
    while(j<m){
        if (k==-1 || T[j]==T[k]){
            nxt[++j] = ++k;
        }
        else{
            k = nxt[k];
        }
    }
}
int kmp(){
    getnext();
    int j, k;
    j = 0; k = 0;
    while(k<m && j<n){
        if (k==-1 || T[k]==P[j]){
            ++k;++j;
        }
        else{
            k = nxt[k];
        }
    }
    if(k==m) return j-m+1;
    return -1;
}

int main()
{
//    freopen("data.in","r",stdin);
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++) scanf("%d",&P[i]);
        for(int i=0;i<m;i++) scanf("%d",&T[i]);
        printf("%d\n", kmp());
    }

    return 0;
}
