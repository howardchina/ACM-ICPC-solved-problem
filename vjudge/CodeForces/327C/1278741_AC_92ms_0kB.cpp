#include <stdio.h>
#include <string.h>
#define MOD 1000000007
#define ll long long

char a[100000];

inline ll extend_gcd(ll a,ll b,ll &x,ll &y){
    ll ans,t;
    if(b==0){x=1,y=0;return a;}
    ans=extend_gcd(b,a%b,x,y);t=x,x=y,y=t-(a/b)*y;
    return ans;
}

ll multipow( ll base, ll b ) {
    ll r = 1;
    while( b != 0 ) {
        if( b & 1 )
            r = (r * base)%MOD;
        base = (base * base)%MOD;
        b >>= 1;
    }
    return r;
}

int main()
{
    int k, i,len;
    ll ai, q, qn_1, q_1,ans, X, Y;
    while(~scanf("%s%d", a, &k)) {
        len = strlen(a);
        ai = 0;
        for(i = 0; i < len; i++) {
            if(a[i] == '0' || a[i] == '5') {
                ai = (ai+multipow(2, i))%MOD;
            }
        }
        q = multipow(2, len);
        q_1 = (q + MOD -1)%MOD;
        extend_gcd(q_1, MOD, X, Y);
        X = (X + MOD)%MOD;
        qn_1 = (multipow(q, k)-1)*X%MOD;
        ans = ai * qn_1 % MOD;
        printf("%lld\n", ans);
    }
    return 0;
}
