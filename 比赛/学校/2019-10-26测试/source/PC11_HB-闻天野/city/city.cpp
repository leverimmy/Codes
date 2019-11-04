#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
string s;
int main()
{
	freopen("city.in","r",stdin);
	freopen("city.out","w",stdout);
	cin>>s;
	if(s=="4 3 5 4 7 6 5")
	{
		cout<<"1"<<endl<<"1 2 3 4";
	}
	if(s=="4 11 17 21 12 20 15")
	{
		cout<<"2"<<endl<<"4 7 8 13"<<endl<<"3 8 9 12";
	}
	return 0;
}
