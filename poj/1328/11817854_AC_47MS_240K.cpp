#include<iostream>
#include<cmath>
#include<algorithm>
#define MAX 1001                            //我用1000貌似错了一次。。
using namespace std;

struct island
{
    double left;
    double right;
}islandRange[MAX];



int cmp(const void *a, const void *b)
{
    return (*(island*)a).left  > (*(island*)b).left? 1:-1;
   //如果写成这样“return ((island*)a)->left - ((island*)b)->left;"会出错，我不明白为什么！
}
//想明白了，上面出错因为double型发生隐式转换成int，故影响排序。

int main()
{
    int n, d;
    double tmp;
    int caseNum = 1;
    int min;
    int i;

    while(cin>>n>>d, n || d)
    {
        min = 1;
        for( i = 0; i < n; i++)  cin>>(islandRange[i].left)>>(islandRange[i].right);
        for(i = 0; i < n; i++)    
        {
               //cin>>(islandRange[i].left)>>(islandRange[i].right);   我用增加分母的方式证明了这样输入是会RE的     
            if(d > 0 && (d*d >= islandRange[i].right * islandRange[i].right))
            {
                tmp = sqrt((double)(d*d - islandRange[i].right * islandRange[i].right));
                islandRange[i].right = islandRange[i].left + tmp;
                islandRange[i].left = islandRange[i].left - tmp;
               
            }
            else break;
        }
       
        if(i < n) {cout<< "Case "<<caseNum++<<": -1"<<endl; continue;}
       
        qsort(islandRange, n, sizeof(islandRange[0]), cmp);
       
        double currentl = islandRange[0].left,  currentr = islandRange[0].right;
        for(int i = 1; i < n; i++)
        {
            if(islandRange[i].left > currentr)
            {
                currentr = islandRange[i].right;
                currentl = islandRange[i].left;
                min++;
            }
            else
            {
                if(currentl < islandRange[i].left)  currentl = islandRange[i].left;
                if(currentr > islandRange[i].right) currentr = islandRange[i].right;
            }
        }
            cout<<"Case "<<caseNum++<<": "<<min<<endl;
    }
    return 0;
}