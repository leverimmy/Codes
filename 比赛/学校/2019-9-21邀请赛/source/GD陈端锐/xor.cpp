#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
int put[100010];
struct query
{
	int a;
	int b;
	int c;
	int id;
}v[100010];
bool cmp(query x,query y)
{
	return x.a<x.b;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,m,pd=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d%d",&v[i].a,&v[i].b,&v[i].c);
			v[i].id=i;
		}
		sort(v+1,v+m+1,cmp);
		memset(put,-1,sizeof(put));
		for(int i=1;i<=m;i++)
		{
			int w=v[i].a,len=v[i].b-v[i].a;
			while(w<=v[i].b&&put[w]<=0)
			{
				len--;
				w++;
			}
			if(put[w]!=-1)
			{
				pd=1;
				break;
			}
			put[w]=v[i].c;
			w++;
			while(w<=v[i].b&&put[w]<=0)
			{
				put[w]=0;
				w++;
				len--;
			}
			if(len>0)
			{
				pd=1;
				break;
			}
		}
		if(pd==1) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}
