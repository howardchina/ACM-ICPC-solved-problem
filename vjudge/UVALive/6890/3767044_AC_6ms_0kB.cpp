#include<stdio.h>
#include<string.h>
#include<set>
#include<map>
#include <vector>
#include<algorithm>
using namespace std;
const int maxn = 555;
const int INF = 1000000007;
#define MP make_pair
#define x first
#define y second
#define pb push_back
typedef pair<int,int> pii;
typedef vector<int> vi;
pii a[maxn],b[maxn];
vi X,Y;

void Debug(pii a[maxn],int n,int sft){
    for(int i=0;i<n;i++){
        printf("%d %d ",a[(i+sft)%n].x,a[(i+sft)%n].y);
    }
    printf("\n");
}

void Input(pii a[maxn],int n){
    X.clear();
    Y.clear();
    for(int i=0;i<n;i++){
        scanf("%d%d",&a[i].x,&a[i].y);
        X.pb(a[i].x);
        Y.pb(a[i].y);
    }
    sort(X.begin(),X.end());
    sort(Y.begin(),Y.end());
    X.resize(unique(X.begin(),X.end())-X.begin());
    Y.resize(unique(Y.begin(),Y.end())-Y.begin());
    for(int i=0;i<n;i++){
        a[i].x = lower_bound(X.begin(),X.end(),a[i].x)-X.begin();
        a[i].y = lower_bound(Y.begin(),Y.end(),a[i].y)-Y.begin();
    }
//    Debug(a,n,0);
}

void rotate(pii a[maxn],int n){
    int W=0,H=0,M,minx,miny;
    for(int i=0;i<n;i++){
        W=max(W,a[i].x);
        H=max(H,a[i].y);
    }
    M=max(W,H);
    minx=INF,miny=INF;
    for(int i=0;i<n;i++){
        int tmp=a[i].x;
        a[i].x=a[i].y;
        a[i].y=M-tmp;
        minx = min(minx,a[i].x);
        miny = min(miny,a[i].y);
    }
    if(minx || miny){
        for(int i=0;i<n;i++){
            a[i].x-=minx;
            a[i].y-=miny;
        }
    }
}

void Solve(int na,int nb){
    int ans=0,n;
    if(na==nb){
        n=na;
        int fst[4]={0};
        for(int i=0;i<n;i++){
            if(a[i].x>a[fst[1]].x || (a[i].x==a[fst[1]].x && a[i].y<=a[fst[1]].y)){
                fst[1]=i;
            }
            if((a[i].x>=a[fst[2]].x && a[i].y>a[fst[2]].y) || a[i].y>a[fst[2]].y){
                fst[2]=i;
            }
            if(a[i].x<a[fst[3]].x || (a[i].x==a[fst[3]].x && a[i].y>=a[fst[3]].y)){
                fst[3]=i;
            }
        }


        for(int i=0;i<4;i++){
//            Debug(a,n,i);
            int ok=1;
            for(int j=0;j<n;j++){
                if(a[(j+fst[i])%n]!=b[j]){
                    ok=0;
                    break;
                }
            }
            if(ok){
                ans=ok;
                break;
            }else if(i!=3){
                rotate(a,n);
            }
        }
    }
    printf("%s\n",ans?"yes":"no");
}

int main(){
//    freopen("data.in","r",stdin);
    int na,nb;
	while(scanf("%d",&na)!=EOF){
	    Input(a,na);
	    scanf("%d",&nb);
	    Input(b,nb);
	    Solve(na,nb);
	}
	return 0;
}
