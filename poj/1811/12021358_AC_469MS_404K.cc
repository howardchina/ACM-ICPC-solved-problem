#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
typedef __int64 u64;

u64 product_mod(u64 A, u64 B, u64 C)
{
    u64 R=0;
    while(B){
        if(B&1)R=(R+A)%C;
        A<<=1;B>>=1;
        if(A>C)A=A%C;
    }
    return R;
}
u64 power_mod(u64 A, u64 B, u64 C)
{
    u64 R = 1, D = A;
    while (B )
    {
        if (B&1) R = product_mod(R, D, C);
            D = product_mod(D, D, C);
        B >>=1;
    }
    return R;
}

int pri[]={2,3,5,7,11,13,17,19,23,29};
bool isprime(__int64 n)
{
    if(n<2)
        return false;
    if(n==2)
        return true;
    if(!(n&1))
        return false;
    __int64 k = 0, i, j, m, a;
    m = n - 1;
    while(m % 2 == 0)
        m = (m >> 1), k++;
    for(i = 0; i < 10; i ++)
    {
        if(pri[i]>=n)return 1;
        a = power_mod( pri[i], m, n );
        if(a==1)
            continue;
        for(j = 0; j < k; j ++)
        {
            if(a==n-1)break;
            a = product_mod(a,a,n);
        }
        if(j < k)
            continue;
        return false ;
    }
    return true;
}

u64 gcd(u64 a,u64 b)
{
    while(b){
        a%=b;
        a^=b^=a^=b;
    }
    return a;
}
__int64 pollard_rho(__int64 C, __int64 N)
{
    __int64 I, X, Y, K, D;
    I = 1;
    X = rand() % N;
    Y = X;
    K = 2;
    do
    {
        I++;
        D = gcd(N + Y - X, N);
        if (D > 1 && D < N) return D;
        if (I == K) Y = X, K *= 2;
        X = (product_mod(X, X, N) + N - C) % N;
    }while (Y != X);
    return N;
}

__int64 rho(__int64 N)
{
    if (isprime(N)) return N;
    do
    {
        __int64 T = pollard_rho(rand() % (N - 1) + 1, N);
        if (T < N)
        {
              __int64 A, B;
              A = rho(T);
              B = rho(N / T);
              return A < B ? A : B;
        }
    }
    while (true);
}

int main()
{
    u64 t,n,r;
    scanf("%I64d",&t);
    while(t--){
        scanf("%I64d",&n);
        r=rho(n);
        if(r==n)
            puts("Prime");
        else
            printf("%I64d\n",r);
    }
    return 0;
}
