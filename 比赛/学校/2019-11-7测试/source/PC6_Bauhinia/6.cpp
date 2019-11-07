#include <bits/stdc++.h>
#define rgi register int
#define fin(s) freopen(s,"r",stdin)
#define fout(s) freopen(s,"w",stdout)
using namespace std;
int n;
string s="A";
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	fin("6.in"),fout("6.out");
	cin>>n;
	if(n==1)
	{
		cout<<s<<endl;
		return 0;
	}
	for(rgi i=2;i<=n;++i)
	{
		string t=s;
		s.push_back(i+'A'-1);
		s.append(t);
	}
	cout<<s<<endl;
	return 0;
}

