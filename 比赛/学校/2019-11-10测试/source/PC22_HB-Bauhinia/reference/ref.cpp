#include <bits/stdc++.h>
#define rgi register int
#define di(ch) (ch-'a')
using namespace std;
int n,pos=-1;
string s;
vector<int> book[26];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>s;
	n=s.size();
	for(rgi i=0;i<n;++i)
		book[di(s[i])].push_back(i);
	for(rgi i=0;i<26;++i)
		if(book[i].size()&1)
		{
			if(~pos)
			{
				cout<<"Impossible"<<endl;
				return 0;
			}
			else
				pos=i;
		}
	for(rgi i=0)
	return 0;
}

