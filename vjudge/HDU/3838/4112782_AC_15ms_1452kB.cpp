#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int solve(int P,int Q,int R,int X,int Y,int Z){
    int a[]={P,Q,R};
    int b[]={X,Y,Z};
    vector<int> ans;
    for(int i=0;i<3;i++){
        int P = a[i],Q = a[(i+1)%3];
        int X = b[i],Y = b[(i+1)%3];
        if(P==Q){
            if(X!=Y){
                return 0;
            }
        }else if((X-Y)%(P-Q)){
            return 0;
        }else{
            ans.push_back((X-Y)/(P-Q));
        }
    }
    if(ans.empty()) return 2;
    sort(ans.begin(),ans.end());
    if(ans[0]!=ans.back() || ans[0]==0) return 0;
    return 1;
}

int x[3],y[3],x2[3],y2[3],ix[3],iy[3];

int main(){
//    freopen("data.in","r",stdin);
    int cas=0;
    for(;;){
        int ok=0;
        for(int i=0;i<3;i++){
            scanf("%d%d",&x[i],&y[i]);
            if(x[i]||y[i]) ok=1;
        }
        if(!ok)break;
        for(int i=0;i<3;i++){
            scanf("%d%d",&x2[i],&y2[i]);
        }
        int ans=0;
        for(int i=0;i<40;i++){
            int rx,ry;
            if(i<20){rx=10; ry=i-10;}
            else {rx=30-i; ry=10;}

            double len = sqrt(rx*rx+ry*ry);
            double cosa = rx/len;
            double sina = ry/len;

            for(int j=0;j<3;j++){
                ix[j] = (int)floor(x[j]*cosa-y[j]*sina+0.5);
                iy[j] = (int)floor(x[j]*sina+y[j]*cosa+0.5);
            }

            int p[3]={0,1,2};
            do{
                int cnt1=solve(ix[0],ix[1],ix[2],x2[p[0]],x2[p[1]],x2[p[2]]);
                int cnt2=solve(iy[0],iy[1],iy[2],y2[p[0]],y2[p[1]],y2[p[2]]);
                ans+=cnt1*cnt2;
            }while(next_permutation(p,p+3));
        }
        printf("Case %d: ",++cas);
        if(ans==0) puts("no solution");
        else if(ans==1) puts("equivalent solutions");
        else puts("inconsistent solutions");
    }


}
