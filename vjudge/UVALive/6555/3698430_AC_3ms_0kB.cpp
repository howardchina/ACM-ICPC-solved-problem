#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;
#define x first
#define y second
#define mp make_pair
typedef pair<int,int> pii;
const int maxn = 111111;

char s[maxn];
pii m[26];
int p[5][5];
int has[26];
void insert(int ch){
    has[ch]=1;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(p[i][j]==-1){
                m[ch]=mp(i,j);
                p[i][j]=ch;
                return ;
            }
        }
    }

}

void fill(){
    for(int i=0;i<26;i++){
        if(!has[i] && i!=9){
            insert(i);
        }
    }
}

void Debug(){

    putchar('\n');
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            putchar('A'+p[i][j]);
        }
        putchar('\n');
    }

}

void gen(int a,int b){
    int ax=m[a].x,ay=m[a].y;
    int bx=m[b].x,by=m[b].y;
    if(ax==bx){
        ay=(ay+1)%5;
        by=(by+1)%5;
        printf("%c%c",'A'+p[ax][ay],'A'+p[bx][by]);
    }else if(ay==by){
        ax=(ax+1)%5;
        bx=(bx+1)%5;
        printf("%c%c",'A'+p[ax][ay],'A'+p[bx][by]);
    }else{
        printf("%c%c",'A'+p[ax][by],'A'+p[bx][ay]);
    }
}

void solve(){
    gets(s);
    int n=strlen(s);
    memset(has,0,sizeof has);
    memset(p,-1,sizeof p);
    for(int i=0;i<n;i++){
        if(('a'<=s[i] && s[i]<='z') || ('A'<=s[i] && s[i]<='Z')){
            if('a'<=s[i] && s[i]<='z') s[i]=s[i]-'a'+'A';
            if(!has[s[i]-'A']){
                insert(s[i]-'A');
            }
        }
    }
    fill();
//    Debug();
    gets(s);
    n = strlen(s);
    int a=-1,b=-1,c=0,cnt=0;
    for(int i=0;i<n;i++){
        if(('a'<=s[i] && s[i]<='z') || ('A'<=s[i] && s[i]<='Z')){
            if('a'<=s[i] && s[i]<='z') s[i]=s[i]-'a'+'A';
            if(a==-1){
                a=s[i]-'A';
                cnt++;
            }else if(b==-1){
                b=s[i]-'A';
                cnt++;
            }
            if(cnt>=2){
                if(a!=b){
                    gen(a,b);
                    a=b=-1;
                    cnt=0;
                }else{
                    while(a==c || c==9)c++;
                    c%=26;
                    gen(a,c);
                    a=b;
                    b=-1;
                    c++;
                    if(c==9)c++;
                    if(c>=26)c=0;
                    cnt=1;
                }
            }
        }
    }
    if(cnt==1){
        while(a==c || c==9)c++;
        c%=26;
        gen(a,c);
    }
}

int main()
{
//    freopen("data.in","r",stdin);
    int T;
    scanf("%d",&T);
    gets(s);
    for(int cas=1;cas<=T;cas++){
        printf("Case %d: ",cas);
        solve();
        putchar('\n');
    }
    return 0;
}
