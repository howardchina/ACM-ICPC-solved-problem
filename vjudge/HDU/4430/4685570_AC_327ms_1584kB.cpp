#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;
LL R , K ;

LL getsum(LL r , LL k, LL n) {
    LL sum = 0, tmp = k ;
    for(int i=1; i<=r; i++) {
        sum += tmp ;
        tmp *= k ;
        if(sum > n) return sum ;
    }
    return sum ;
}

void solve( LL n ) {
    for(LL r=2; r<=40; r++) {
        LL mik = 2, mak = 1000000 ;
        while(mik < mak) {
            LL mid = mik + (mak - mik + 1) / 2;
            LL tmp = getsum(r , mid, n);
            if(tmp <= n) mik = mid ;
            else mak = mid - 1 ;
        }
        if(getsum(r , mik , n) == n) {
            if(r * mik < R * K) {
                R = r ;
                K = mik ;
            }
        }
    }
}

int main()
{
    LL n ;
    while(cin>>n) {
        K = n - 1  , R = 1 ;
        solve(n) ;
        solve(n-1) ;
        cout<<R << " " << K << endl;
    }
    return 0;
}
