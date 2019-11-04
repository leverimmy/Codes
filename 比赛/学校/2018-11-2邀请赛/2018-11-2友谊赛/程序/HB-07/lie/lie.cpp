#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

const int N=100010;

typedef pair<int,int> pii;

struct Node
{
	int l,r,c;
	bool operator<(const Node& y) const
	{
		return r==y.r?l<y.l:r<y.r;
	}
} s[N];

int n,a,b,tot,f[N][2];
map<pii,int> w;

int main()
{
	freopen("lie.in","r",stdin);
	freopen("lie.out","w",stdout); 
	
	int i,p=0;
	
	scanf("%d",&n);
	
	for (i=0;i<n;++i)
	{
		scanf("%d%d",&a,&b);
		if (a+b>=n)
		{
			continue;
		}
		if (w.find(pii(b+1,n-a))==w.end())
		{
			w[pii(b+1,n-a)]=1;
		}
		else
		{
			if (w[pii(b+1,n-a)]<n-a-b)
			{
				++w[pii(b+1,n-a)];
			}
		}
	}
	
	s[0].l=0;
	s[0].r=0;
	s[0].c=0;
	
	for (map<pii,int>::iterator k=w.begin();k!=w.end();++k)
	{
		s[++tot].l=k->first.first;
		s[tot].r=k->first.second;
		s[tot].c=k->second;
	}
	
	sort(s+1,s+tot+1);
	
	for (i=1;i<=tot;++i)
	{
		f[i][0]=max(f[i-1][0],f[i-1][1]);
		while (p<i&&s[p+1].r<s[i].l)
		{
			++p;
		}
		f[i][1]=max(f[p][0],f[p][1])+s[i].c;
	}
	
	cout<<n-max(f[tot][0],f[tot][1]);
	
	return 0;
}
