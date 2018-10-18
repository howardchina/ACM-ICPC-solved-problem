#include <stdio.h>
#include <string.h>
#define max(x,y) ((x>y)?x:y)
struct Node{
    int i,child[205],val[2],cnt;
    char name[105],fa[105];
}tree[205];
bool dup[205][2];
void DP(int x)
{
    tree[x].val[0]=0;
    tree[x].val[1]=1;
    dup[x][0] = dup[x][1] =1;
    int i,id;
    for(i=0;i<tree[x].cnt;i++){
        id = tree[x].child[i];
        tree[x].val[0]+=max(tree[id].val[0],tree[id].val[1]);
        tree[x].val[1]+=tree[id].val[0];
    }
    for(i=0;i<tree[x].cnt;i++){
        id = tree[x].child[i];
        if( ( tree[id].val[0]>tree[id].val[1] && dup[id][0]==0 )
        ||( tree[id].val[0] < tree[id].val[1] && dup[id][1]==0 )
           || tree[id].val[0]==tree[id].val[1] ){
            dup[x][0]=0;
        }
        if(dup[id][0]==0){
            dup[x][1]=0;
        }
    }
}

int main()
{
    int i,j,n;
    while(~(scanf("%d",&n))){
        if(n==0)break;
        memset(tree,0,sizeof(tree));
        scanf("%s", tree[0].name);
        for(i=1;i<n;i++){
            scanf("%s %s", tree[i].name, tree[i].fa);
        }
        for(i=1;i<n;i++){
            for(j=0;j<n;j++){
                if(!strcmp(tree[i].fa,tree[j].name)){
                    tree[j].child[tree[j].cnt++]=i;
                    continue;
                }

            }
        }
        for(i=n-1;i>=0;i--){
            DP(i);
        }
        printf("%d ", max(tree[0].val[0],tree[0].val[1]));
        if((tree[0].val[0]>tree[0].val[1] && dup[0][0])
        || (tree[0].val[0]<tree[0].val[1] && dup[0][1])){
            puts("Yes");
        }else{
            puts("No");
        }
    }
}
