#include <cstdio>

using namespace std;

struct node
{
	int lc,weight,rc;
}t[1000010];

int n,maxn=-99999;
int ans[1000010];

int check(int a,int b)
{
	if(a==-1 && b==-1)
		return 1;
	else if(a!=-1 && b!=-1 && t[a].weight == t[b].weight && check(t[a].lc,t[b].rc) && check(t[a].rc,t[b].lc))
		return 1;
	return 0;
}

void dfs(int id)
{
	ans[id]=1;
	if(t[id].lc!=-1)
	{
		dfs(t[id].lc);
		ans[id]+=ans[t[id].lc];
	}
	if(t[id].rc!=-1)
	{
		dfs(t[id].rc);
		ans[id]+=ans[t[id].rc];
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&t[i].weight);
	for(int i=1;i<=n;i++)
		scanf("%d %d",&t[i].lc,&t[i].rc);
	dfs(1);
	for(int i=1;i<=n;i++)
	{
		if(check(t[i].lc,t[i].rc)==1)
			maxn=ans[i]>maxn?ans[i]:maxn;
	}
	printf("%d",maxn);
	return 0;
}