#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char s[1111];
int stk[1111],top;
int main()
{
//    freopen("dat.in","r",stdin);
    int T,n;
    scanf("%d",&T);
    while(T--){
        scanf("%s",s);
        n = strlen(s);
        int opcnt=0,digcnt=0;
        top=0;
        for(int i=0;i<n;i++){
            if('*' == s[i]) opcnt++;
            else{
                digcnt++;
                stk[top++]=i;
            }
        }
        int cnt=0,ans=0;
        if(opcnt != 0){
            if(opcnt>=digcnt)
                cnt = ans = opcnt-digcnt+1;
            for(int i=0;i<n;i++){
                if(s[i]=='*') cnt--;
                else cnt++;
                if(cnt==0){
                    swap(s[i],s[stk[--top]]);
                    cnt=2;
                    ans++;
                }
            }
            if(s[n-1]!='*') ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
