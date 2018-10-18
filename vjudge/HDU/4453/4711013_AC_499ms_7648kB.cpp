#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cassert>
using namespace std;
const int maxn = 200010 ;
const int INF = 0x3f3f3f3f ;
#define Lson o->son[0]
#define Rson o->son[1]

int A[100010] ;

struct Node{
    Node*son[2] , *fa ;
    int sz  , key , add ;
    bool flip ;
    inline void pushup(){
        sz = 1 ;
        if(son[0]) sz += son[0]->sz ;
        if(son[1]) sz += son[1]->sz ;
    }
    void pushdown() {
        if(add) {
            if(son[0]) son[0]->add += add , son[0]->key += add ;
            if(son[1]) son[1]->add += add , son[1]->key += add ;
            add = 0;
        }
        if(flip) {
            flip ^= 1 ;
            swap(son[0] , son[1]) ;
            if(son[0]) son[0]->flip ^= 1 ;
            if(son[1]) son[1]->flip ^= 1 ;
        }
    }
};

struct SplayTree{
    Node nodes[maxn]  , *root ;
    int node_cnt ;
    void newNode(Node*&o , Node*fa , int key) {
        o = &nodes[++node_cnt] ;
        o -> key = key ;
        o ->fa = fa;
        Lson = Rson = NULL ;
        o->sz = 1 ;
        o->flip = 0 ;
        o->add = 0;
    }
    void rotate(Node*o , int k) {
        o->pushdown() ;
        Node*a = o->son[k] , *y = o->fa , *z = y->fa ;
        if(z) z->son[ z->son[1]==y ] = o ;
        o->son[k] = y ;
        y->son[k^1] = a ;
        if(a) a->fa = y ;
        y->fa = o ;
        o->fa = z ;
        y->pushup() ;
        o->pushup() ;
    }
    void splay(Node*o , Node*goal) {
        while(o->fa != goal) rotate(o , o->fa->son[0] == o) ;
        if(goal == NULL) root = o ;
    }
    void build(Node*&o , Node*fa , int L , int R) {
        if(L > R) return ;
        int mid = (L+R)>>1 ;
        newNode(o , fa , A[mid]) ;
        build(Lson  , o , L , mid-1) ;
        build(Rson , o , mid+1 , R)  ;
        o ->pushup() ;
    }
    void init(int N) {
        node_cnt = 0 ;
        newNode(root , NULL , -INF) ;
        newNode(root->son[1] , root , INF) ;
        build(root->son[1]->son[0] , root->son[1] , 1 , N) ;
        root->son[1]->pushup() ;
        root->pushup() ;
    }
    Node*select(int k) {
        assert(1<=k && k<=root->sz) ;
        Node*o = root ;
        o->pushdown()  ;
        int s = Lson ? Lson->sz + 1  :   1 ;
        while(s != k) {
            if(s < k) k -= s , o = Rson ;
            else o = Lson ;
            o->pushdown() ;
            s = Lson ? Lson->sz + 1 : 1 ;
        }
        return o ;
    }
    void Flip(int a, int b) {
        Node*x = select(a-1) , *y = select(b+1) ;
        splay(x , NULL) , splay(y , x) ;
        y->son[0]->flip ^= 1 ;
        y->pushup() , x->pushup() ;
    }
    Node* cut(int a ,int b) {
        Node*x = select(a-1) , *y = select(b+1) ;
        splay(x , NULL) , splay(y , x) ;
        Node *tmp = y->son[0] ;
        y->son[0] = NULL ;
        y->pushup() , x->pushup() ;
        return tmp ;
    }
    void Add(int a , int b, int val) {
        Node*x = select(a-1) , *y = select(b+1) ;
        splay(x , NULL) , splay(y , x) ;
        y->son[0]->add += val ;
        y->son[0]->key += val ;
        y->pushup() ;
        x->pushup() ;
    }
    void Insert(int a , int val) {
        Node*x = select(a) , *y = select(a+1) ;
        splay(x , NULL) , splay(y , x) ;
        newNode(y->son[0] , y , val) ;
        y->pushup() , x->pushup() ;
    }
    void Insert(int a, Node *tmp) {
        Node*x = select(a) , *y = select(a+1) ;
        splay(x , NULL) , splay(y , x) ;
        y->son[0] = tmp ;
        tmp->fa = y ;
        y->pushup() , x->pushup() ;
    }
    void Delete(int a) {
        Node*x = select(a-1) , *y = select(a+1) ;
        splay(x , NULL) , splay(y , x) ;
        y->son[0] = NULL ;
        y->pushup() , x->pushup() ;
    }
    int Query(int a) {
        Node *x = select(a) ;
        return x->key ;
    }

   
}spt;

int main()
{ 

    int N , M , K1, K2, cas = 1;
    while(scanf("%d%d%d%d", &N, &M, &K1, &K2) == 4 && N) {
        int P = 1;
        for(int i=1; i<=N; i++) scanf("%d" , &A[i]) ;
        spt.init(N) ;

        printf("Case #%d:\n" , cas++) ;

        while(M--) {
            char cmd[10] ;
            int x ;
            scanf("%s", cmd) ;
            if(cmd[0] == 'a') {
                scanf("%d", &x) ;
                int res = N - P + 1 ;
                if(res >= K2) {
                    spt.Add(P+1, P+K2-1+1, x);
                }
                else {
                    spt.Add(P+1, N+1 , x);
                    spt.Add(1+1, K2 - res +1, x);
                }
            }
            else if(cmd[0] == 'r') {
                if(P+K1-1 <= N) {
                    spt.Flip(P +1, P+K1-1+1) ;
                }
                else {
                    int C1 = N-P+1, C2 = K1 - C1 , R = N - K1 ;
                    if(C1 == C2){
                        Node*tmp1 = spt.cut(P+1, P+C1-1+1);
                        Node*tmp2 = spt.cut(1+1 , C2+1) ;
                        tmp1->flip^=1 , tmp2->flip ^= 1 ;
                        spt.Insert(R +1, tmp2) ;
                        spt.Insert(0 +1, tmp1) ;
                    }
                    else if(C1 > C2) {
                        int C3 = C1 - C2 ; C1 -= C3 ;
                        Node*tmp1 = spt.cut(P+1, P+C1-1+1);
                        Node*tmp3 = spt.cut(P+C1+1, P+C1+C3-1+1) ;
                        Node*tmp2 = spt.cut(1+1 , C2+1) ;
                        tmp1->flip^=1 , tmp2->flip^=1 , tmp3->flip^=1 ;
                        spt.Insert(0+1 , tmp1);
                        spt.Insert(R+C1+1, tmp2) ;
                        spt.Insert(R+C1+C2+1 , tmp3);
                    }
                    else if(C2 > C1) {
                        int C3 = C2 - C1;  C2 -= C3 ;
                        Node *tmp1 = spt.cut(P+1, P+C1-1+1) ;
                        Node *tmp3 = spt.cut(1+1,C3+1) ;
                        Node *tmp2 = spt.cut(1+1,C2+1) ;
                        tmp1->flip^=1 , tmp2->flip^=1 , tmp3->flip^=1 ;
                        spt.Insert(R+1 , tmp2);
                        spt.Insert(0+1, tmp1) ;
                        spt.Insert(0+1 ,tmp3) ;
                    }
                }
            }
            else if(cmd[0] == 'i') {
                scanf("%d", &x) ;
                spt.Insert(P+1 , x) ;
                N ++ ;
            }
            else if(cmd[0] == 'd') {
                spt.Delete(P+1) ;
                if(P == N) P = 1 ;
                N -- ;
            }
            else if(cmd[0] == 'm') {
                scanf("%d", &x) ;
                if(x == 1) {
                    if(P == 1) P = N ;
                    else P -- ;
                }
                else {
                    if(P == N) P = 1 ;
                    else P ++ ;
                }
            }
            else if(cmd[0] == 'q') {
                printf("%d\n" , spt.Query(P+1)) ;
            }
        }
    }
    return 0;
}
