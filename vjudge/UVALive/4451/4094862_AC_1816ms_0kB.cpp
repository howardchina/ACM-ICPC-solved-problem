#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int UP = 0;
const int FLOOR = 1;
const int DOWN = 2;

int deck[33],n;

struct State{
    int card[8],type[8],hold[2];
    int pos,score;

    State child()const{
        State s;
        memcpy(&s,this,sizeof s);
        s.pos = pos+1;
        return s;
    }

    State(){
        for(int i=0;i<8;i++){
            card[i]=deck[i];
            type[i]=(i%2==0)?UP:DOWN;
        }
        hold[0]=hold[1]=score=0;
        pos=8;
    }

    bool isFinal(){
        if(pos==2*n){
            score += hold[0]+hold[1];
            hold[0]=hold[1]=0;
            return true;
        }
        return false;
    }

    int getScore(int c1,int c2,int c3)const{
        int S = abs(c1)+abs(c2)+abs(c3);
        int cnt=(c1>0) + (c2>0) + (c3>0);
        return cnt>1?S:-S;
    }

    void expand(int player, vector<State>& ret) const{
        int cur = deck[pos];

        if(hold[player]==0){
            State s = child();
            s.hold[player]=cur;
            ret.push_back(s);
        }

        for(int i=0;i<7;i++) if(type[i]==DOWN && type[i+1]==UP){
            State s=child();
            s.score += getScore(card[i],card[i+1],cur);
            s.type[i] = s.type[i+1] = FLOOR;
            s.card[i] = s.card[i+1] = cur;
            ret.push_back(s);

            if(hold[player]!=0){
                State s = child();
                s.score += getScore(card[i],card[i+1],hold[player]);
                s.type[i] = s.type[i+1] = FLOOR;
                s.card[i] = s.card[i+1] = hold[player];
                s.hold[player] = cur;
                ret.push_back(s);
            }
        }

        if(hold[player]!=0){
            for(int i=0;i<7;i++) if(type[i]==FLOOR && type[i+1]==FLOOR && card[i]==card[i+1]){
                State s = child();
                s.score += getScore(card[i],hold[player],cur);
                s.type[i] = UP; s.type[i+1] = DOWN;
                s.card[i] = cur; s.card[i+1] = hold[player]; s.hold[player] = 0;
                ret.push_back(s);

                swap(s.card[i],s.card[i+1]);
                ret.push_back(s);
            }
        }
    }
};

int alphabeta(State& s, int player, int alpha, int beta){
    if(s.isFinal()) return s.score;

    vector<State> children;
    s.expand(player,children);

    int n = children.size();
    for(int i=0;i<n;i++){
        int v = alphabeta(children[i],player^1, alpha, beta);
        if(!player) alpha = max(alpha,v);
        else beta = min(beta,v);
        if(beta <= alpha) break;
    }
    return !player? alpha : beta;
}

const int INF = 0x3f3f3f3f;

int main()
{
//    freopen("data.in","r",stdin);
    int cas=1,score;
    char s[10],c;
    while(scanf("%s",s)!=EOF && s[0]!='E'){
        scanf("%d",&n);
        for(int i=0;i<2*n;i++){
            scanf("%d%c",&deck[i],&c);
            if(c=='B') deck[i]=-deck[i];
        }
        State initial;
        int first_player = deck[0]>0?0:1;
        score = alphabeta(initial,first_player,-INF,INF);
        if(s[0]=='B') score = -score;
        printf("Case %d: ",cas++);
        if(score==0) {
            printf("Axel and Birgit tie\n");
        }else if(score > 0){
            printf("%s wins %d\n",s,score);
        }else{
            printf("%s loses %d\n",s,-score);
        }
    }
    return 0;
}
