#include <stdio.h>
#define maxn 33200
#define AddHash(x) (hash[x.arr[0]][x.arr[1]][x.arr[2]][x.arr[3]][x.arr[4]][x.arr[5]][x.pos][x.vis]=1)
#define InHash(x) (hash[x.arr[0]][x.arr[1]][x.arr[2]][x.arr[3]][x.arr[4]][x.arr[5]][x.pos][x.vis])
#define AddWay(x) {for(i=0;i<6;i++){way[wai][i]=x.arr[i];}way[wai][6]=x.vis,way[wai++][7]=x.step;}
#define Swap(x,y) {x^=y;y^=x;x^=y;}
#define Abs(x,y) ((x-y>0)?(x-y):(y-x))
bool vis[10][6] = {
    {1, 0, 0, 0, 0, 0},
    {1, 1, 0, 0, 0, 0},
    {1, 1, 1, 0, 0, 0},
    {1, 1, 1, 1, 0, 0},
    {1, 1, 1, 1, 1, 0},
    {1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 1},
    {1, 1, 0, 0, 0, 1},
    {1, 1, 1, 0, 0, 1},
    {1, 1, 1, 1, 0, 1}};
bool hash[6][6][6][6][6][6][6][10];
int wai, way[720][8];
struct Node {
    int arr[6], pos, vis, step;
};
struct Q {
    int head, tail;
    Node a[maxn];
} q;
void Enqueue(Node r)
{
    q.a[q.tail] = r;
    if(q.tail == maxn-1) q.tail = 0;
    else q.tail++;
    return;
}
Node Dequeue()
{
    Node z = q.a[q.head];
    if(q.head == maxn-1) q.head = 0;
    else q.head++;
    return z;
}
bool Is_empty()
{
    return q.head == q.tail;
}
void bfs()
{
    Node now, next;
    int i;
    wai=now.pos=now.vis=now.step=0;
    for(i=0;i<6;i++){
        now.arr[i] = i;
    }
    AddHash(now);
    Enqueue(now);
    while(!Is_empty()){
        now = Dequeue();
        AddWay(now);
        if(now.pos>0){
            next = now;
            next.step++;
            Swap(next.arr[0],next.arr[next.pos]);
            if(!InHash(next)){
                AddHash(next);
                Enqueue(next);
            }
        }
        if(now.pos<5){
            next = now;
            next.pos++, next.step++;
            if(next.pos>next.vis || (next.vis>5&&next.pos>next.vis-6)){
                if(next.vis == 9) next.vis=5;
                else next.vis++;
            }
            if(!InHash(next)){
                AddHash(next);
                Enqueue(next);
            }
            next = now;
            next.step++;
            Swap(next.arr[5],next.arr[next.pos]);
            if(next.vis<5){
                next.vis+=6;
                if(next.vis==10) next.vis=5;
            }
            if(!InHash(next)){
                AddHash(next);
                Enqueue(next);
            }
        }
    }
    return;
}
int main()
{
    bfs();
    int Begin,End,src[6],des[6],i,j,Min,step;
    scanf("%d %d", &Begin, &End);
    for(i=5;~i;i--){
        src[i]=Begin%10;
        Begin/=10;
        des[i]=End%10;
        End/=10;
    }
    Min=0x7fffffff;
    for(i=0;i<wai;i++){
        step=way[i][7];
        for(j=0;j<6;j++){
            if(src[way[i][j]]!=des[j] && !vis[way[i][6]][j]) break;
            else step+=Abs(src[way[i][j]],des[j]);
        }
        if(j==6 && step<Min) Min = step;
    }
    printf("%d\n", Min);
    return 0;
}
