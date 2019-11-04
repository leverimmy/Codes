#include <iostream>
#include <cstdlib>
#include <ctime>
#define int unsigned long long
using namespace std;
int t;
signed main()
{
	ios::sync_with_stdio(false);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	srand((int)time(0)*(int)&main);
	cin>>t;
	for(;t;--t)
	{
		int r=rand()&1;
		if(r)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}
