#include <bits/stdc++.h>
#define rgi register int
using namespace std;
int n;
priority_queue<int> que;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("9.in","r",stdin);
	freopen("9.out","w",stdout);
	cin>>n;
	for(;n;--n)
	{
		int op;
		cin>>op;
		if(op==1)
		{
			int x;
			cin>>x;
			que.push(x);
		}
		else
		{
			if(que.empty())
				cout<<"-1"<<endl;
			else
			{
				cout<<que.top()<<endl;
				que.pop();
			}
		}
	}
	return 0;
}

