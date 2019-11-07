#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
#define int long long
int n;
vector<int>ans;
void dfs(int x)
{
	if(x==n+1)
	{
		for(int i=0;i<ans.size();i++)
			printf("%c",'A'+ans[i]-1);
		exit(0);
	}
	vector<int>v;
	for(int i=0;i<ans.size();i++)
		v.push_back(ans[i]);
	v.push_back(x);
	for(int i=0;i<ans.size();i++)
		v.push_back(ans[i]);
		swap(v,ans);
	dfs(x+1);
}
signed main()
{
	freopen("6.in","r",stdin);
	freopen("6.out","w",stdout);
	scanf("%d",&n);
	dfs(1);
	return 0;
}