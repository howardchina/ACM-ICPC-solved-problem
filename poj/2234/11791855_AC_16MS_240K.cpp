#include <iostream>
using namespace std;

int main()
{

	int M;
	while(cin>>M)
	{
		/*input*/
		int pile[20] ={};
		for(int i=0; i<M; ++i)
		{	cin>>pile[i];	}

		/*calculate*/
		int result   = 0;
		for(int i=0; i<M; ++i)
		{	result ^= pile[i];	}

		/*output*/
		if(result)cout<<"Yes"<<endl;
		else      cout<<"No" <<endl;
	}

	return 0;
}