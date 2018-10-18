#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAX = 1005;
int N;
double D;
struct Node
{
    double start, end;
}list[ MAX ];
bool cmp( Node a, Node b )
{    return a.start < b.start;    }
// 记住了，浮点数的比较不能用-
int cmp1( const void *a, const void *b )
{
    if ( ((Node*)a)->end < ((Node*)b)->end )
        return -1;
    else if ( ((Node*)a)->end > ((Node*)b)->end )
        return 1;
    else
        return 0;
}
bool read()
{
    int i;
    double range, x, y;
    bool mark = true;
    if ( D <= 0 )
        mark = false;
    for( i = 0; i < N; i ++ )
    {
        scanf( "%lf %lf", &x, &y );
        if ( y > D )
            mark = false;
        if ( mark )
        {
            range = sqrt( 1.0*D * D - 1.0*y * y );
            list[ i ].start = x - range;
            list[ i ].end = x + range;
        }
    }
    if ( mark )
        qsort( list, N, sizeof( Node ), cmp1 );
    return mark;
}
int solve()
{
    int i, cnt = 1;
    double curEnd = list[ 0 ].end;
    for( i = 1; i < N; i ++ )
        if ( list[ i ].start > curEnd )
        {
            cnt ++;
            curEnd = list[ i ].end;
        }
    return cnt;
}
int main()
{
    int i = 0;
    while( scanf( "%d %lf", &N, &D ) != EOF )
    {
        if ( N == 0 && D == 0 )
            break;
        if ( read() )
            printf( "Case %d: %d\n", ++ i, solve() );
        else
            printf( "Case %d: %d\n", ++ i, -1 );
    }
    return 0;
}
