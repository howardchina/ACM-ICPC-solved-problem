#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

const int maxn = 30050 ;

void assert(bool ok) {
    if(!ok) while(1) ;
}

vector<int>son[maxn];
int fa[30010];
int n;
struct node{
    char name[66];
    int d; // 第几代
    bool operator <(const node &rhs)const{
        return strcmp(name,rhs.name)<0;
    }
}p[30010];

map<string , int > id ;
int id_tot ;

int ID(string s) {
    if(id.count(s)) return id[s] ;
    id[s] = ++ id_tot ;
    return id_tot ;
}

void init()
{
    id.clear() ;
    id_tot = 0 ;
    for(int i=0; i<=n; i++) son[i].clear() ;
    memset(fa, 0, (n+1) * sizeof(fa[0])) ;

    int f[1000] ;

    char buf[100] ;
    for(int i=1; i<=n; i++) {
        scanf("%s", buf) ;
        int d = 0 ;
        while(buf[d] == '.') d ++ ;

        int x = ID(buf+d) ;

        p[x].d = d ;
        strcpy(p[x].name , buf+d) ;

        f[d] = x ;
        if(d > 0) {
            fa[x] = f[d-1] ;
            son[fa[x]].push_back(x)  ;
        }

    }

}


bool cmp(int x , int y) {
    return p[x] < p[y] ;
}

void ssort()
{
    for(int i=1;i<=n;i++)
        if(son[i].size()>0)
            sort(son[i].begin() ,son[i].end() , cmp);
}
void Lout(int x)
{
    for(int i=0; i<p[x].d; i++) printf(".");
    printf("%s\n",p[x].name);
    int l=son[x].size() ;
    for(int i=0;i<l;i++)
        Lout(son[x][i]);
}
void bout(int x)
{
    if(x==1)printf("1\n");
    else printf("%d\n",son[fa[x]].size());
}
void cou(int x1,int x2)
{
    if(p[x1].d<p[x2].d)swap(x1,x2);

    while(p[x1].d!=p[x2].d)x1=fa[x1];


    while(fa[x1]!=fa[x2])
    {
        x1=fa[x1];
        x2=fa[x2];
    }
    printf("%s\n",p[ fa[x1] ].name);
}



int main()
{

//    freopen("data.in", "r", stdin) ;

    while(scanf("%d", &n) == 1 && n) {
        init() ;

        int Q ;

        scanf("%d", &Q) ;

        ssort() ;
        while(Q--) {
            char op[5] , x[100] , y[100] ;
            scanf("%s", op) ;
            if(op[0] == 'L') {
                Lout(1) ;
            }
            else if(op[0] == 'b') {
                scanf("%s", x) ;
                bout(ID(x)) ;
            }
            else if(op[0] == 'c') {
                scanf("%s%s", x ,y) ;
                cou(ID(x) , ID(y)) ;
            }
        }

        assert(id_tot == n) ;

    }

    return 0;
}
