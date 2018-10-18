#include<iostream>
#include<cstring>
#include<queue>
#include<stdio.h>
using namespace std;
struct la {
    int restf, lanum;
};
int f[28], d[28], t[28], lt[28], bestl[28];
bool operator < (const la &t1, const la &t2)
{
    if(t1.restf==t2.restf) return t1.lanum>t2.lanum;
    return t1.restf<t2.restf;
}
int main()
{
    int n, h, i, j, endt, nowt, totlef, bestf;
    while(cin>>n && n) {
        cin>>h;
        h*=12;
        for(i=0; i<n; i++) cin>>f[i];
        for(i=0; i<n; i++) cin>>d[i];
        for(i=1; i<n; i++) cin>>t[i];
        t[0]=endt=0;
        bestf=-1;
        for(i=0; i<n; i++) {
            endt+=t[i];
            if(endt>h) break;
            nowt=h-endt;
            priority_queue<la>q;
            la x;
            for(j=0; j<=i; j++) {
                x.restf=f[j]; x.lanum=j;
                q.push(x);
            }
            memset(lt, 0, sizeof(lt));
            totlef=0;
            while(nowt--) {
                x=q.top(); q.pop();
                lt[x.lanum]++;
                totlef+=x.restf;
                x.restf-=d[x.lanum];
                if(x.restf<0) x.restf=0;
                q.push(x);
            }
            if(totlef>bestf) {
                bestf=totlef;
                for(j=0; j<=i; j++) bestl[j]=lt[j];
                for(; j<n; j++) bestl[j]=0;
            }
        }
        cout<<bestl[0]*5;
        for(i=1; i<n; i++) cout<<", "<<bestl[i]*5;
        cout<<endl;
        cout<<"Number of fish expected: "<<bestf<<endl<<endl;
    }
    return 0;
}
