#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

const int N = 50001;
const int inf = 100000000;
struct Node{
    Node* ch[2];
    int r,v,s,w;//儿子 随机数 值 结点总数 次数
    void init(int v=0){
        this->v = v;
        ch[0] = ch[1] = NULL;
        r = rand();
        s = 1;
        w = 1;
    }
    bool operator <(const Node& rhs)const{
        return r<rhs.r;
    }
    int cmp(int x)const{
        if (x==v) return -1;
        return x<v ? 0 : 1;
    }

    void maintain(){
        s = w;
        if (ch[0]) s += ch[0]->s;
        if (ch[1]) s += ch[1]->s;
    }
};

Node* root[N*4]; int a[N];
Node node[N*4*16];
int tot=1;int tmp;
int n, m;

Node* newNode(int v){
    node[tot].init(v);
    return &node[tot++];
}

void rotate(Node* &o,int d){
    Node* k = o->ch[d^1]; o->ch[d^1] = k->ch[d]; k->ch[d] = o;
    o->maintain(); k->maintain(); o = k;
}

void insert(Node* &o,int num){
    if (!o)o = newNode(num);
    else{
        int d = o->cmp(num);
        if (d<0){o->w++;}
        else{
            insert(o->ch[d], num);
            if (o->ch[d] > o) rotate(o,d^1);
        }
    }
    o->maintain();
}

void build(int o,int l,int r,int x,int num){
//    if (num == 2477809){
//        printf("Build root[%d] l=%d r=%d\n", o, l, r);
//    }

    insert(root[o],num);
    if(l==r) return;
    int m = (l+r)>>1;
    if(x<=m) build(o<<1,l,m,x,num);
    else build(o<<1|1,m+1,r,x,num);
}

void ask_rank(Node* &o,int num){
    if (!o) return;
    else if(num == o->v) { if(o->ch[0])tmp+=o->ch[0]->s; return;}
    else if(num < o->v) ask_rank(o->ch[0], num);
    else{
        tmp += o->ch[0]? o->ch[0]->s : 0;
        tmp += o->w;
        ask_rank(o->ch[1], num);
    }
}

void get_rank(int o,int l,int r,int x,int y,int num){
    if(l==x && r==y) {
        ask_rank(root[o], num); return ;
    }
    int mid = (l+r)>>1;
    if (mid>=y) get_rank(o<<1,l,mid,x,y,num);
    else if (mid<x) get_rank(o<<1|1,mid+1,r,x,y,num);
    else{
        get_rank(o<<1,l,mid,x,mid,num);
        get_rank(o<<1|1,mid+1,r,mid+1,y,num);
    }
}

void get_index(int x, int y, int k){
    int num;
    int l = 0, r = inf, m;
    while(l<=r){
        m = (l+r)>>1;
        tmp = 1;
        get_rank(1, 1, n, x, y, m);
        if (tmp<=k){
            l = m+1;
            num = m;
        }
        else{
            r = m-1;
        }
    }
    printf("%d\n", num);
}

void del(Node* &o,int num){

    int d = o->cmp(num);
    if (d<0){
        if (o->w==1){
            if (o->ch[0] && o->ch[1]){
                int d2 = (o->ch[0]) > (o->ch[1]);
                rotate(o,d2); del(o->ch[d2], num);
            }
            else{
                if (o->ch[0]){
                    o = o->ch[0];
                }
                else if (o->ch[1]){
                    o = o->ch[1];
                }
                else{
                    o = NULL;
                }
            }
        }else{
            o->w--;
        }
    }
    else{
        del(o->ch[d], num);
    }
    if(o) o->maintain();
}

void change(int o,int l,int r,int x,int nxt,int cur){
//    if(o==58){
//        puts("Debug");
//
//    }

//    printf("Change root[%d] l=%d r=%d root->s=%d\n",o,l,r,root[o]->s);
    del(root[o],cur);
    insert(root[o],nxt);
//    printf("_Change root[%d] l=%d r=%d root->s=%d\n",o,l,r,root[o]->s);
    if(l==r) return;
    int m = (l+r)>>1;
    if(x<=m) change(o<<1,l,m,x,nxt,cur);
    else change(o<<1|1,m+1,r,x,nxt,cur);
}

void ask_before(Node* &o,int num){
    if (!o) return;
    else if (o->v < num) {
        tmp = max(o->v, tmp);
        ask_before(o->ch[1], num);
    }
    else{
        ask_before(o->ch[0], num);
    }
}

void get_before(int o,int l,int r,int x,int y,int num){
    if(l==x && r==y) {
        ask_before(root[o], num); return ;
    }
    int mid = (l+r)>>1;
    if (mid>=y) get_before(o<<1,l,mid,x,y,num);
    else if (mid<x) get_before(o<<1|1,mid+1,r,x,y,num);
    else{
        get_before(o<<1,l,mid,x,mid,num);
        get_before(o<<1|1,mid+1,r,mid+1,y,num);
    }
}

void ask_after(Node* &o,int num){
    if (!o) return;
    else if (o->v > num) {
        tmp = min(o->v, tmp);
        ask_after(o->ch[0], num);
    }
    else{
        ask_after(o->ch[1], num);
    }
}

void get_after(int o,int l,int r,int x,int y,int num){
    if(l==x && r==y) {
        ask_after(root[o], num); return ;
    }
    int mid = (l+r)>>1;
    if (mid>=y) get_after(o<<1,l,mid,x,y,num);
    else if (mid<x) get_after(o<<1|1,mid+1,r,x,y,num);
    else{
        get_after(o<<1,l,mid,x,mid,num);
        get_after(o<<1|1,mid+1,r,mid+1,y,num);
    }
}

int main()
{
//    freopen("data.in","r",stdin);
//    freopen("data.out","w",stdout);
    int op, l, r, k, pos;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) build(1,1,n,i,a[i]);
    while(m--){
        scanf("%d", &op);
        if (op == 1){
            scanf("%d%d%d", &l, &r, &k);
            tmp = 1;
            get_rank(1,1,n,l,r,k);
            printf("%d\n", tmp);
        }
        else if (op == 2){
            scanf("%d%d%d", &l, &r, &k);
            get_index(l,r,k);
        }
        else if (op == 3){
            scanf("%d%d", &pos, &k);
            change(1,1,n,pos,k,a[pos]);
            a[pos] = k;
        }
        else if (op == 4){
            scanf("%d%d%d", &l, &r, &k);
            tmp = 0;
            get_before(1,1,n,l,r,k);
            printf("%d\n", tmp);
        }
        else if (op == 5){
            scanf("%d%d%d", &l, &r, &k);
            tmp = inf;
            get_after(1,1,n,l,r,k);
            printf("%d\n", tmp);
        }
    }
    return 0;
}
