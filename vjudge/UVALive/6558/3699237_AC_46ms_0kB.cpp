#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
#define x first
#define y second
#define MP make_pair
const int maxn = 222;
typedef pair<string,string> pss;

char s[maxn],s1[maxn];
int du[maxn],dep[maxn];
vector<int>g[maxn];
pss ans[maxn*maxn];
int anscnt;
string name[maxn];

void output(){
    sort(ans,ans+anscnt);
    printf("%d",anscnt);
    for(int i=0;i<anscnt;i++){
        printf(" %s,%s",ans[i].x.c_str(),ans[i].y.c_str());
    }
    putchar('\n');
}

void add(int u,int v){
    g[u].push_back(v);
    du[v]++;
}
int vis[maxn];
void bfs(int f){
    queue<int>q;
    int u = f;
    q.push(u);
    memset(vis,0,sizeof vis);
    int v;
    while(!q.empty()){
        u = q.front();
        q.pop();
        for(int i=g[u].size()-1;i>=0;i--){
            v = g[u][i];
            if(!vis[v]){
                q.push(v);
            }
            vis[v]++;
        }
    }
    for(int i=g[f].size()-1;i>=0;i--){
        v = g[f][i];
        if(vis[v]>1) ans[anscnt++]=MP(name[f],name[v]);
    }
}

bool solve(){
    int m,tot=1,u,v;
    scanf("%d",&m);
    if(m==0) return false;

    map<string,int>mp;
    for(int i=1;i<maxn;i++){
        g[i].clear();
        du[i]=0;
    }


    for(int i=0;i<m;i++){
        scanf("%s%s",s,s1);
        if(mp.count(s)==0){
            mp.insert(MP(s,tot));
            name[tot++]=s;
        }
        if(mp.count(s1)==0){
            mp.insert(MP(s1,tot));
            name[tot++]=s1;
        }
        u = mp[s];
        v = mp[s1];
        add(u,v);
    }

    queue<int>q;
    for(int i=1;i<tot;i++){
        if(du[i]==0){
            q.push(i);
        }
    }

    anscnt=0;
    while(!q.empty()){
        u = q.front();
        q.pop();

        bfs(u);

        for(int i=g[u].size()-1;i>=0;i--){
            v = g[u][i];
            du[v]--;
            if(du[v]==0){
                q.push(v);
            }
        }
    }

    return true;
}

int main()
{
//    freopen("data.in","r",stdin);
    int cas=1;
    while(solve()){
        printf("Case %d: ",cas++);
        output();
    }
    return 0;
}
