#include<bits/stdc++.h>
using namespace std;
unsigned long long hsh[30001],prod[30001];
char s[30001];
int get_hash(int l,int r)
{
	return (hsh[r]-hsh[l-1])*prod[30000-l];
}
const int base=29;
vector<int>v[27];
signed main()
{
	freopen("duplicate.in","r",stdin);
	freopen("duplicate.out","w",stdout);
	int T;
	scanf("%d",&T);
	prod[0]=1;
	for(int i=1;i<=30000;i++)
		prod[i]=prod[i-1]*base;
	while(T--)
	{
		int n;
		scanf("%d",&n);
		cin>>s+1;
		for(int i=0;i<26;i++)
			v[i].clear();
		for(int i=1;i<=n;i++)
			hsh[i]=hsh[i-1]*base+s[i]-'a';
		for(int i=1;i<=n;i++)
			v[s[i]-'a'].push_back(i);
		int ans=0;
		for(int i=0;i<26;i++)
		{
			for(int j=0;j<v[i].size();j++)
				for(int k=j+1;k<v[i].size();k++)
					if(get_hash(v[i][j],v[i][k]-1)==get_hash(v[i][k],2*v[i][k]-1-v[i][j]))
						ans++;
		}
		printf("%lld\n",1ll*(n/2)*(n/2+1)/2+1ll*((n-1)/2+1)*((n-1)/2)/2-ans);
	}
	return 0;
}
/*
1
10
ababcbabca
*/