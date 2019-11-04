#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int T;
string s;

int main()
{	
	freopen("subscript.in","r",stdin);
	freopen("subscript.out","w",stdout);
	cin>>T;
	while(T--)
	{
		getline(cin,s);
		cout<<s<<endl;
	} 
	return 0;
}
