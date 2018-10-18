#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long LL;

struct Cost{
    LL c;
    int d;

    bool operator <(const Cost& rhs)const{
        return c > rhs.c;
    }
};

int day[2550], R[2550], cost[100010];

priority_queue<Cost>pq;

const int dd[2][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                       {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

const char mm[12][4] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov" , "Dec"};

int trans(char *month, int date, int year, int hour){
    int x = 0;
    if (year % 4 == 0) x = 1;//年只有20年左右 不用写复杂闰年判断

    int re = 0;

    for(int i = 0; i < year; i++){
        if (i % 4 == 0) re += 366;
        else re += 365;
    }

    for(int i = 0; strcmp(month, mm[i]); i++){
        re += dd[x][i];
    }

    re += (date-1);

    re = re * 24 + hour;

    return re;
}

int main()
{
//    freopen("data.in", "r", stdin);
    int N, M, T, S;
    char month[11]; int date, year, H;
    while(1){
        scanf("%d%d", &N,&M);
        if (N==0 && M==0) break;

        char basemonth[] = "Jan";
        int baseday = trans(basemonth, 1, 0, 0);
        for(int i = 0; i < N; i++){
            scanf("%s%d%d%d%d", month, &date, &year, &H, &R[i]);
            day[i] = trans(month, date, year-2000, H) - baseday;
        }

        scanf("%d%d", &T, &S);

        for(int i = 0; i < M; i++){
            scanf("%d", &cost[i]);
        }

        while(!pq.empty()) pq.pop();

        int j = 0;
        LL ans = 0;
        for(int i = 0; i < N; i++){
            for(;j < M && j <= day[i]; j++){
                Cost cur;
                cur.c = (LL)cost[j] - (LL)S*j;
                cur.d = j;
//                printf("%I64d %d\n", cur.c, cur.d);
                pq.push(cur);
            }
            while(pq.top().d + T < day[i]) pq.pop();
//            printf("%I64d %d\n", pq.top().c, pq.top().d);
            ans += ((pq.top().c + (LL)S*pq.top().d) + (LL)S*(day[i] - pq.top().d)) * R[i];
        }

        printf("%I64d\n", ans);
    }
    return 0;
}
