#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 510*200;
int ch[maxn][128],fail[maxn],last[maxn];
int root,sz,cnt;
char str[10010];
bool used[510];

int newnode(){
    memset(ch[sz],-1,sizeof(ch[sz]));
    last[sz] = 0;
    return sz++;
}

void init(){
    sz = 0;
    root = newnode();
}

void insert(char *str,int id){
    int len = strlen(str);
    int now = root;
    for(int i = 0;i < len;i++){
        int &tmp = ch[now][str[i]];
        if(tmp == -1)   tmp = newnode();
        now = tmp;
    }
    last[now] = id;
}

void construct(){
    queue<int> q;
    fail[root] = root;
    for(int i = 0;i < 128;i++){
        int &tmp = ch[root][i];
        if(tmp == -1)   tmp = root;
        else{
            fail[tmp] = root;
            q.push(tmp);
        }
    }
    while(!q.empty()){
        int now = q.front();q.pop();
        for(int i = 0;i < 128;i++){
            if(ch[now][i] == -1){
                ch[now][i] = ch[fail[now]][i];
            }else{
                fail[ch[now][i]] = ch[fail[now]][i];
                q.push(ch[now][i]);
            }
        }
    }
}

void query(char *str,int id){
    int len = strlen(str);
    int now = root;
    int flag = 0;
    memset(used,0,sizeof(used));
    for(int i = 0;i < len;i++){
        now = ch[now][str[i]];
        int tmp = now;
        while(tmp != root){
            if(last[tmp]){
                flag = 1;
                used[last[tmp]] = 1;
            }
            tmp = fail[tmp];
        }
    }
    if(flag){
        cnt++;
        printf("web %d:",id);
        for(int i = 0;i < 510;i++){
            if(used[i]) printf(" %d",i);
        }
        printf("\n");
    }
}

int main(){
    init();
    int n,m;
    scanf("%d",&n);
    for(int i = 1;i <= n;i++){
        scanf("%s",str);
        insert(str,i);
    }
    construct();
    cnt = 0;
    scanf("%d",&m);
    for(int i = 1;i <= m;i++){
        scanf("%s",str);
        query(str,i);
    }
    printf("total: %d\n",cnt);
    return 0;
}
