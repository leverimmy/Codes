#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<climits>
#include<cassert>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<iostream>
#include<map>
#include<stack>
#include<vector>
#include<queue>
#include<list>
#define ll long long
#define INF 0x3f3f3f3f
char v[1000010];
std::stack<int>s;
int a[1000010],S[1000010];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	scanf("%d%s",&n,v+1);
	for(int i=1;i<=n;i++)
	{
		a[i]=v[i]=='(';
		S[i]=a[i]+S[i-1];
	}
	int l(0),r(0),ans(0),cnt(0),u(0);
	bool flg(0);
	while(u<=n)
	{
		loopf:
		if(flg)
			l=r=0;
		u++;
		if(a[u])
			s.push(u);
		else
		{
			if(s.empty())
			{
				while(!a[u+1])
					u++;
				flg=1;
				goto loopf;
			}
			int p=s.top();
			s.pop();
			if(!l||!r||(p<l&&u>r))
			{
				l=p;
				r=u;
			}
			else
				r=u;
			int len=r-l+1;
			if(len==ans)
				cnt++;
			if(len>ans)
			{
				ans=len;
				cnt=1;
			}
		}
	}
	return!printf("%d %d\n",ans,cnt);
}
