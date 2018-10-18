#include <stdio.h>
#include <string.h>
#include <math.h>
#include <queue>
using namespace std;

const int maxn = 1000+100;
const double inf = 0xfffffff;
double Abs(double x)
{
  return x>0?x:(0-x);
}

struct Edge{
  int to,next,alt;
  double dist;
}edges[maxn*maxn];

struct HeapNode{
  int u,alt;
  double d;
  bool operator<(const HeapNode &rhs)const
  {
    if(1.0*rhs.alt/rhs.d < 1.0*alt/d) return true;
    else return false;
  }
};

struct Point{
  double x,y,z;
}points[maxn];

int m;
int head[maxn];
int pa[maxn];
double lowc[maxn];
double len,alt;
bool mark[maxn];

void Init()
{
  m=0;
  memset(head,-1,sizeof(head));
}

void AddEage(int from, int to, double dist, int alt)
{
  Edge &e = edges[m];
  e.next = head[from];
  e.to = to; e.dist = dist; e.alt=alt;
  head[from]=m;
  edges[m++]=e;
}

void Prim(int rt, int n)
{
  priority_queue<HeapNode>q;
  memset(mark,0,sizeof(mark));
  memset(pa,-1,sizeof(pa));
  for(int i=0; i<=n; i++) lowc[i]=inf;
  HeapNode x;
  lowc[rt]=x.d=x.alt=0; x.u=rt; pa[rt]=rt;
  q.push(x);
  while(!q.empty()){
    x=q.top(); q.pop();
    int u = x.u;
    if(mark[u])continue;
    mark[u]=true;
    alt+=x.alt; len+=x.d;
    for(int i=head[u]; i!=-1; i=edges[i].next){
      Edge e = edges[i];
      if(lowc[e.to]>e.alt/e.dist){
        lowc[e.to]=e.alt/e.dist; pa[e.to]=u;
        x.u=e.to; x.d=e.dist; x.alt=e.alt; q.push(x);
      }
    }
  }
}

int main()
{
//  freopen("test.in","r",stdin);
  int N;
  while(scanf("%d",&N)){
    if(N==0)break;
    Init();
    for(int i=0; i<N; i++){
      Point &p=points[i];
      scanf("%lf%lf%lf", &p.x, &p.y, &p.z);
      for(int j=0; j<i; j++){
        double dist=sqrt((p.x-points[j].x)*(p.x-points[j].x)+(p.y-points[j].y)*(p.y-points[j].y));
        AddEage(i,j,dist,Abs(p.z-points[j].z));
        AddEage(j,i,dist,Abs(p.z-points[j].z));
      }
    }
    len=alt=0;
    Prim(0,N);
    printf("%.3lf\n",alt/len);
  }
  return 0;
}



