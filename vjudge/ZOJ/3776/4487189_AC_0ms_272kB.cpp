#include <iostream>

using namespace std;

int main()
{
    int T;
    cin>>T;
    int n, m;
    while(T--){
        cin>>n>>m;
        int a = 0, b = 0, x;
        for(int i=0;i<n;i++){
            cin>>x;
            a += x;
        }
        for(int i=0;i<m;i++){
            cin>>x;
            b += x;
        }
        if (a > b){
            cout<<"Calem"<<endl;
        }
        else if (a < b){
            cout<<"Serena"<<endl;
        }
        else{
            cout<<"Draw"<<endl;
        }
    }
    return 0;
}
