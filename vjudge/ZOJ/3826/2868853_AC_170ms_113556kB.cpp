#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 400010,maxc = 70;
struct Node{
    int nxt[maxc];
    int b,e;
}node[maxn];
int tot,n;
char s[maxn];
char qs[maxn];
int newNode(){
    Node* np= &node[tot];
    np->b = 0;
    np->e = 0;
    for(int i=0;i<maxc;i++)
        np->nxt[i]=0;
    return tot++;
}
int mp(char c){
    if('a'<=c && c<='z') return c-'a';
    if('A'<=c && c<='Z') return c-'A'+26;
    if('0'<=c && c<='9') return c-'0'+54;
    //if('.'==c)
    return 64;
}

bool isData(char c){
    return ('0'<=c && c<='9') || ('a'<=c && c<='z') || ('A'<=c && c<='Z');
}

int insert(int key,int b){
    int e;
    if(s[b]=='"'){
        e=b+1;
        while(s[e]!='"')e++;
    }else{
        e=b;
        if(!node[key].nxt[mp('.')])
            node[key].nxt[mp('.')] = newNode();
        key = node[key].nxt[mp('.')];
        while(s[++e]!='}'){
            int crtkey=key;
            while(s[++e]!='"'){
                if(!node[crtkey].nxt[mp(s[e])])
                    node[crtkey].nxt[mp(s[e])] = newNode();
                crtkey = node[crtkey].nxt[mp(s[e])];
            }
            e+=2;
            node[crtkey].b = e;
            e = insert(crtkey,e);
            node[crtkey].e = e;
            if(s[e]=='}')break;
        }
    }
    return ++e;
}

int query(){
    int key = node[0].nxt[mp('.')];
    int n = strlen(qs);
    for(int i=0;i<n;i++){
        if(qs[i]=='"') continue;
        if(node[key].nxt[mp(qs[i])])
            key = node[key].nxt[mp(qs[i])];
        else return 0;
    }
    return key;
}
int main()
{
//    freopen("data.in","r",stdin);
    int T;
    scanf("%d",&T);
    gets(s);
    while(T--){
        int key,q,root;
        gets(s);
        n = strlen(s);
        tot=0;
        root = newNode();
        node[root].b = 0;
        node[root].e = insert(root,0);
        scanf("%d",&q);
        gets(qs);
        while(q--){
            gets(qs);
            key=query();
            if(key && node[key].e){
                int e=node[key].e;
                for(int i=node[key].b;i<e;i++)
                    putchar(s[i]);
                putchar('\n');
            }else puts("Error!");
        }
    }
    return 0;
}
