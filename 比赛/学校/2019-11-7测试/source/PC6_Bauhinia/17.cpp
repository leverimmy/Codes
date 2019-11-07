#include <bits/stdc++.h>
#define rgi register int
#define fin(s) freopen(s,"r",stdin)
#define fout(s) freopen(s,"w",stdout)
using namespace std;
int n;
char s[1000005];
void dfs(int l,int r)
{
	if(l>=r)
		return;
	swap(s[l],s[r]);
	printf("%s\n",s);
	dfs(l+1,r-1);
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	fin("17.in"),fout("17.out");
	scanf("%d",&n);
	scanf("%s",s);
	dfs(0,n-1);
	printf("\n%s\n",s);
	return 0;
}

