#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
//    freopen("data.in", "r", stdin);
    int T;
    scanf("%d", &T);
    char a[5][2]; int num[5];
    int q[5]; char b[5];
    while(T--){
        scanf("%d%s%d%s%d", &num[0], a[1], &num[2], a[3], &num[4]);
        int p1 = 0, p2 = 0;
        for(int i=0;i<5;i++){
            if (i&1){
                b[++p2] = a[i][0];
            }
            else{
                if (!p2 || b[p2] == '+' || b[p2] == '-'){
                    q[++p1] = num[i];
                }
                else{
                    if (b[p2] == '*'){
                        q[p1] = q[p1] * num[i];
                        p2--;
                    }
                    else if (b[p2] == '/'){
                        q[p1] = q[p1] / num[i];
                        p2--;
                    }
                    else if (b[p2] == '%'){
                        q[p1] = q[p1] % num[i];
                        p2--;
                    }
                }
            }
        }
        int sum = q[1];
        for (int i=2, j = 1; i <= p1 && j <= p2; i++, j++){
            if (b[j] == '+'){
                sum = sum + q[i];
            }
            else{
                sum = sum - q[i];
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}
