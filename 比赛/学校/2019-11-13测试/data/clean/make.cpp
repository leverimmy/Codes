#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<cstdio>
using namespace std;

#define random(x) (rand()%x)
int main()
{
	freopen("clean15.in","w",stdout);
	srand((int)time(0));
	int len,n;
	cin>>len>>n;
	cout<<len<<" "<<n<<endl;
//	cout<<endl;
	while(n>0)
	{
		int i=random(len);
		int j=random(len);
		if(i<=j&&i>0)
		{
			cout<<i<<" "<<j<<endl;
			n--;
		}
	}
	return 0;
}
