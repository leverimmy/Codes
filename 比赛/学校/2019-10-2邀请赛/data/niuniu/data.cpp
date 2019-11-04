#include<cstdlib>
#include<ctime>
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("niuniu5.in","w",stdout);
	srand(time(0));
	int T=100000;
	cout<<T<<endl;
	for(int i=1;i<=T;i++)
	{
		cout<<rand()%13+1<<' '<<rand()%13+1<<' '<<rand()%13+1<<' '<<rand()%13+1<<endl;
	}
	return 0;
}
