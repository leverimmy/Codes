#include <bits/stdc++.h>
#define rgi register int
#define pii pair<int,int>
#define mkp make_pair
#define fi first
#define se second
#define pb push_back
using namespace std;
int t,n;
string s;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	for(cin>>t;t;--t)
	{
		cin>>s;
		n=s.size();
		int ans1=0,ans2=0,cnt1,cnt2;
		rgi i,j;
		cnt1=0,cnt2=0;
		for(i=0,j=n-1;i<=j;++i,--j)
		{
			if(i==j&&s[i]=='B')
			{
				ans1+=min(cnt1,cnt2);
				break;
			}
			if(s[i]=='R')
				while(s[i]=='R')
					++cnt1,++i;
			else
				ans1+=cnt1;
			if(s[j]=='R')
				while(s[j]=='R')
					++cnt2,--j;
			else
				ans1+=cnt2;
		}
		cnt1=0,cnt2=0;
		for(i=0,j=n-1;i<=j;++i,--j)
		{
			if(i==j&&s[i]=='R')
			{
				ans2+=min(cnt1,cnt2);
				break;
			}
			if(s[i]=='B')
				while(s[i]=='B')
					++cnt1,++i;
			else
				ans1+=cnt1;
			if(s[j]=='B')
				while(s[j]=='B')
					++cnt2,--j;
			else
				ans1+=cnt2;
		}
		cout<<min(ans1,ans2)<<endl;
	}
	return 0;
}

