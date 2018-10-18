#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char** argv) {

    int n,h,i,f[26],d[26],t[26],time[26],tem[26],temt[26],j,max,max1,maxi,t1,flag,sum,left1,left;
    while(scanf("%d",&n)&&n)
    {
        max1=0;
        left=0;
        scanf("%d",&h);
        h=h*60/5;
        for(i=0;i<n;++i)
        {
            scanf("%d",&f[i]);
        }
        for(i=0;i<n;++i)
        {
            scanf("%d",&d[i]);
        }
        for(i=1;i<n;++i)
        {
            scanf("%d",&t[i]);
        }//输入
        t[0]=0;

        max1=-1;
        for(i=0;i<n;++i)//枚举第i个湖
        {
            left1=0;
            memset(temt,0,sizeof(temt));
            sum=0;
            if(h>=t[i])
            h-=t[i];
            else
                break;
            t1=h;
            for(j=0;j<=i;j++)
            {
                tem[j]=f[j];
            }
            while(t1>0)
            {
                maxi=0;
                flag=1;
            for(j=0;j<=i;++j)
            {

                if(maxi<tem[j])
                {
                    max=j;
                    maxi=tem[j];
                    flag=0;
                }
            }
            if(flag!=0)
            {
                left1=t1;
                break;
            }
            t1--;
            temt[max]++;//选出最大值，记录时间
            sum+=tem[max];
            if(d[max]>tem[max])
                tem[max]=0;
            else
                tem[max]-=d[max];

            }
            if(sum>max1)
            {
                max1=sum;
                left=left1;
                for(j=0;j<26;++j)
                {
                    time[j]=temt[j];
                }
            }
        }
        time[0]=time[0]+left;
        for(j=0;j<n-1;j++)
            printf("%d, ",time[j]*5);
        printf("%d\n",time[j]*5);
        printf("Number of fish expected: %d\n\n",max1);//输出，注意格式
    }
    return (EXIT_SUCCESS);
}
