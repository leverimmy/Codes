#include<cstdio>
#include<cstring>
#include<cassert>
#include<climits>
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
char ch[10010];
signed main()
{
	freopen("17.in","r",stdin);
	freopen("17.out","w",stdout);
	int id;
	while(~scanf("%s%d",ch,&id))
	{
		int n;
		scanf("%d%s",&n,ch);
		for(int i=1;i<=n/2;i++)
		{
			std::swap(ch[i-1],ch[n-i]);
			std::cout<<ch<<std::endl;
		}
		if(n%2)
			std::cout<<ch<<std::endl;
	}
	return 0;
}
