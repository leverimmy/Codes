#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
int main()
{	
	freopen("expression10.in","w",stdout);
	srand(time(NULL));
	int n=200;
	cout<<n<<endl; 
	for(int i=1;i<=n+1;i++)cout<<1+(rand()*rand())%1000000<<" ";
	cout<<endl;
	for(int i=1;i<=n;i++)
	{
		int bj=rand()%3;
		if(bj==0)cout<<"& ";
		if(bj==1)cout<<"| ";
		if(bj==2)cout<<"^ ";
	}
	cout<<endl;
	for(int i=1;i<=n;i++)
	{
		int up=rand()%10000;
		printf("%.2lf ",(up*1.0)/10000);
	}
	return 0;
}

