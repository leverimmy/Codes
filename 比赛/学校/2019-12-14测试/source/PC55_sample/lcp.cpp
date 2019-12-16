#include <bits/stdc++.h>
#define int unsigned
#define rgi register unsigned
#define ll unsigned long long
#define hash _hash
#define rank _rank
using namespace std;
const int maxn=100005u;
const ll bas=133ull;
int n,m,sa[maxn],rank[maxn];
ll hash[maxn],pow2[maxn];
char s[maxn];
inline ll gethash(int p,int q)
{
	return hash[q]-hash[p-1]*pow2[q-p+1];
}
inline int lcp(int p,int q)
{
	int l=0u,r=min(n-p+1,n-q+1);
	while(l<r)
	{
		int mid=(l+r+1u)>>1u;
		if(gethash(p,p+mid-1)==gethash(q,q+mid-1))
			l=mid;
		else
			r=mid-1;
	}
	return l;
}
inline bool cmp(int p,int q)
{
	int l=lcp(p,q);
	return s[p+l]<s[q+l];
}
signed main()
{
	freopen("lcp.in","r",stdin);
	freopen("lcp.out","w",stdout);
	scanf("%u%u",&n,&m);
	scanf("%s",s+1);
	pow2[0]=1ull;
	for(rgi i=1;i<=n;++i)
	{
		pow2[i]=pow2[i-1]*bas;
		s[i]=s[i]-'a'+1;
		hash[i]=hash[i-1]*bas+(ll)s[i];
		sa[i]=i;
	}
	sort(sa+1,sa+n+1,cmp);
	for(rgi i=1;i<=n;++i)
		rank[sa[i]]=i;
	while(m--)
	{
		int x,y;
		scanf("%u%u",&x,&y);
		if(rank[x]<rank[y])
			putchar(48);
		else
			putchar(49);
		putchar(10);
	}
	return 0;
}
