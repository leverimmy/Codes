#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
char s[100005];
signed main()
{
	freopen("lcp.in","r",stdin);
	freopen("lcp.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s);
	string str(s);
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(str.substr(a-1)<str.substr(b-1)) printf("0\n");
		else printf("1\n");
	}
	return 0;
}
