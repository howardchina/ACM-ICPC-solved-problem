#include <cstdio>
#include <cstring>
#include <iostream>
#define clr(x,k) memset((x),(k),sizeof(x))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MAXN 10000001
#define ll long long
#define MOD 1000000007
using namespace std;
char s[100004];
int k;

//求逆元
//欧几里得扩展
//对(p*b)%mod=1
//调用extend_gcd(b,mod,X,Y),X即为p的解
inline ll extend_gcd(ll a,ll b,ll &x,ll &y){
    ll ans,t;
    if(b==0){x=1,y=0;return a;}
    ans=extend_gcd(b,a%b,x,y);t=x,x=y,y=t-(a/b)*y;
    return ans;
}
ll multipow(ll base,ll n){
    ll r=1;
    while(n){
        if(n&1)
            r=(r*base)%MOD;
        base = (base*base)%MOD;
        n>>=1;
    }
    return r;
}
int main(){
    while(scanf("%s %d",s,&k)!=EOF){
        ll a1=0;
        int len=strlen(s);
        for(int i=0;i<len;i++){
            if(s[i]=='0'||s[i]=='5'){
                    a1=(a1+multipow(2,i))%MOD;
            }
        }
        ll q = multipow(2,len);
        ll q1 = (q+MOD-1)%MOD;
        ll X,Y;
        extend_gcd(q1,MOD,X,Y);
        X = (X+MOD)%MOD;//防止X为负数
        ll qn_x = (multipow(q,k)-1)*X%MOD;
        ll ans = (a1*qn_x)%MOD;
        cout<<ans<<endl;
    }
    return 0;
}