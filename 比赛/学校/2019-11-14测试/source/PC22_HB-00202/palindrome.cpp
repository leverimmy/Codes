#include <bits/stdc++.h>
#define rgi register int
#define ll long long
#define pii pair<int,int>
#define mkp make_pair
#define fi first
#define se second
#define pb push_back
using namespace std;
const int maxn=5005;
int n,ans[maxn];
string s;
map<string,pii> mp;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("palindrome.in","r",stdin);
	freopen("palindrome.out","w",stdout);
	cin>>s;
	n=s.size();
	for(rgi len=0;len<n;++len)
	{
		for(rgi i=0;i<n;++i)
		{
			rgi j=i+len,k=i,l=j;
			if(j>=n)
				break;
			bool flag=0;
			for(;k<l;++k,--l)
				if(s[k]!=s[l])
				{
					flag=1;
					break;
				}
			if(flag)
				continue;
			string tmp=s.substr(i,len+1);
			map<string,pii>::iterator it=mp.find(tmp);
			if(len==0)
			{
				mp.insert(mkp(tmp,mkp(1,1)));
				if(it==mp.end())
					mp.insert(mkp(tmp,mkp(1,1)));
				else
					mp[tmp]=mkp(1,(*it).se.se+1);
				continue;
			}
			--k,++l;
			string tmp1=s.substr(i,k-i+1),tmp2=s.substr(l,j-l+1);
			//cout<<tmp1<<" "<<tmp2<<endl;
			if(tmp1!=tmp2)//Íêµ° 
			{
				if(it==mp.end())
					mp.insert(mkp(tmp,mkp(1,1)));
				else
					mp[tmp]=mkp(1,(*it).se.se+1);
				continue;
			}
			map<string,pii>::iterator it1=mp.find(tmp1);
			if(it1==mp.end())//Íêµ° 
			{
				if(it==mp.end())
					mp.insert(mkp(tmp,mkp(1,1)));
				else
					mp[tmp]=mkp(1,(*it).se.se+1);
				continue;
			}
			if(it==mp.end())
				mp.insert(mkp(tmp,mkp((*it1).se.fi+1,1)));
			else
				mp[tmp]=mkp((*it1).se.fi+1,(*it).se.se+1);
		}
	}
	for(map<string,pii>::iterator it=mp.begin();it!=mp.end();++it)
	{
		//cout<<(*it).fi<<" "<<(*it).se.fi<<" "<<(*it).se.se<<endl;
		ans[(*it).se.fi]+=(*it).se.se;
	}
	reverse(ans+1,ans+n+1);
	for(rgi i=1;i<=n;++i)
		ans[i]+=ans[i-1];
	reverse(ans+1,ans+n+1); 
	for(rgi i=1;i<=n;++i)
		cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}

