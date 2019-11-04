#include<bits/stdc++.h>
using namespace std;
const double eps=1e-6;
struct node
{
	int u,v,a,b;
}e[100001];
int n,m;
double k;
bool cmp(node x1,node x2){return (double)x1.a-x1.b*k<(double)x2.a-x2.b*k;}
int fa[100001];
int find(int x){return (fa[x]==x)?fa[x]:fa[x]=find(fa[x]);}
bool kruskal(double x)
{
	k=x;
	double ans=0;
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int f1=find(e[i].u),f2=find(e[i].v);
		if(f1!=f2)
		{
			fa[f1]=f2;
			ans+=(double)e[i].a-e[i].b*k;
		}
	}
	return ans<eps;
}
int main()
{
	freopen("mst.in","r",stdin);
	freopen("mst.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d%d",&e[i].u,&e[i].v,&e[i].a,&e[i].b);
	double l=0,r=100000;
	while(l+eps<r)
	{
		double mid=(l+r)/2;
		if(kruskal(mid))
			r=mid;
		else
			l=mid;
	}
	printf("%lf",r);
	return 0;
}
/*
3 3
1 2 1 1
2 3 1 3
3 1 1 2
*/