#include<iostream>
#include<cstdio>
#include<vector>
#include <string.h>
//#define end(x,y,z) (!((x == 0) && (y == 0) && (z == 0)))
#define MAXN 10005
using namespace std;
int prime[MAXN];
int fir,sec,d;
bool vis[MAXN];
vector<int> SUM;
vector<int> data;

bool dfs(int cnt, int sum)
{
  if (cnt >= 2) {
    for (int i(2); i<=min(cnt,d); ++i) {
      int temp = SUM[SUM.size()-i-1];
      if (!prime[sum - temp])return false;
    }
  }
  if (cnt == sec - fir + 1)return true;
  for (int i(fir); i<=sec; ++i) {
    if (!vis[i]) {
      vis[i] = true;
      int temp = sum + i;
      SUM.push_back(temp);
      data.push_back(i);
      if (dfs(cnt+1,temp)) {
        return true;
      } else {
        data.pop_back();
        SUM.pop_back();
      }
      vis[i] = false;
    }
  }
  return false;
}

int main()
{
   // freopen("test.in","r",stdin);
  for (int i(2); i<MAXN; ++i) {
    if (!prime[i]) {
      for (int j(i*i); j<MAXN; j += i)prime[j] = 1;
    }
  }
  while (scanf("%d%d%d",&fir,&sec,&d)) {
    if (fir == 0 && sec == 0 && d == 0)break;
    memset(vis,false,sizeof(vis));
    SUM.clear();
    data.clear();
    SUM.push_back(0);
    if (dfs(0,0)) {
      cout<<data[0];
      for (int i(1); i<data.size(); ++i) {
        cout<<","<<data[i];
      }
      cout<<endl;
    } else {
      cout<<"No anti-prime sequence exists."<<endl;
    }
  }
  return 0;
}
