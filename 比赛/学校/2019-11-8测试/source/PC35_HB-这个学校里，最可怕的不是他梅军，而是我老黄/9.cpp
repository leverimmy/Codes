#include<cstdio>
#include<cstring>
#include<climits>
#include<cassert>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<iostream>
#include<map>
#include<stack>
#include<queue>
#include<vector>
#define ll long long
#define INF 0x3f3f3f3f
std::priority_queue<int>q;
signed main()
{
	freopen("9.in","r",stdin);
	freopen("9.out","w",stdout);
	int m;
	scanf("%d",&m);
	while(m--)
	{
		int opt;
		scanf("%d",&opt);
		if(opt==1)
		{
			int x;
			scanf("%d",&x);
			q.push(x);
		}
		if(opt==2)
		{
			int ans(-1);
			if(!q.empty())
			{
				ans=q.top();
				q.pop();
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
