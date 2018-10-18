#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char s[1100];
int main()
{
//    freopen("data.in","r",stdin);
    int k,n,len,pos,g,cas=1;
    while(scanf("%d",&k)==1){
        gets(s);
        gets(s+1);
        n=strlen(s+1);
        len=1,pos=1;
        for(int l,r,i=1;i<=n;i++){
            l=i-1,r=i+1;
            g=k;
            while(0<l && r<=n){
                while((!('a'<=s[l]&&s[l]<='z'))&&(!('A'<=s[l]&&s[l]<='Z'))&&l>0)
                    l--;
                if(l==0) break;
                while((!('a'<=s[r]&&s[r]<='z'))&&(!('A'<=s[r]&&s[r]<='Z'))&&r<=n)
                    r++;
                if(r==n+1) break;
                char ll=s[l]<='Z'?(s[l]-'A'+'a'):s[l];
                char rr=s[r]<='Z'?(s[r]-'A'+'a'):s[r];
                if(ll!=rr){
                    if(g>0)
                        g--;
                    else
                        break;
                }
                if(len<(r-l+1)){
                    len=r-l+1,pos=l;
                }else if(len==(r-l+1)&&pos>l){
                    len=r-l+1,pos=l;
                }
                l--,r++;
            }
            l=i,r=i+1;
            g=k;
            while(0<l && r<=n){
                while((!('a'<=s[l]&&s[l]<='z'))&&(!('A'<=s[l]&&s[l]<='Z'))&&l>0)
                    l--;
                if(l==0) break;
                while((!('a'<=s[r]&&s[r]<='z'))&&(!('A'<=s[r]&&s[r]<='Z'))&&r<=n)
                    r++;
                if(r==n+1) break;
                char ll=(s[l]<='Z')?(s[l]+'a'-1):s[l];
                char rr=(s[r]<='Z')?(s[r]+'a'-1):s[r];
                if(ll!=rr){
                    if(g>0)
                        g--;
                    else
                        break;
                }
                if(len<(r-l+1)){
                    len=r-l+1,pos=l;
                }else if(len==(r-l+1)&&pos>l){
                    len=r-l+1,pos=l;
                }
                l--,r++;
            }
        }
        printf("Case %d: %d %d\n",cas++,len,pos);
    }
    return 0;
}
