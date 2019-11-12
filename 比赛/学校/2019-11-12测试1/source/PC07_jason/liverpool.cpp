#include<bits/stdc++.h>
using namespace std;
char s[100001];
unsigned long long hash(char s[])
{
	unsigned long long h=0;
	int n=strlen(s+1);
	for(int i=1;i<=n;i++)
		h=(h+512+s[i])*29;
	return h;
}
map<unsigned long long,int>mp;
signed main()
{
	freopen("liverpool.in","r",stdin);
	freopen("liverpool.out","w",stdout);
	int n,T;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>s+1;
		scanf("%d",&x);
		mp[hash(s)]=x;
	}
	scanf("%d",&T);
	while(T--)
	{
		int m;
		long long ans=0;
		scanf("%d",&m);
		for(int i=1;i<=m;i++)
		{
			cin>>s+1;
			int h=hash(s);
			if(!mp[h]) 
				ans=-1;
			if(ans!=-1)
				ans+=mp[h];
		}
		printf("%lld\n",ans);
	}	
	return 0;
}
