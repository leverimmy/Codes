#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
int n,m=100000;
char s[200001];
int sa[200001],tax[200001],rnk[200001],tp[200001];
void qsort()
{
	for(int i=1;i<=m;i++)
		tax[i]=0;
	for(int i=1;i<=n;i++)tax[rnk[i]]++;
	for(int i=1;i<=m;i++)tax[i]+=tax[i-1];
	for(int i=n;i>=1;i--)
		sa[tax[rnk[tp[i]]]--]=tp[i];
}
void suffix_sort()
{
	for(int i=1;i<=n;i++)
		rnk[i]=s[i]-'a'+1,tp[i]=i;
	qsort();
	for(int w=1,p=0;p<n;w<<=1)
	{
		p=0;
		for(int i=n-w+1;i<=n;i++)
			tp[++p]=i;
		for(int i=1;i<=n;i++)
			if(sa[i]>w)
				tp[++p]=sa[i]-w;
		qsort();
		for(int i=1;i<=n;i++)
			swap(tp[i],rnk[i]);
		rnk[sa[1]]=p=1;
		for(int i=2;i<=n;i++)
			if(tp[sa[i]]==tp[sa[i-1]]&&tp[sa[i]+w]==tp[sa[i-1]+w])
				rnk[sa[i]]=p;
			else
				rnk[sa[i]]=++p;
	}
}
signed main()
{
	freopen("lcp.in","r",stdin);
	freopen("lcp.out","w",stdout);
	int q;
	scanf("%d%d",&n,&q);
	cin>>s+1;
	suffix_sort();
	while(q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(rnk[x]<rnk[y])
			printf("0\n");
		else
			printf("1\n");
	}
//	for(int i=1;i<=n;i++)
//		printf("%d ",sa[i]);
	return 0;
}
/*
5 2 
abaab 
1 3 
1 4
*/