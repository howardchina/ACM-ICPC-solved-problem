#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int MaxS = 300010;
const int MaxP = 10010;
const int MaxW = 16;
const int AbsY = 11000;
const int MaxR = 2000000;

inline int sqr(int x) {return x*x;}

struct pt
{
    int x, y, c;
    pt(){}
    pt(int x, int y):x(x),y(y){}
    pt operator -(pt p)
    {
        return pt(x - p.x, y - p.y);
    }
    int operator *(pt p)
    {
        return x * p.x + y * p.y;
    }
    int operator &(pt p)
    {
        return x * p.y - y * p.x;
    }
    bool operator <(const pt &p)const
    {
        if(x == p.x) return y < p.y;
        return x < p.x;
    }
    bool operator ==(pt p)
    {
        return x == p.x && y == p.y;
    }
    int dis2(pt p)
    {
        return sqr(x - p.x) + sqr(y - p.y);
    }
    void getP(int _c)
    {
        scanf("%d%d", &x, &y);
        c = _c;
    }
};
struct LP
{
    pt p;
    LP *s;
};

pt S[MaxS], wl[MaxW][2];
LP Rem[MaxR], *hd[AbsY * 2], *cp;
int N, M, P, w, rad, rad2;
vector <pt> R[MaxP];

bool cmp(const pt &i, const pt &j)
{
    if(i.x == j.x) return i.c < j.c;
    return i.x < j.x;
}
bool between(pt a, pt b, pt c)
{
    return (a - c) * (b - c) <= 0;
}
int sign(int x){return (x > 0) - (x < 0);}
bool crossWall(pt p, pt q ,int d2)
{
    if(p == q) return true;
    int c = 0;
    for(int i = 0; i < w; i++)
    {
        pt a = wl[i][0], b = wl[i][1];
        int pqa = sign((q - p) & (a - p));
        int pqb = sign((q - p) & (b - p));
        int abp = sign((b - a) & (p - a));
        int abq = sign((b - a) & (q - a));
        if((pqa * pqb < 0 && abp * abq < 0) ||
           (pqa == 0 && between(p,q,a)) ||
           (pqb == 0 && between(p,q,b)))
           ++c;
    }
    return rad >= c && d2 <= sqr(rad - c);
}
void cal()
{
    memset(hd, 0, sizeof(hd));
    cp = Rem;
    for(int i = 0; i < P; i++)
    {
        if(S[i].c < N)
        {
            LP *&r = hd[S[i].y + AbsY];
            LP *nl = cp++;
            nl->p = S[i], nl->s = r;
            r = nl;
        }
        else
        {
            int c = S[i].c - N;
            int y = S[i].y;
            for(int ny = y - rad; ny <= y + rad; ny++)
                for(LP *l = hd[ny + AbsY]; l; l = l->s)
                {
                    int d2 = S[i].dis2(l->p);
                    if(d2 > rad2) break;
                    if(crossWall(S[i], l->p, d2))
                        R[c].push_back(l->p);
                }
        }
    }
}

int main()
{
//    freopen("data.in", "r", stdin);
    int tCase;
    scanf("%d", &tCase);
    for(int ct = 1; ct <= tCase; ct++)
    {
        scanf("%d%d%d%d", &N, &rad, &w, &M);
        rad2 = sqr(rad);
        P = N + M;
        for(int i = 0; i < N; i++)
            S[i].getP(i);
        for(int i = 0; i < w; i++)
            wl[i][0].getP(i), wl[i][1].getP(i);
        for(int i = 0; i < M; i++)
            S[i + N].getP(i + N);
        for(int i = 0; i < M; i++)
            R[i].clear();
        sort(S, S + P, cmp);
        cal();
        reverse(S, S + P);
        cal();
        for(int i = 0; i < M; i++)
        {
            int c = R[i].size();
            sort(R[i].begin(), R[i].end());
            printf("%d", c);
            for(int j = 0; j < c; j++)
                printf(" (%d,%d)", R[i][j].x, R[i][j].y);
            putchar('\n');
        }
    }
    return 0;
}