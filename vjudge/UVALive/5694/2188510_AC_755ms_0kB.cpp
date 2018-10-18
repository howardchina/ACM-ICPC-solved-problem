#include <iostream>
#include <set>
#include <stdio.h>
#include <algorithm>

using namespace std;
#define mp(a,b) make_pair(a,b)

typedef long long LL;

const int MAXN = 100010;
struct Edge{
	int h,l;
	int flag;
	friend bool operator < (const Edge &now,const Edge &other){
		if(now.flag!=other.flag)
			return now.flag > other.flag;
		else
			return now.l < other.l;
	}
};

int R[MAXN][4];
int X[MAXN];
int w,h,n,m;
set<Edge> S[MAXN];
set<Edge>::iterator it;
set<pair<int,int> > line;
set<pair<int,int> >::iterator its;
void getData(){
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<4;j++)
			scanf("%d",&R[i][j]);
}

LL run(){
	int i,j,idx;
	int ncnt=0;
	Edge now;
	for(i=0;i<n;i++){
		X[ncnt++] = R[i][0];
		X[ncnt++] = R[i][2];
	}
	X[ncnt++] = 1;
	X[ncnt++] = w;
	sort(X,X+ncnt);
	ncnt = unique(X,X+ncnt)-X;
	for(i=0;i<ncnt;i++ ) S[i].clear();
	for(i=0;i<n;i++){
		now.l = R[i][1];
		now.h = R[i][3];
		idx = lower_bound(X,X+ncnt,R[i][0]) - X;
		now.flag = 1;
		S[idx].insert(now);
		idx = lower_bound(X,X+ncnt,R[i][2]) - X;
		now.flag = -1;
		S[idx].insert(now);
	}
	line.clear();
	line.insert(mp(0,0));
	line.insert(mp(h+1,h+1));
	LL px = 1;
	LL base = h-m+1,sum=0,ll,hh,ts,wi,len;
	for(i=0;i<ncnt;i++){
		wi = X[i] - px - 1;//间隔
		px = X[i];
		if(wi>0)
			sum += wi*base;
		//bool mark = true;
		len = base;
		for(it=S[i].begin(); it != S[i].end(); it ++){
			now = *it;
			if(now.flag==1){//add edge
				line.insert(mp(now.l,now.h));
				its = line.find(mp(now.l,now.h));
				its --;
				ll = (*its).second;
				its ++; its ++;
				hh = (*its).first;
				ts = hh-ll-1;
				if(ts >= m){
					base -= (ts-m+1);
					ts = now.l - ll -1;
					if(ts >= m)
						base += (ts-m+1);
					ts = hh - now.h - 1;
					if(ts >= m)
						base += (ts-m+1);
				}
				len = base;
			} else {
				its = line.find(mp(now.l,now.h));
				its --;
				ll = (*its).second;
				its ++; its ++;
				hh = (*its).first;
				ts = hh-ll-1;
				if(ts >= m){
					base += (ts-m+1);
					ts = now.l - ll -1;
					if(ts >= m)
						base -= (ts-m+1);
					ts = hh - now.h - 1;
					if(ts >= m)
						base -= (ts-m+1);
				}
				line.erase(mp(now.l,now.h));
			}
		}
		sum += len;
	}
	return sum;
}

void rotate(){
	int i;
	swap(w,h);
	for(i=0;i<n;i++){
		swap(R[i][0],R[i][1]);
		swap(R[i][2],R[i][3]);
	}
}

int main(){
	while(scanf("%d%d%d%d",&w,&h,&n,&m)!=EOF){
		getData();
		LL ans = run();
		if(m!=1){
			rotate();
			ans += run();
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
3 3 3 2
2 2 2 2
3 1 3 1
3 2 3 2
*/