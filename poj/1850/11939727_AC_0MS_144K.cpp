#include <stdio.h>
typedef unsigned long long ull;
ull C(int n,int k)
{
    ull re=1,temp=1;
    for(int i=0; i<k; i++){
        re*=n-i;
        if(re%(i+1)) re/=(i+1);
        else temp*=(i+1);
    }
    return re/temp;
}
int main()
{
//    freopen("test.in","r",stdin);
    char str[11];
    int cm[130];
    for(int i=0;i<26;i++)
        cm[i+'a']=i+1;
    scanf("%s",str);
    int len=0;
    ull ans=0;
    while(str[len]!='\0'){
        if(len && str[len]<=str[len-1]){
            puts("0");
            return 0;
        }
        len++;
    }
    for(int i=0;i<len;i++){
        ans+=C(26,i);
        if(i==0){
            for(int j=1; j<cm[str[0]]; j++){
                ans+=C(26-j,len-i-1);
            }
        }else{
            for(int j=cm[str[i-1]]+1; j<cm[str[i]]; j++){
                ans+=C(26-j,len-i-1);
            }
        }
    }
    printf("%I64d\n",ans);
    return 0;
}
