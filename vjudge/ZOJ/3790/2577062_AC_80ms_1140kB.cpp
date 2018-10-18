#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct Node{
    int c,p;
    bool operator<(const Node& rhs)const{
        if(c!=rhs.c) return c<rhs.c;
        return p<rhs.p;
    }
}s[111111];
int N,K;
int cal(int st,int ed){
    int k=0,sum=0,ret=0;
    for(int p=st,q=st;q<=ed;){
        if(k<=K){
            sum++;
            ret=max(ret,sum);
            k+=s[q+1].p-s[q].p-1;
            q++;
        }else{
            sum--;
            k-=s[p+1].p-s[p].p-1;
            p++;
        }
    }
    return ret;
}
int main()
{
//    freopen("data.in","r",stdin);
    while(scanf("%d%d",&N,&K)==2){
        int i,j;
        for(i=0;i<N;s[i].p=i++)
            scanf("%d",&s[i].c);
        sort(s,s+N);
        int ans=0;
        for(i=0;i<N;i=j+1){
            int c=s[i].c;
            j=i;
            while(j+1<N && s[j+1].c==c) j++;
            ans=max(ans,cal(i,j));
        }
        printf("%d\n",ans);
    }
    return 0;
}
