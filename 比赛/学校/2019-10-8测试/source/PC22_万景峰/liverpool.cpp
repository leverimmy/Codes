#include <iostream>
#include <cstdio>
#include <string>
#include <unordered_map>
#define ll long long
#define rgi register int
using namespace std;
int n,m,w,x;
unordered_map<string,int> s;
string name,y;
int main()
{
	ios::sync_with_stdio(false);
	freopen("liverpool.in","r",stdin);
	freopen("liverpool.out","w",stdout);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(rgi i=1;i<=n;++i)
	{
		cin>>name>>w;
		s.insert(make_pair(name,w+1));
	}
	for(cin>>m;m;--m)
	{
		bool flag=0;
		ll ans=0;
		cin>>x;
		for(rgi i=1;i<=x;++i)
		{
			cin>>y;
			unordered_map<string,int>::iterator it=s.find(y);
			if(it==s.end())
			{
				cout<<"-1"<<endl;
				flag=1;
				break;
			}
			ans+=(*it).second;
		}
		if(!flag)
		{
			if(ans)
				cout<<ans-x<<endl;
			else
				cout<<"-1"<<endl;
		}
	}
	return 0;
}
