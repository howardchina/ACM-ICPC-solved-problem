#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
const int maxn = 22;
int a[maxn],len[maxn],mp[33],flag[11],spj[33],maxlen,ans,n;
char s[maxn][maxn];

void Debug(){
    puts("");
    for(int i=0;i<26;i++){
        if(mp[i]>=0){
            printf("%c=%d ",'A'+i,mp[i]);
        }
    }
    puts("");
}

void dfs(int dep,int id,int sum){
//    if(sum>99) return;
    if(dep>=len[n-1]){
        if(sum==0){
            ans++;
//            Debug();
        }
        return;
    }
    if(id==n-1){
        int l = len[id];
        int c = s[id][l-1-dep]-'A';
        if(mp[c]==-1){
            for(int i=0;i<=9;i++){
                if(flag[i]>=0) continue;
                if(i==0 && spj[c]) continue;
                if(sum%10==i){
                    flag[i]=c;
                    mp[c]=i;
                    dfs(dep+1,0,sum/10);
                    mp[c]=-1;
                    flag[i]=-1;
                }
            }
        }else{
            if(sum%10==mp[c]){
                dfs(dep+1,0,sum/10);
            }
        }
        return;
    }

    int l = len[id];
    if(dep>=l){
        dfs(dep,id+1,sum);
        return;
    }
    int c = s[id][l-1-dep]-'A';
    if(mp[c]==-1){
        for(int i=0;i<=9;i++){
            if(flag[i]>=0) continue;
            if(i==0 && spj[c]) continue;
            flag[i]=c;
            mp[c]=i;
            dfs(dep,id+1,sum+i);
            mp[c]=-1;
            flag[i]=-1;
        }
    }else{
        dfs(dep,id+1,sum+mp[c]);
    }
}

int main()
{
//    freopen("data.in","r",stdin);
    while(scanf("%d",&n)!=EOF){
        memset(mp,-1,sizeof mp);
        memset(flag,-1,sizeof flag);
        memset(spj,0,sizeof spj);
        maxlen = 0;
        for(int i=0;i<n;i++){
            scanf("%s",s[i]);
            len[i] = strlen(s[i]);
            maxlen = max(maxlen,len[i]);
            spj[s[i][0]-'A']=1;
        }
        ans=0;
        dfs(0,0,0);
        printf("%d\n",ans);
//        return 0;
    }
    return 0;
}
