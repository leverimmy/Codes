#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
int a[101][101];
int n;
char s[101];
void dfs(int l,int r)
{
	if(l==r||l>r)
	{
		cout<<endl;
		cout<<s+1;
		exit(0);
	}
	swap(s[l],s[r]);
	cout<<s+1<<endl;
	dfs(l+1,r-1);
}
signed main()
{
	freopen("17.in","r",stdin);
	freopen("17.out","w",stdout);
	cin>>n>>s+1;
	dfs(1,n);
	return 0;
}