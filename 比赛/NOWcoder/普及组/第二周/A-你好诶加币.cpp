#include <cstdio>
#include <iostream>

using namespace std;

long long a,b,sum;

int main()
{
	cin>>a>>b;sum=a+b;
	if((a<0 && b<0 && sum>=0) || (a>0 && b>0 && sum<=0))
			cout<<"\""<<"hello, %lld\\n\"";
	else
		cout<<a+b;
	return 0;
}
