#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
struct Node{
    char k[110];
    char v[110];
};
Node memo[110],memo2[110],a[110],d[110],c[110];
char str[110],tmp[110],tmp2[110];
int tot,tot2,aa,dd,cc;
bool cmp(Node a,Node b){
    return strcmp(a.k,b.k)<=0;
}
void read(Node *x,int &tt){
    tt=0;
    gets(str);
    int n=strlen(str),l,l2;
    for(int i=0;i<n;i++){
        if(str[i]!='}' && (str[i]<'a'||str[i]>'z'))continue;
        if(str[i]=='}')break;
        l=l2=0;
        while('a'<=str[i] && str[i]<='z'){
            tmp[l++]=str[i++];
        }
        tmp[l]='\0';
        strcpy(x[tt].k,tmp);
        i++;
        while('0'<=str[i] && str[i]<='9'){
            tmp2[l2++]=str[i++];
        }
        tmp2[l2]='\0';
        strcpy(x[tt++].v,tmp2);
    }
}
void gao(){
    sort(memo,memo+tot,cmp);
    sort(memo2,memo2+tot2,cmp);
    aa=dd=cc=0;
    int i,j;
    for(i=j=0;i<tot&&j<tot2;){
        int s=strcmp(memo[i].k,memo2[j].k);
        if(s==0){
            if(strcmp(memo[i].v,memo2[j].v)!=0)
                strcpy(c[cc++].k,memo[i].k);
            i++,j++;
        }else if(s==-1){
            strcpy(d[dd++].k,memo[i].k);
            i++;
        }else{
            strcpy(a[aa++].k,memo2[j].k);
            j++;
        }
    }
    if(i<tot){
        for(;i<tot;i++)
            strcpy(d[dd++].k,memo[i].k);
    }
    if(j<tot2){
        for(;j<tot2;j++)
            strcpy(a[aa++].k,memo2[j].k);
    }
}
void ot(){
    if(aa||dd||cc){
        if(aa){
            sort(a,a+aa,cmp);
            printf("+%s",a[0].k);
            for(int i=1;i<aa;i++)
                printf(",%s",a[i].k);
            putchar('\n');
        }
        if(dd){
            sort(d,d+dd,cmp);
            printf("-%s",d[0].k);
            for(int i=1;i<dd;i++)
                printf(",%s",d[i].k);
            putchar('\n');
        }
        if(cc){
            sort(c,c+cc,cmp);
            printf("*%s",c[0].k);
            for(int i=1;i<cc;i++)
                printf(",%s",c[i].k);
            putchar('\n');
        }
    }else
        puts("No changes");
    putchar('\n');
}
int main()
{
//    freopen("data.in","r",stdin);
    int T;
    scanf("%d",&T);
    gets(str);
    while(T--){
        read(memo,tot);
        read(memo2,tot2);
        gao();
        ot();
    }
    return 0;
}
