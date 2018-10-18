#include <cstdio>
#include <cstring>
const int maxn=55;
char s[2][maxn][maxn];
int lv[maxn][maxn];
int N,M,F,K;
int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,-1,0,1};
int check(int cur,int x,int y){
    int re=0;
    for(int i=0;i<8;i++){
        if(x+dx[i]<=0) continue;
        if(y+dy[i]<=0) continue;
        if(x+dx[i]>N) continue;
        if(y+dy[i]>M) continue;
        if(s[cur][x+dx[i]][y+dy[i]]=='1')re++;
    }
    return re;
}

void solve(){
    int cur=0,nex=1;
    for(int t=1;t<=F;t++){
        nex=1-cur;
        for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++){
            if(s[cur][i][j]=='X'){
                s[nex][i][j]='X';
                continue;
            }
            if(lv[i][j]==t){
                s[nex][i][j]='X';
                continue;
            }
            int cnt=check(cur,i,j);
            if(s[cur][i][j]=='1'){
                if(cnt<2 || cnt>3) s[nex][i][j]='0';
                else s[nex][i][j]='1';
            }else{
                if(cnt==3) s[nex][i][j]='1';
                else s[nex][i][j]='0';
            }
        }
        cur=nex;
    }
}

int main(){
//    freopen("data.in","r",stdin);
    int Q,T,X,Y;
    scanf("%d",&Q);
    while(Q--){
        scanf("%d%d%d%d",&N,&M,&F,&K);
        memset(s,0,sizeof s);
        for(int i=1;i<=N;i++)
            scanf("%s",s[0][i]+1);
        memset(lv,0,sizeof lv);
        for(int i=0;i<K;i++){
            scanf("%d%d%d",&T,&X,&Y);
            lv[X][Y]=T;
        }
        solve();
        int f=F&1;
        for(int i=1;i<=N;i++)
            puts(s[f][i]+1);
    }
    return 0;
}
