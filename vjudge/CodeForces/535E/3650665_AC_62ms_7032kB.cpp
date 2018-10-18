#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;
typedef unsigned long long LL;
const int maxs = 100001;
const int maxn = 200001;
const double eps = 1e-22;
int s[maxs];
vector<int>id[maxs];
int pointid[maxs];
int memid[maxs];
int ans[maxn];
pair<int,int>point[maxs];
pair<int,int>ch[maxs];

double Cross(double x1,double y1,double x2,double y2){
    return x1*y2-y1*x2;
}

int main(){
//    freopen("data.in","r",stdin);
//    freopen("data1.out","w",stdout);
    int n;
    scanf("%d",&n);
    int si,ri;
    for(int i=1;i<=n;i++){
        scanf("%d%d",&si,&ri);
        if(s[si]<ri){
            s[si]=ri;
            id[si].clear();
            id[si].push_back(i);
        }else if(s[si]==ri){
            id[si].push_back(i);
        }
    }
    int maxr = 0,cnt=0;
    point[cnt].first = 0;
    point[cnt++].second = 0;
    for(int i=maxs;i>=1;i--){
        if(s[i]){
            if(s[i]>maxr){
                maxr = s[i];
                pointid[cnt]=i;
                point[cnt].first = i;
                point[cnt++].second = s[i];
            }
        }
    }

    int m=0;
    double tmp;
    for(int i=0;i<cnt;i++){
        while(m>1 && (tmp = Cross(1.0/(eps+ch[m-1].first)-1.0/(eps+ch[m-2].first), 1.0/(eps+ch[m-1].second)-1.0/(eps+ch[m-2].second),
                           1.0/(eps+point[i].first)-1.0/(eps+ch[m-2].first), 1.0/(eps+point[i].second)-1.0/(eps+ch[m-2].second))) < -eps) {
            m--;
        }
        ch[m]=point[i];
        memid[m++]=pointid[i];
    }
    int tot = 0;
    for(int i=1;i<m;i++){
        for(int j=id[memid[i]].size()-1; j>=0; j--){
            ans[tot++]=id[memid[i]][j];
        }
    }
    sort(ans,ans+tot);
    for(int i=0;i<tot;i++){
        printf("%d%c",ans[i],i!=tot-1?' ':'\n');
    }

    return 0;
}
