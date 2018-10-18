#include<stdio.h>
#include<string.h>
#define MAXD 100010
#define MAXS 5000010
#define INF 0x3f3f3f3f
int N, Q, M, top, pool[MAXS], node, key[MAXS], left[MAXS], right[MAXS], size[MAXS], pre[MAXS], a[2 * MAXD], lx[4 * MAXD], rx[4 * MAXD];
struct Splay
{
    int T;
    void update(int x)
    {
        size[x] = size[left[x]] + size[right[x]] + 1;
    }
    void left_rotate(int x)
    {
        int y = right[x], p = pre[x];
        right[x] = left[y];
        if(right[x])
            pre[right[x]] = x;
        left[y] = x;
        pre[x] = y;
        pre[y] = p;
        if(p != 0)
            right[p] == x ? right[p] = y : left[p] = y;
        else
            T = y;
        update(x);
    }
    void right_rotate(int x)
    {
        int y = left[x], p = pre[x];
        left[x] = right[y];
        if(left[x])
            pre[left[x]] = x;
        right[y] = x;
        pre[x] = y;
        pre[y] = p;
        if(p != 0)
            right[p] == x ? right[p] =  y : left[p] = y;
        else
            T = y;
        update(x);
    }
    void splay(int x, int goal)
    {
        int y, z;
        for(;;)
        {
            if((y = pre[x]) == goal)
                break;
            if((z = pre[y]) == goal)
                right[y] == x ? left_rotate(y) : right_rotate(y);
            else
            {
                if(right[z] == y)
                {
                    if(right[y] == x)
                        left_rotate(z), left_rotate(y);
                    else
                        right_rotate(y), left_rotate(z);
                }
                else
                {
                    if(left[y] == x)
                        right_rotate(z), right_rotate(y);
                    else
                        left_rotate(y), right_rotate(z);
                }
            }
        }
        update(x);
    }
    int calculate(int &T, int k)
    {
        if(T == 0)
            return 0;
        if(k < key[T])
            return calculate(left[T], k);
        else
            return size[left[T]] + 1 + calculate(right[T], k);
    }
    int Delete(int &T, int v)
    {
        -- size[T];
        if(key[T] == v || (v < key[T] && left[T] == 0) || (v > key[T] && right[T] == 0))
        {
            int k = key[T], p = pre[T];
            if(left[T] == 0 || right[T] == 0)
            {
                pool[++ top] = T;
                T = left[T] + right[T];
                if(T)
                    pre[T] = p;
            }
            else
                key[T] = Delete(left[T], key[T] + 1);
            return k;
        }
        if(v < key[T])
            return Delete(left[T], v);
        else
            return Delete(right[T], v);
    }
    int query(int k)
    {
        return calculate(left[right[T]], k);
    }
    void change(int k, int v)
    {
        Delete(T, k);
        splay(Insert(T, v, 0), right[T]);
    }
    void new_node(int &T, int v)
    {
        if(top)
            T = pool[top --];
        else
            T = ++ node;
        key[T] = v;
        size[T] = 1;
        left[T] = right[T] = 0;
    }
    int Insert(int &T, int v, int fa)
    {
        if(T == 0)
        {
            new_node(T, v);
            pre[T] = fa;
            return T;
        }
        ++ size[T];
        if(v < key[T])
            return Insert(left[T], v, T);
        else
            return Insert(right[T], v, T);
    }
    void init(int x, int y)
    {
        int i, j, k;
        T = 0;
        new_node(T, -INF), new_node(right[T], INF);
        pre[T] = 0, pre[right[T]] = T;
        size[T] = 2;
        for(i = x; i <= y; i ++)
            splay(Insert(T, a[i], 0), right[T]);
    }
}sp[4 * MAXD];
void init()
{
    int i, j, k;
    for(M = 1; M < N + 2; M <<= 1);
    node = top = size[0] = left[0] = right[0] = 0;
    memset(a, 0, sizeof(a[0]) * M);
    for(i = 1; i <= N; i ++)
        scanf("%d", &a[i]);
    for(i = M; i < 2 * M; i ++)
    {
        lx[i] = rx[i] = i - M;
        if(lx[i] >= 1 && rx[i] <= N)
            sp[i].init(lx[i], rx[i]);
    }
    for(i = M - 1; i > 1; i --)
    {
        lx[i] = lx[2 * i], rx[i] = rx[2 * i + 1];
        if(lx[i] >= 1 && rx[i] <= N)
            sp[i].init(lx[i], rx[i]);
    }
}
void change(int x, int k)
{
    int i;
    for(i = M + x; i ^ 1; i >>= 1)
    {
        if(lx[i] >= 1 && rx[i] <= N)
            sp[i].change(a[x], k);
    }
    a[x] = k;
}
void query(int x, int y, int k)
{
    int i, j, min, max, mid, n1, n2;
    min = 0, max = INF;
    for(;;)
    {
        mid = (min + max) / 2;
        if(mid == min)
            break;
        n1 = n2 = 0;
        for(i = x + M - 1, j = y + M + 1; i ^ j ^ 1; i >>= 1, j >>= 1)
        {
            if(~i & 1)
            {
                n1 += sp[i ^ 1].query(mid - 1), n2 += sp[i ^ 1].query(mid);
            }
            if(j & 1)
                n1 += sp[j ^ 1].query(mid - 1), n2 += sp[j ^ 1].query(mid);
        }
        if(n1 >= k)
            max = mid;
        else
            min = mid;
    }
    printf("%d\n", mid);
}
void solve()
{
    int i, j, k, x, y;
    char b[5];
    scanf("%d", &Q);
    for(i = 0; i < Q; i ++)
    {
        scanf("%s", b);
        if(b[0] == '2')
        {
            scanf("%d%d%d", &x, &y, &k);
            query(x, y, k);
        }
        else
        {
            scanf("%d%d", &x, &k);
            change(x, k);
        }
    }
}
int main()
{
    //int t;
    //scanf("%d", &t);
    while(scanf("%d", &N) == 1)
    {
//        scanf("%d%d", &N, &Q);
        init();
        solve();
    }
    return 0;
}
