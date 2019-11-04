#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	freopen("subscript.in","r",stdin);
	freopen("subscript.out","w",stdout);
	ios::sync_with_stdio(false);
	int T;
	char s[100001];
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		cin>>s;
		cout<<s;
	}
	return 0;
}