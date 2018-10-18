#include <cstdio>
typedef long long LL;
struct Mat{
    LL m[2][2];
};
inline void E(Mat &s){
    s.m[0][0]=1LL;s.m[0][1]=0LL;
    s.m[1][0]=0LL;s.m[1][1]=1LL;
}
inline void C(Mat &s){
    s.m[0][0]=s.m[0][1]=s.m[1][0]=s.m[1][1]=0LL;
}
inline Mat productMod(Mat a,Mat b,LL Mod){
    Mat s;
    C(s);

    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            if(a.m[i][j])
                for(int k=0;k<2;k++)
                    s.m[i][k] = (s.m[i][k] + a.m[i][j]*b.m[j][k])%Mod;
    return s;
}
inline Mat powMod(Mat a,int b,int Mod){
    Mat s;
    E(s);

    while(b){
        if(b&1) s=productMod(s,a,Mod);
        a=productMod(a,a,Mod);
        b>>=1;
    }
    return s;
}
/**
S<n+1> = 2a*S<n> - (a^2-b)*S<n-1>

m00 = 2a;       m01 = 1;
m10 = (b-a^2);  m11 = 0;
*/

int main()
{
//    freopen("data.in","r",stdin);
    int a,b,n,m;
    while(scanf("%d%d%d%d",&a,&b,&n,&m)!=EOF){
        Mat L,R,re;
        int ans;
        L.m[0][0] = (2LL*(a*a+b))%m;
        L.m[0][1] = (2LL*a)%m;
        L.m[1][0] = L.m[1][1] = 0LL;
        R.m[0][0] = (2LL*a)%m;
        R.m[0][1] = 1LL;
        R.m[1][0] = (((LL)b-a*a)%m+m)%m;
        R.m[1][1] = 0LL;
        R = powMod(R,n-1,m);
        re = productMod(L,R,m);
        ans = re.m[0][1];
        printf("%d\n",ans);
    }
    return 0;
}
