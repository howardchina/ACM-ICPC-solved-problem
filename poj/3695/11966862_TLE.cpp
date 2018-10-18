#include <stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
struct Rec{
    int x,y,_x,_y,area;
}rec[25];
int a[25];
int sta[1<<20];
int sb;
int main()
{
//    freopen("test.in","r",stdin);
    int i,j,k,n,m,L,r,sum,b,kase=1,que;
    bool flag;
    Rec tmp;
    while(scanf("%d%d",&n,&m)){
        if(n==0&&m==0)break;
        L=0;
        while(n--){
            scanf("%d%d%d%d",&rec[L].x,&rec[L].y,&rec[L]._x,&rec[L]._y);
            L++;
        }
        que=1;
        printf("Case %d:\n",kase++);
        while(m--){
            scanf("%d",&r);
            for(i=0;i<r;i++) scanf("%d",&a[i]);
            sum=0;sb=0;
            for(i=1; i<(1<<r); i++){
                flag=true;
                for(k=0; k<sb; k++){
                    if(i&sta[k]){
                        flag=false;
                        break;
                    }
                }
                if(!flag)continue;
                tmp.area=0;b=0;
                for(j=0; j<r; j++){
                    if((1<<j)&i){
                        if(b==0){
                            tmp=rec[j];
                            tmp.area=(tmp._x-tmp.x)*(tmp._y-tmp.y);
                            b++;
                        }else{
                            tmp.x=max(tmp.x,rec[j].x);
                            tmp.y=max(tmp.y,rec[j].y);
                            tmp._x=min(tmp._x,rec[j]._x);
                            tmp._y=min(tmp._y,rec[j]._y);
                            if(tmp.x>=tmp._x||tmp.y>=tmp._y)tmp.area=0;
                            else tmp.area=(tmp._x-tmp.x)*(tmp._y-tmp.y);
                            b++;
                        }
                        if(!tmp.area){
                            sta[sb++]=i;
                            break;
                        }
                    }
                }
                if(tmp.area){
                    if(b&1){
                        sum+=tmp.area;
                    }else{
                        sum-=tmp.area;
                    }
                }
            }
            printf("Query %d: %d\n",que++,sum);
        }
        puts("");
    }
    return 0;
}
