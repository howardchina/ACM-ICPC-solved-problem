#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    int x,y,cas=1;
    while(scanf("%d%d",&x,&y)!=EOF){
        int ans=0;
        for(int i=x;i<=y;i++){
            if((i*i*i+1-3)/10>y) break;
            for(int j=x;j<=y;j++){
                if((i*i*i+j*j*j-3)/10>y) break;
                int tmp=i*i*i+j*j*j;
                if(tmp%10==3 && x<=tmp/10 && tmp/10<=y)
                    ans++;
            }
        }
        printf("Case %d: %d\n",cas++,ans);
    }
    return 0;
}
