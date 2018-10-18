#include <cstdio>
#include <cstring>

int a[111][2],n;
char s[111][4];

void solve(){
    int l=-1,r=-1;
    for(int i=1;i<=n;i++){
        if(s[i][0]!='?')l=i;
        a[i][0]=l;
    }
    for(int i=n;i>=1;i--){
        if(s[i][0]!='?')r=i;
        a[i][1]=r;
    }
}
void query(int p){
    int l=a[p][0],r=a[p][1];
    if(l==-1 || (r!=-1 && p-l>r-p)){
        l=p,r=a[p][1];
        for(;l<r;l++)
            printf("left of ");
        puts(s[r]);
    }else if(r==-1 || (l!=-1 && p-l<r-p)){
        l=a[p][0],r=p;
        for(;l<r;r--)
            printf("right of ");
        puts(s[l]);
    }else if(l==p){
        puts(s[p]);
    }else{
        printf("middle of %s and %s\n",s[l],s[r]);
    }
}
int main()
{
//    freopen("data.in","r",stdin);
    int q,x;
    while(scanf("%d",&n)!=EOF){
        gets(s[0]);
        for(int i=1;i<=n;i++)
            scanf("%s",s[i]);
        solve();
        scanf("%d",&q);
        while(q--){
            scanf("%d",&x);
            query(x);
        }
    }
    return 0;
}
