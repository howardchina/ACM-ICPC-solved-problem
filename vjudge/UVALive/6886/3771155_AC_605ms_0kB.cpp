#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAXN = 1<<19 ;
const double PI = acos(-1.0) ;

struct Complex{
    double x , y ;
    Complex(double x=0 , double y=0):x(x),y(y){}
    Complex operator - (const Complex&b) const {
        return Complex(x-b.x, y-b.y) ;
    }
    Complex operator + (const Complex&b) const {
        return Complex(x+b.x ,y+b.y) ;
    }
    Complex operator * (const Complex&b) const {
        return Complex(x*b.x-y*b.y , x*b.y+y*b.x) ;
    }
};
void change(Complex y[] , int len) {
    int i , j , k;
    for(i=1,j=len/2; i<len-1 ; i++) {
        if(i < j) swap(y[i] , y[j]) ;
        k = len / 2;
        while(j >= k) {
            j -= k ;
            k /= 2;
        }
        if(j < k) j += k ;
    }
}
void fft(Complex y[] , int len , int on) {
    change(y , len) ;
    for(int h=2; h<=len; h<<=1) {
        Complex wn(cos(-on*2.0*PI/h) , sin(-on*2.0*PI/h)) ;
        for(int j=0; j<len; j+=h) {
            Complex w(1, 0) ;
            for(int k=j; k<j+h/2; k++) {
                Complex u = y[k] ;
                Complex t = w*y[k+h/2];
                y[k] = u+t;
                y[k+h/2] = u-t;
                w = w*wn ;
            }
        }
    }
    if(on == -1) for(int i=0; i<len; i++) y[i].x /= len ;
}

int a[MAXN],b[MAXN],cnt[MAXN],N,M;
Complex x1[MAXN];

int main()
{
    while(scanf("%d", &N) == 1) {
        memset(cnt ,0 , sizeof(cnt)) ;
        int la = 0 ;
        for(int i=0; i<N; i++) {
            scanf("%d", &a[i]) ;
            cnt[a[i]] ++ ;
            la = max(la , a[i]+1) ;
        }
        cnt[0] ++ ;
        scanf("%d", &M) ;
        for(int i=0; i<M; i++) scanf("%d", &b[i]) ;

        int len = 1 ;
        while(len<la*2) len *= 2 ;
        for(int i=0; i<la; i++) x1[i] = Complex(cnt[i] , 0);
        for(int i=la; i<len; i++) x1[i]= Complex(0 , 0) ;
        fft(x1 , len , 1) ;
        for(int i=0; i<len ;i++) x1[i] = x1[i] * x1[i] ;
        fft(x1 , len , -1) ;
        for(int i=0; i<len ; i++) cnt[i] = (int)(x1[i].x + 0.5) ;

        int ans = 0;
        for(int i=0; i<M; i++){
            if(cnt[b[i]] > 0) ans ++  ;
        }
        printf("%d\n" ,ans) ;
    }
    return 0;
}
