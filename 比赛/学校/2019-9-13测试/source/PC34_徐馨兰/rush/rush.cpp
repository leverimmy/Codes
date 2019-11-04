#include <bits/stdc++.h>
using namespace std;

int n,m;
//int x[100010],y[100010];
long long num;

bool h1[100010],h2[100010],l1[100010],l2[100010];

int main()
{
	freopen("rush.in","r",stdin);
	freopen("rush.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		h1[i]=h2[i]=l1[i]=l2[i]=1;
	}
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		h1[y]=0;
		h2[y]=0;
		l1[x]=0;
		l2[x]=0;
	}
	for(int i=1;i<=n;i++)
	{
		num+=(h1[i] || h2[i]) + (l1[i] || l2[i]);	
	}
	for(int i=2;i<=n-1;i++)
	{
		if(h1[i]&&!h2[i])
			if(l1[i]||l2[n-i+1])
				if(l1[i]&&l2[n-i+1])
					num--,h1[i]=0;
				else
					num--,l1[i]=l2[n-i+1]=0;
		else if((!h1[i])&&h2[i])
			if(l2[i]||l1[n-i+1])
				if(l2[i]&&l1[n-i+1])
					num--,h2[i]=0;
				else
					num--,l2[i]=l1[n-i+1]=0;
		else if(h1[i]&&h2[i])
			if((l1[i]||l2[n-i+1])&&(l2[i]||l1[n-i+1]))
				num--;
	}
	printf("%lld\n",num);
	return 0;
} 
/*
2 2
2 1
2 2
*/
