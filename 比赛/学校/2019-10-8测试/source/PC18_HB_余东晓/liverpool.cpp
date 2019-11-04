#include<cstdio>
#include<cstdlib>
#include<climits>
#include<cassert>
#include<cstring>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<iostream>
#include<stack>
#include<map>
#include<queue>
#include<vector>
#define ll long long
#define INF 0x3f3f3f3f
struct node
{
	bool end;
	int nxt[26];
}a[2000020];
int tot(0);
ll val[2000020];
void add(char* ch,int x)
{
	int i,p(0);
	for(i=0;ch[i];i++)
	{
		if(!a[p].nxt[ch[i]-'a'])
			a[p].nxt[ch[i]-'a']=++tot;
		p=a[p].nxt[ch[i]-'a'];
	}
	val[p]=x;
	a[p].end=1;
}
int qus(char* ch)
{
	int i,p(0);
	for(i=0;ch[i];i++)
	{
		if(!a[p].nxt[ch[i]-'a'])
			return -1;
		p=a[p].nxt[ch[i]-'a'];
	}
	if(!a[p].end)
		return -1;
	return val[p];
}
char ch[2000020];
signed main()
{
	freopen("liverpool.in","r",stdin);
	freopen("liverpool.out","w",stdout);
	memset(a,0,sizeof(a));
	int n,m;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		ll x;
		scanf("%s%lld",ch,&x);
		add(ch,x);
	}
	scanf("%d",&m);
	while(m--)
	{
		int k;
		ll ans(0);
		bool flg(0);
		scanf("%d",&k);
		while(k--)
		{
			scanf("%s",ch);
			if(flg)
				continue;
			ll p=qus(ch);
			if(p==-1)
			{
				ans=-1;
				flg=1;
				continue;
			}
			ans+=p;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
