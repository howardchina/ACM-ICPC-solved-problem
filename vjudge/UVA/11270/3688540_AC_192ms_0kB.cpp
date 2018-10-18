#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
typedef LL type;
typedef pair<int,LL> pil;
#define mp make_pair
#define FF first
#define SS second
const int maxn = 1<<10;
int p[2][maxn];
pil q[2][maxn];
int tail[2];

void init(int cur){
    memset(p[cur],-1,sizeof p[cur]);
    tail[cur]=0;
}

int main()
{
    int n,m,cur,st,pos,nst,hi;
    LL cnt;
    while(scanf("%d%d",&m,&n)!=EOF){
        if(m>n) swap(m,n);
        cur=0;
        st = (1<<m)-1;
        hi = 1<<(m-1);
        init(cur);
        p[0][st]=tail[cur];
        pos = tail[cur]++;
        cnt = 1;
        q[cur][pos]=mp(st,cnt);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++,cur^=1){
                init(cur^1);
                for(int k=tail[cur]-1;k>=0;k--){
                    st = q[cur][k].FF;
                    cnt = q[cur][k].SS;

                    if(st & hi){
                        nst = (st^hi)<<1;
                        if((pos=p[cur^1][nst])==-1){
                            pos = tail[cur^1]++;
                            p[cur^1][nst] = pos;
                            q[cur^1][pos]=mp(nst,cnt);
                        }else{
                            q[cur^1][pos].SS += cnt;
                        }

                        if(j && !(st&1)){
                            nst = ((st^hi)<<1)|3;
                            if((pos=p[cur^1][nst])==-1){
                                pos = tail[cur^1]++;
                                p[cur^1][nst] = pos;
                                q[cur^1][pos]=mp(nst,cnt);
                            }else{
                                q[cur^1][pos].SS += cnt;
                            }
                        }
                    }else{
                        nst = (st<<1)|1;
                        if((pos=p[cur^1][nst])==-1){
                            pos = tail[cur^1]++;
                            p[cur^1][nst] = pos;
                            q[cur^1][pos]=mp(nst,cnt);
                        }else{
                            q[cur^1][pos].SS += cnt;
                        }
                    }
                }
            }
        }
        st = (1<<m)-1;
        pos = p[cur][st];
        cnt = q[cur][pos].SS;
        printf("%lld\n",cnt);
    }
    return 0;
}
