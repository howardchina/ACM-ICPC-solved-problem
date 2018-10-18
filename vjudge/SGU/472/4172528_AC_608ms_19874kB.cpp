/** Micro Mezz Macro Flation -- Overheated Economy ., Last Update: Nov. 7th 2014 **/ //{

/** Header .. **/ //{
#pragma comment(linker, "/STACK:36777216")
//#pragma GCC optimize ("O2")
#define LOCAL
//#include "testlib.h"
#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <cstring>
#include <climits>
#include <cassert>
#include <complex>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <list>
#include <set>
#include <map>

//#include <tr1/unordered_set>
//#include <tr1/unordered_map>
//#include <array>

using namespace std;

#define REP(i, n) for (int i=0;i<n;++i)
#define FOR(i, a, b) for (int i=a;i<b;++i)
#define DWN(i, b, a) for (int i=b-1;i>=a;--i)
#define REP_1(i, n) for (int i=1;i<=n;++i)
#define FOR_1(i, a, b) for (int i=a;i<=b;++i)
#define DWN_1(i, b, a) for (int i=b;i>=a;--i)
#define REP_C(i, n) for (int n____=n,i=0;i<n____;++i)
#define FOR_C(i, a, b) for (int b____=b,i=a;i<b____;++i)
#define DWN_C(i, b, a) for (int a____=a,i=b-1;i>=a____;--i)
#define REP_N(i, n) for (i=0;i<n;++i)
#define FOR_N(i, a, b) for (i=a;i<b;++i)
#define DWN_N(i, b, a) for (i=b-1;i>=a;--i)
#define REP_1_C(i, n) for (int n____=n,i=1;i<=n____;++i)
#define FOR_1_C(i, a, b) for (int b____=b,i=a;i<=b____;++i)
#define DWN_1_C(i, b, a) for (int a____=a,i=b;i>=a____;--i)
#define REP_1_N(i, n) for (i=1;i<=n;++i)
#define FOR_1_N(i, a, b) for (i=a;i<=b;++i)
#define DWN_1_N(i, b, a) for (i=b;i>=a;--i)
#define REP_C_N(i, n) for (int n____=(i=0,n);i<n____;++i)
#define FOR_C_N(i, a, b) for (int b____=(i=0,b);i<b____;++i)
#define DWN_C_N(i, b, a) for (int a____=(i=b-1,a);i>=a____;--i)
#define REP_1_C_N(i, n) for (int n____=(i=1,n);i<=n____;++i)
#define FOR_1_C_N(i, a, b) for (int b____=(i=a,b);i<=b____;++i)
#define DWN_1_C_N(i, b, a) for (int a____=(i=b,a);i>=a____;--i)

#define ECH(it, A) for (__typeof((A).begin()) it=(A).begin(); it != (A).end(); ++it)
#define rECH(it, A) for (__typeof((A).rbegin()) it=(A).rbegin(); it != (A).rend(); ++it)
#define REP_S(i, str) for (char*i=str;*i;++i)
#define REP_L(i, hd, suc) for (int i=hd;i;i=suc[i])
#define REP_G(i, u) REP_L(i,hd[u],suc)
#define REP_SS(x, s) for (int x=s;x;x=(x-1)&s)
#define DO(n) for ( int ____n = n; ____n-->0; )
#define REP_2(i, j, n, m) REP(i, n) REP(j, m)
#define REP_2_1(i, j, n, m) REP_1(i, n) REP_1(j, m)
#define REP_3(i, j, k, n, m, l) REP(i, n) REP(j, m) REP(k, l)
#define REP_3_1(i, j, k, n, m, l) REP_1(i, n) REP_1(j, m) REP_1(k, l)
#define REP_4(i, j, k, ii, n, m, l, nn) REP(i, n) REP(j, m) REP(k, l) REP(ii, nn)
#define REP_4_1(i, j, k, ii, n, m, l, nn) REP_1(i, n) REP_1(j, m) REP_1(k, l) REP_1(ii, nn)

#define ALL(A) A.begin(), A.end()
#define LLA(A) A.rbegin(), A.rend()
#define CPY(A, B) memcpy(A, B, sizeof(A))
#define INS(A, P, B) A.insert(A.begin() + P, B)
#define ERS(A, P) A.erase(A.begin() + P)
#define LBD(A, x) (lower_bound(ALL(A), x) - A.begin())
#define UBD(A, x) (upper_bound(ALL(A), x) - A.begin())
#define CTN(T, x) (T.find(x) != T.end())
#define SZ(A) int((A).size())
#define PB push_back
#define MP(A, B) make_pair(A, B)
#define PTT pair<T, T>
#define Ts *this
#define rTs return Ts
#define fi first
#define se second
#define re real()
#define im imag()

#define Rush for(int ____T=RD(); ____T--;)
#define Display(A, n, m) {                      \
REP(i, n){		                            \
REP(j, m-1) cout << A[i][j] << " ";     \
cout << A[i][m-1] << endl;		        \
}						                    \
}
#define Display_1(A, n, m) {                    \
REP_1(i, n){		                        \
REP_1(j, m-1) cout << A[i][j] << " ";   \
cout << A[i][m] << endl;		        \
}						                    \
}

typedef long long LL;
//typedef long double DB;
typedef double DB;
typedef unsigned uint;
typedef unsigned long long uLL;

typedef vector<int> VI;
typedef vector<char> VC;
typedef vector<string> VS;
typedef vector<LL> VL;
typedef vector<DB> VF;
typedef set<int> SI;
typedef set<string> SS;
typedef map<int, int> MII;
typedef map<string, int> MSI;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef vector<VII> VVII;

template<class T> inline T& RD(T &);
template<class T> inline void OT(const T &);
//inline int RD(){int x; return RD(x);}
inline LL RD(){LL x; return RD(x);}
inline DB& RF(DB &);
inline DB RF(){DB x; return RF(x);}
inline char* RS(char *s);
inline char& RC(char &c);
inline char RC();
inline char& RC(char &c){scanf(" %c", &c); return c;}
inline char RC(){char c; return RC(c);}
//inline char& RC(char &c){c = getchar(); return c;}
//inline char RC(){return getchar();}

template<class T> inline T& RDD(T &);
inline LL RDD(){LL x; return RDD(x);}

template<class T0, class T1> inline T0& RD(T0 &x0, T1 &x1){RD(x0), RD(x1); return x0;}
template<class T0, class T1, class T2> inline T0& RD(T0 &x0, T1 &x1, T2 &x2){RD(x0), RD(x1), RD(x2); return x0;}
template<class T0, class T1, class T2, class T3> inline T0& RD(T0 &x0, T1 &x1, T2 &x2, T3 &x3){RD(x0), RD(x1), RD(x2), RD(x3); return x0;}
template<class T0, class T1, class T2, class T3, class T4> inline T0& RD(T0 &x0, T1 &x1, T2 &x2, T3 &x3, T4 &x4){RD(x0), RD(x1), RD(x2), RD(x3), RD(x4); return x0;}
template<class T0, class T1, class T2, class T3, class T4, class T5> inline T0& RD(T0 &x0, T1 &x1, T2 &x2, T3 &x3, T4 &x4, T5 &x5){RD(x0), RD(x1), RD(x2), RD(x3), RD(x4), RD(x5); return x0;}
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6> inline T0& RD(T0 &x0, T1 &x1, T2 &x2, T3 &x3, T4 &x4, T5 &x5, T6 &x6){RD(x0), RD(x1), RD(x2), RD(x3), RD(x4), RD(x5), RD(x6); return x0;}
template<class T0, class T1> inline void OT(const T0 &x0, const T1 &x1){OT(x0), OT(x1);}
template<class T0, class T1, class T2> inline void OT(const T0 &x0, const T1 &x1, const T2 &x2){OT(x0), OT(x1), OT(x2);}
template<class T0, class T1, class T2, class T3> inline void OT(const T0 &x0, const T1 &x1, const T2 &x2, const T3 &x3){OT(x0), OT(x1), OT(x2), OT(x3);}
template<class T0, class T1, class T2, class T3, class T4> inline void OT(const T0 &x0, const T1 &x1, const T2 &x2, const T3 &x3, const T4 &x4){OT(x0), OT(x1), OT(x2), OT(x3), OT(x4);}
template<class T0, class T1, class T2, class T3, class T4, class T5> inline void OT(const T0 &x0, const T1 &x1, const T2 &x2, const T3 &x3, const T4 &x4, const T5 &x5){OT(x0), OT(x1), OT(x2), OT(x3), OT(x4), OT(x5);}
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6> inline void OT(const T0 &x0, const T1 &x1, const T2 &x2, const T3 &x3, const T4 &x4, const T5 &x5, const T6 &x6){OT(x0), OT(x1), OT(x2), OT(x3), OT(x4), OT(x5), OT(x6);}
inline char& RC(char &a, char &b){RC(a), RC(b); return a;}
inline char& RC(char &a, char &b, char &c){RC(a), RC(b), RC(c); return a;}
inline char& RC(char &a, char &b, char &c, char &d){RC(a), RC(b), RC(c), RC(d); return a;}
inline char& RC(char &a, char &b, char &c, char &d, char &e){RC(a), RC(b), RC(c), RC(d), RC(e); return a;}
inline char& RC(char &a, char &b, char &c, char &d, char &e, char &f){RC(a), RC(b), RC(c), RC(d), RC(e), RC(f); return a;}
inline char& RC(char &a, char &b, char &c, char &d, char &e, char &f, char &g){RC(a), RC(b), RC(c), RC(d), RC(e), RC(f), RC(g); return a;}
inline DB& RF(DB &a, DB &b){RF(a), RF(b); return a;}
inline DB& RF(DB &a, DB &b, DB &c){RF(a), RF(b), RF(c); return a;}
inline DB& RF(DB &a, DB &b, DB &c, DB &d){RF(a), RF(b), RF(c), RF(d); return a;}
inline DB& RF(DB &a, DB &b, DB &c, DB &d, DB &e){RF(a), RF(b), RF(c), RF(d), RF(e); return a;}
inline DB& RF(DB &a, DB &b, DB &c, DB &d, DB &e, DB &f){RF(a), RF(b), RF(c), RF(d), RF(e), RF(f); return a;}
inline DB& RF(DB &a, DB &b, DB &c, DB &d, DB &e, DB &f, DB &g){RF(a), RF(b), RF(c), RF(d), RF(e), RF(f), RF(g); return a;}
inline void RS(char *s1, char *s2){RS(s1), RS(s2);}
inline void RS(char *s1, char *s2, char *s3){RS(s1), RS(s2), RS(s3);}
template<class T0,class T1>inline T0& RDD(T0&a, T1&b){RDD(a),RDD(b); return a;}
template<class T0,class T1,class T2>inline T1& RDD(T0&a, T1&b, T2&c){RDD(a),RDD(b),RDD(c); return a;}

template<class T> inline void RST(T &A){memset(A, 0, sizeof(A));}
template<class T> inline void FLC(T &A, int x){memset(A, x, sizeof(A));}
template<class T> inline void CLR(T &A){A.clear();}

template<class T0, class T1> inline void RST(T0 &A0, T1 &A1){RST(A0), RST(A1);}
template<class T0, class T1, class T2> inline void RST(T0 &A0, T1 &A1, T2 &A2){RST(A0), RST(A1), RST(A2);}
template<class T0, class T1, class T2, class T3> inline void RST(T0 &A0, T1 &A1, T2 &A2, T3 &A3){RST(A0), RST(A1), RST(A2), RST(A3);}
template<class T0, class T1, class T2, class T3, class T4> inline void RST(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4){RST(A0), RST(A1), RST(A2), RST(A3), RST(A4);}
template<class T0, class T1, class T2, class T3, class T4, class T5> inline void RST(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5){RST(A0), RST(A1), RST(A2), RST(A3), RST(A4), RST(A5);}
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6> inline void RST(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5, T6 &A6){RST(A0), RST(A1), RST(A2), RST(A3), RST(A4), RST(A5), RST(A6);}
template<class T0, class T1> inline void FLC(T0 &A0, T1 &A1, int x){FLC(A0, x), FLC(A1, x);}
template<class T0, class T1, class T2> inline void FLC(T0 &A0, T1 &A1, T2 &A2, int x){FLC(A0, x), FLC(A1, x), FLC(A2, x);}
template<class T0, class T1, class T2, class T3> inline void FLC(T0 &A0, T1 &A1, T2 &A2, T3 &A3, int x){FLC(A0, x), FLC(A1, x), FLC(A2, x), FLC(A3, x);}
template<class T0, class T1, class T2, class T3, class T4> inline void FLC(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, int x){FLC(A0, x), FLC(A1, x), FLC(A2, x), FLC(A3, x), FLC(A4, x);}
template<class T0, class T1, class T2, class T3, class T4, class T5> inline void FLC(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5, int x){FLC(A0, x), FLC(A1, x), FLC(A2, x), FLC(A3, x), FLC(A4, x), FLC(A5, x);}
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6> inline void FLC(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5, T6 &A6, int x){FLC(A0, x), FLC(A1, x), FLC(A2, x), FLC(A3, x), FLC(A4, x), FLC(A5, x), FLC(A6, x);}
template<class T> inline void CLR(priority_queue<T, vector<T>, less<T> > &Q){while (!Q.empty()) Q.pop();}
template<class T> inline void CLR(priority_queue<T, vector<T>, greater<T> > &Q){while (!Q.empty()) Q.pop();}
template<class T> inline void CLR(stack<T> &S){while (!S.empty()) S.pop();}
template<class T> inline void CLR(queue<T> &Q){while (!Q.empty()) Q.pop();}

template<class T0, class T1> inline void CLR(T0 &A0, T1 &A1){CLR(A0), CLR(A1);}
template<class T0, class T1, class T2> inline void CLR(T0 &A0, T1 &A1, T2 &A2){CLR(A0), CLR(A1), CLR(A2);}
template<class T0, class T1, class T2, class T3> inline void CLR(T0 &A0, T1 &A1, T2 &A2, T3 &A3){CLR(A0), CLR(A1), CLR(A2), CLR(A3);}
template<class T0, class T1, class T2, class T3, class T4> inline void CLR(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4){CLR(A0), CLR(A1), CLR(A2), CLR(A3), CLR(A4);}
template<class T0, class T1, class T2, class T3, class T4, class T5> inline void CLR(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5){CLR(A0), CLR(A1), CLR(A2), CLR(A3), CLR(A4), CLR(A5);}
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6> inline void CLR(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5, T6 &A6){CLR(A0), CLR(A1), CLR(A2), CLR(A3), CLR(A4), CLR(A5), CLR(A6);}
template<class T> inline void CLR(T &A, int n){REP(i, n) CLR(A[i]);}

template<class T> inline bool EPT(T &a){return a.empty();}
template<class T> inline T& SRT(T &A){sort(ALL(A)); return A;}
template<class T, class C> inline T& SRT(T &A, C B){sort(ALL(A), B); return A;}
template<class T> inline T& RVS(T &A){reverse(ALL(A)); return A;}
template<class T> inline T& UNQQ(T &A){A.resize(unique(ALL(A))-A.begin());return A;}
template<class T> inline T& UNQ(T &A){SRT(A);return UNQQ(A);}


//}

/** Constant List .. **/ //{

const int MOD = int(1e9) + 7;
const int INF = 0x3f3f3f3f;
const LL INFF = 0x3f3f3f3f3f3f3f3fLL;
const DB EPS = 1e-9;
const DB OO = 1e20;
const DB PI = acos(-1.0); //M_PI;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

//}

/** Add On .. **/ //{
// <<= '0. Nichi Joo ., //{

template<class T> inline bool checkMin(T &a,const T b){return b < a ? a = b, 1 : 0;}
template<class T> inline bool checkMax(T &a,const T b){return a < b ? a = b, 1 : 0;}
template <class T, class C> inline bool checkUpd(T& a, const T b, C c){return c(b,a) ? a = b, 1 : 0;}
template<class T> inline T min(T a, T b, T c){return min(min(a, b), c);}
template<class T> inline T max(T a, T b, T c){return max(max(a, b), c);}
template<class T> inline T min(T a, T b, T c, T d){return min(min(a, b), min(c, d));}
template<class T> inline T max(T a, T b, T c, T d){return max(max(a, b), max(c, d));}
template<class T> inline T min(T a, T b, T c, T d, T e){return min(min(min(a,b),min(c,d)),e);}
template<class T> inline T max(T a, T b, T c, T d, T e){return max(max(max(a,b),max(c,d)),e);}
template<class T> inline T sqr(T a){return a*a;}
template<class T> inline T cub(T a){return a*a*a;}
template<class T> inline T ceil(T x, T y){return (x - 1) / y + 1;}
template<class T> T abs(T x){return x>0?x:-x;}
inline int sgn(DB x){return x < -EPS ? -1 : x > EPS;}
inline int sgn(DB x, DB y){return sgn(x - y);}

inline DB cos(DB a, DB b, DB c){return (sqr(a)+sqr(b)-sqr(c))/(2*a*b);}
inline DB cot(DB x){return 1./tan(x);};
inline DB sec(DB x){return 1./cos(x);};
inline DB csc(DB x){return 1./sin(x);};

//}

//}



/** I/O Accelerator Interface .. **/ //{
#define g (c=getchar())
#define d isdigit(g)
#define p x=x*10+c-'0'
#define n x=x*10+'0'-c
#define pp l/=10,p
#define nn l/=10,n
template<class T> inline T& RD(T &x){
    char c;while(!d);x=c-'0';while(d)p;
    return x;
}
template<class T> inline T& RDD(T &x){
    char c;while(g,c!='-'&&!isdigit(c));
    if (c=='-'){x='0'-g;while(d)n;}
    else{x=c-'0';while(d)p;}
    return x;
}
inline DB& RF(DB &x){
    //scanf("%lf", &x);
    char c;while(g,c!='-'&&c!='.'&&!isdigit(c));
    if(c=='-')if(g=='.'){x=0;DB l=1;while(d)nn;x*=l;}
    else{x='0'-c;while(d)n;if(c=='.'){DB l=1;while(d)nn;x*=l;}}
    else if(c=='.'){x=0;DB l=1;while(d)pp;x*=l;}
    else{x=c-'0';while(d)p;if(c=='.'){DB l=1;while(d)pp;x*=l;}}
    return x;
}
#undef nn
#undef pp
#undef n
#undef p
#undef d
#undef g
inline char* RS(char *s){
    //gets(s);
    scanf("%s", s);
    return s;
}

LL last_ans; int Case; template<class T> inline void OT(const T &x){
    printf("Case #%d: ", ++Case);
    //printf("%lld\n", x);
    //printf("%.9f\n", x);
    printf("%d\n", x);
    //cout << x << endl;
    //last_ans = x;
}


//}/* .................................................................................................................................. */

const int N = int(1e2) + 9;
const char O[5] = "UDLR";

char Map[N][N];

PII D[N][N][4]; int d[N][N][4][4];

struct state{
    int x, y, i;
    state(int x=0, int y=0, int i=0):x(x),y(y),i(i){};
    PII& d()const{return D[x][y][i];}
    bool operator <(const state& r)const{ //!
        return d() > r.d();
    }
};

state pre[N][N][4];
priority_queue<state> Q; bool Done[N][N][4];
int n, m, sx, sy, bx, by, tx, ty;

string path;

namespace BFS{
    int D[N][N]; int vis[N][N], vis_bj;
    PII Q[N*N]; int pre[N*N]; int cz, op;
    
    void bfs(int sx, int sy, int lx = 0, int rx = n+1, int ly = 0, int ry = m+1){
        
        ++vis_bj; if (Map[sx][sy] == '#') return;
        
        cz = op = 0;
        D[sx][sy] = 0; Q[op++] = MP(sx, sy);
        vis[sx][sy] = vis_bj;
        
        while (cz < op){
            int ux = Q[cz].fi, uy = Q[cz].se;
            
            REP(i, 4){
                int vx = ux + dx[i], vy = uy + dy[i];
                
                if (vx < lx || rx < vx) continue;
                if (vy < ly || ry < vy) continue;
                
                if (Map[vx][vy] == '#' || vis[vx][vy] == vis_bj) continue;
                
                vis[vx][vy] = vis_bj;
                D[vx][vy] = D[ux][uy] + 1; pre[op] = cz;
                Q[op++] = MP(vx, vy);
            }
            ++cz;
        }
    }
    
    void gao(int sx, int sy, int tx, int ty){
        
        int x = op;
        DWN(i, op, 0) if (Q[i].fi == tx && Q[i].se == ty){
            x = i;
            break;
        }
        
        while (Q[x].fi != sx || Q[x].se != sy){
            
            REP(i, 4){
                if (Q[pre[x]].fi + dx[i] == Q[x].fi && Q[pre[x]].se + dy[i] == Q[x].se){
                    //cout << "###" << endl;
                    path += tolower(O[i]);
                    break;
                }
            }
            x = pre[x];
        }
    }
}

int id[N][N];

namespace get_d{
    
    const int N = 509, L = 16;
    
    int floyd[N][N];
    PII posPool[L][N];
    int nidPool[L][N];
    int dPool[L][N][N];
    
    void get_sub(int lx, int rx, int ly, int ry, int n1, int n2, int& n3, int (*d)[N], int *nid, PII* pos){
        
        REP(i, n2) id[pos[i].fi][pos[i].se] = i;
        
        n3 = 0;
        
        FOR_1(y, ly, ry){
            nid[n3++] = id[lx][y];
            nid[n3++] = id[rx][y];
        }
        
        FOR(x, lx+1, rx){
            nid[n3++] = id[x][ly];
            nid[n3++] = id[x][ry];
        }
        
        REP_2(i, j, n2, n2) floyd[i][j] = (i < n1 && j < n1) ? d[i][j] : INF;
    }
    
    void Floyd(int n2, int n3, int (*nd)[N], int *nid){
        REP_3(k, i, j, n2, n2, i){
            if (checkMin(floyd[i][j], floyd[i][k] + floyd[k][j])){
                floyd[j][i] = floyd[i][j];
            }
        }
        REP_2(i, j, n3, n3) if (i != j) nd[i][j] = floyd[nid[i]][nid[j]];
    }
    
    void gao(int lv = 0, int lx = 0, int rx = n+1, int ly = 0, int ry = m+1){
        
        int (*d)[N]; int (*nd)[N];
        PII *pos;  int *nid;
        
        d = dPool[lv], nd = dPool[lv+1];
        pos = posPool[lv], nid = nidPool[lv];
        int n1 = 0, n2, n3;
        
        FOR_1(y, ly, ry){
            pos[n1++] = MP(lx, y);
            pos[n1++] = MP(rx, y);
        }
        
        FOR(x, lx+1, rx){
            pos[n1++] = MP(x, ly);
            pos[n1++] = MP(x, ry);
        }
        
        if (lx + 2 == rx && ly + 2 == ry){
            int x = lx + 1, y = ly + 1;
            REP(i, n1) id[pos[i].fi][pos[i].se] = i;
            
            REP_2(i, j, 4, 4) if (i != j){
                ::d[x][y][i][j] = d[id[x+dx[i]][y+dy[i]]][id[x+dx[j]][y+dy[j]]];
            }
            
            return;
        }
        
        if (rx - lx > ry - ly){
            int ml = (lx+rx) >> 1, mr = ml + 1, mx;
            mx = mr; n2 = n1; FOR(y, ly+1, ry) pos[n2++] = MP(mx, y);
            get_sub(lx,mx,ly,ry,n1,n2,n3,d,nid,pos);
            
            REP(i, n2) if (pos[i].fi >= mx){
                
                if (Map[pos[i].fi][pos[i].se] == '#') continue;
                BFS::bfs(pos[i].fi, pos[i].se, mx, rx, ly, ry);
                
                REP(j, n2) if (i != j){
                    if (BFS::vis[pos[j].fi][pos[j].se] != BFS::vis_bj) continue;
                    checkMin(floyd[i][j], BFS::D[pos[j].fi][pos[j].se]);
                    floyd[j][i] = floyd[i][j];
                }
            }
            
            Floyd(n2,n3,nd,nid); gao(lv+1,lx,mx,ly,ry);
            
            mx = ml; n2 = n1; FOR(y, ly+1, ry) pos[n2++] = MP(mx, y);
            get_sub(mx,rx,ly,ry,n1,n2,n3,d,nid,pos);
            
            REP(i, n2) if (pos[i].fi <= mx){
                if (Map[pos[i].fi][pos[i].se] == '#') continue;
                BFS::bfs(pos[i].fi, pos[i].se, lx, mx, ly, ry);
                REP(j, n2) if (i != j){
                    if (BFS::vis[pos[j].fi][pos[j].se] != BFS::vis_bj) continue;
                    checkMin(floyd[i][j], BFS::D[pos[j].fi][pos[j].se]);
                    floyd[j][i] = floyd[i][j];
                }
            }
            Floyd(n2,n3,nd,nid); gao(lv+1,mx,rx,ly,ry);
        }
        else{
            int ml = (ly+ry) >> 1, mr = ml + 1, my;
            my = mr; n2 = n1; FOR(x, lx+1, rx) pos[n2++] = MP(x, my);
            REP(i, n2) id[pos[i].fi][pos[i].se] = i;
            get_sub(lx,rx,ly,my,n1,n2,n3,d,nid,pos);
            
            REP(i, n2) if (pos[i].se >= my){
                if (Map[pos[i].fi][pos[i].se] == '#') continue;
                BFS::bfs(pos[i].fi, pos[i].se, lx, rx, my, ry);
                REP(j, n2) if (i != j){
                    if (BFS::vis[pos[j].fi][pos[j].se] != BFS::vis_bj) continue;
                    checkMin(floyd[i][j], BFS::D[pos[j].fi][pos[j].se]);
                    floyd[j][i] = floyd[i][j];
                }
            }
            Floyd(n2,n3,nd,nid); gao(lv+1,lx,rx,ly,my);
            
            my = ml; n2 = n1; FOR(x, lx+1, rx) pos[n2++] = MP(x, my);
            get_sub(lx,rx,my,ry,n1,n2,n3,d,nid,pos);
            
            REP(i, n2) if (pos[i].se <= my){
                if (Map[pos[i].fi][pos[i].se] == '#') continue;
                BFS::bfs(pos[i].fi, pos[i].se, lx, rx, ly, my);
                REP(j, n2) if (i != j){
                    if (BFS::vis[pos[j].fi][pos[j].se] != BFS::vis_bj) continue;
                    checkMin(floyd[i][j], BFS::D[pos[j].fi][pos[j].se]);
                    floyd[j][i] = floyd[i][j];
                }
            }
            Floyd(n2,n3,nd,nid); gao(lv+1,lx,rx,my,ry);
        }
    }
    
    void init(){
        //FLC(::d, 0x3f), FLC(dPool, 0x3f);
        gao();
        /*        REP(i, 4) REP(j, 4){
         cout << i << " " << j<< " "<< d[3][2][i][j] << endl;
         }*/
    }
}


void gao(state v){
    
    //cout << v.x << " " << v.y << " " << v.i << endl;
    
    if (D[v.x][v.y][v.i].fi == 0){
        int tx = v.x + dx[v.i], ty = v.y + dy[v.i];
        Map[bx][by] = '#';
        BFS::bfs(sx, sy);
        BFS::gao(sx, sy, tx, ty);
        Map[bx][by] = '.';
    }
    else{
        
        state u = pre[v.x][v.y][v.i];
        
        if (v.i == u.i){
            path += O[u.i^1];
        }
        else{
            int sx = u.x + dx[u.i], sy = u.y + dy[u.i];
            int tx = v.x + dx[v.i], ty = v.y + dy[v.i];
            Map[u.x][u.y] = '#';
            BFS::bfs(sx, sy);
            BFS::gao(sx, sy, tx, ty);
            Map[u.x][u.y] = '.';
        }
        
        gao(u);
    }
}

void relax(const state u, const state v, PII w){
    PII t = MP(u.d().fi+w.fi, u.d().se+w.se);
    if (v.d() > t){
        D[v.x][v.y][v.i] = t;
        pre[v.x][v.y][v.i] = u;
        Q.push(v);
    }
}


int main(){
    
#ifndef ONLINE_JUDGE
    freopen("/users/xiaodao/desktop/Exercise/in.txt", "r", stdin);
    //freopen("/users/xiaodao/desktop/Exercise/out.txt", "w", stdout);
#endif
    
    for (gets(Map[++n]+1);Map[n][1];gets(Map[++n]+1));
    --n; m = int(strlen(Map[1]+1));
    
    REP(i, n+2) Map[i][0] = Map[i][m+1] = '#';
    REP(i, m+2) Map[0][i] = Map[n+1][i] = '#';
    
    REP_2_1(i, j, n, m) if (Map[i][j] == '@'){
        sx = i, sy = j;
        Map[i][j] = ' ';
    }
    else if (Map[i][j] == '$'){
        bx = i, by = j;
        Map[i][j] = '#';
    }
    else if (Map[i][j] == '.'){
        tx = i, ty = j;
        Map[i][j] = ' ';
    }
    
    FLC(D, 0x3f); BFS::bfs(sx, sy);
    Map[bx][by] = ' ';
    REP(i, 4){
        int xx = bx + dx[i], yy = by + dy[i];
        if (BFS::vis[xx][yy] == BFS::vis_bj && BFS::D[xx][yy] != INF){
            D[bx][by][i] = MP(0, BFS::D[xx][yy]);
            Q.push(state(bx, by, i));
        }
    }
    
    
    get_d::init();
    
    
    //    cout <<"!?" << endl;
    
    /*
     REP_2_1(x, y, n, m) if (Map[x][y] == '.'){
     REP(i, 4){
     
     int ux = x + dx[i], uy = y + dy[i];
     if (Map[ux][uy] == '#') continue;
     
     Map[x][y] = '#';
     BFS::bfs(x+dx[i], y+dy[i]);
     REP(j, 4) if (i != j){
     
     int vx = x + dx[j], vy = y + dy[j];
     //  if (Map[x][y] == '#') continue;
     
     if (BFS::vis[vx][vy] != BFS::vis_bj) BFS::D[vx][vy] = INF;
     
     if (d[x][y][i][j] != BFS::D[vx][vy]){
     
     cout << x << " " << y << " " << i << " " << j << endl;
     cout << x+dx[i] << " " << y+dy[i] << endl;
     cout << x+dx[j] <<  " " << y+dy[j] << endl;
     
     cout << d[x][y][i][j] << endl;
     cout << BFS::D[x+dx[j]][y+dy[j]] << endl;
     cout << "!!!!" << endl;
     return 0;
     }
     }
     Map[x][y] = '.';
     }
     }*/
    
    
    while (!Q.empty()){
        
        state u = Q.top(); Q.pop();
        if (Done[u.x][u.y][u.i]) continue;
        Done[u.x][u.y][u.i] = true;
        
        int sx = u.x + dx[u.i], sy = u.y + dy[u.i];
        
        //    cout << sx << " " << sy << " " << u.d().fi << " " << u.d().se << endl;
        
        REP(i, 4){
            if (i != u.i){
                int tx = u.x + dx[i], ty = u.y + dy[i];
                if (Map[tx][ty] == '#' || d[u.x][u.y][u.i][i] == INF) continue;
                state v(u.x,u.y,i);
                relax(u, v, MP(0, d[u.x][u.y][u.i][i]));
            }
            else{
                state v(u.x-dx[i], u.y-dy[i], i);
                if (Map[v.x][v.y] == '#') continue;
                relax(u, v, MP(1,1));
            }
        }
    }
    
    PII z = MP(INF, INF); REP(i, 4) checkMin(z, D[tx][ty][i]);
    
    // cout << " " << tx << " " <<ty << endl;
    // cout << " " << z.fi << " " << z.se << endl;
    
    if (z.fi == INF){
        puts("Impossible.");
    }
    else{
        
        //cout << z.fi << " " << z.se << endl;
        
        REP(i, 4) if (z == D[tx][ty][i]){
            gao(state(tx, ty, i));
            break;
        }
        
        RVS(path);
        cout << path << endl;
    }
}