#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<climits>
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
char ch[1000010],u;
struct node
{
	bool v;
	int l,S,P;
}a[1000010];
signed main()
{
	freopen("sushi.in","r",stdin);
	freopen("sushi.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n(0);
		while(!isalpha(u))
			u=getchar();
		while(isalpha(u))
		{
			ch[++n]=u;
			u=getchar();
		}
		int u(1),m(0);
		while(u<n+1)
		{
			int p(u);
			while(ch[u]==ch[p])
				p++;
			a[++m].l=p-u;
			a[m].v=ch[u]=='B';
			u=p;
		}
		int ans(INF),ans1(0),ans2(0);
		for(int i=1;i<=m;i++)
			a[i].S=a[i-1].l+a[i-2].S;
		for(int i=m;i>=1;i--)
			a[i].P=a[i+1].l+a[i+2].P;
		for(int i=1;i<=m;i++)
			if(a[i].v)
				ans1+=a[i].l*std::min(a[i].S,a[i].P);
			else
				ans2+=a[i].l*std::min(a[i].S,a[i].P);
		printf("%d\n",std::min(ans,std::min(ans1,ans2)));
	}
	return 0;
}
