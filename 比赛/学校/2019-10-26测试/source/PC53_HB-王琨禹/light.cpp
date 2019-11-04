#include <cstdio>
using namespace std;
const int MAXN=100005;
int a[MAXN];
int book[MAXN];
struct QUERY
{
	int l,r,v,p,id,ans;
};
QUERY query[MAXN];
bool cmp(const QUERY &a,const QUERY &b)
{
	if(a.l==b.l)
	{
		if(a.r==b.r)
		{
			if(a.p==b.p)
			{
				if(a.v==b.v)
				{
					return a.id<b.id;
				}
				return a.v<b.v;
			}
			return a.p<b.p;
		}
		return a.r<b.r;
	}
	return a.l<b.l;
}

int main()
{
	freopen("light.in","r",stdin);
	freopen("light.out","w",stdout);
	int N,M;
	scanf("%d%d",&N,&M);
		for(int i=1;i<=N;i++)
		{
			scanf("%d",a+i);
		}
		for(int i=1;i<=M;i++)
		{
			scanf("%d%d%d%d",&query[i].l,&query[i].r,&query[i].p,&query[i].v);
			query[i].id=i;
		}
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=M;j++)
			{
				int l=query[j].l;
				int r=query[j].r;
				int p=query[j].p;
				int v=query[j].v;
				if(i>=l&&i<=r&&a[i]%p==v)
				{
					query[j].ans++;
				}
			}
		}
		for(int i=1;i<=M;i++)
		{
			printf("%d\n",query[i].ans);
		}
	return 0;
}
