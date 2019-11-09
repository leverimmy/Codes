#include <bits/stdc++.h>
#define rgi register int
using namespace std;
int n;
string s;
stack<int> stk;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n>>s;
	static int len,cnt,l,r;
	for(rgi i=0;i<n;++i)
		if(s[i]=='(')
			stk.push(i);
		else if(!stk.empty())
		{
			int k=stk.top();
			if(r==k-1)
			{
				len=max(len,i-k+r-l+2);
				r=i;
			}
			else
			{
				len=max(len,i-k+1);
				l=k,r=i;
			}
			stk.pop();
		}
	while(!stk.empty())
		stk.pop();
	l=0,r=0;
	for(rgi i=0;i<n;++i)
		if(s[i]=='(')
			stk.push(i);
		else if(!stk.empty())
		{
			int k=stk.top();
			if(r==k-1)
			{
				if(i-k+r-l+2==len)
					++cnt;
				r=i;
			}
			else
			{
				if(i-k+1==len)
					++cnt;
				l=k,r=i;
			}
			stk.pop();
		}
	cout<<len<<" "<<cnt<<endl;
	return 0;
}
