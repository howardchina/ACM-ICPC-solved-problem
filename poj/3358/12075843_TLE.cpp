#include <stdio.h>
#include <map>
using namespace std;

int Gcd(int a,int b)
{
    if(a<b)a^=b^=a^=b;
    while(b){
        a%=b;
        a^=b^=a^=b;
    }
    return a;
}
map<int,int>hash;
map<int,int>::iterator it;
int main()
{
//    freopen("test.in","r",stdin);
    int p,q,x,a,b,kase=0;
    bool found;
    while(~scanf("%d/%d",&p,&q)){
        x=Gcd(p,q);
        p/=x;
        q/=x;
        a=b=0;
        hash.clear();
        x=p;
        hash.insert(pair<int,int>(x,++a));
        do{
            x=x*2%q;
            it=hash.find(x);
            found=(it==hash.end());
            hash.insert(pair<int,int>(x,++a));
        }while(found);
        b=it->second;
        a-=b;
        a^=b^=a^=b;
        printf("Case #%d: %d,%d\n",++kase,a,b);
    }
    return 0;
}
