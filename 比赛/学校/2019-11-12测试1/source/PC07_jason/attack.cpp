#include<bits/stdc++.h>
using namespace std;
struct node
{
	int fmx,smx;
	node(int x1=0,int x2=0){fmx=x1,smx=x2;}
}t[100001];
int a[100001];
vector<int>e[100001];
int mx[100001];
node pushup(node a,node b)
{
	node res;
	res.fmx=max(a.fmx,b.fmx);
	res.smx=max(min(a.fmx,b.fmx),max(a.smx,b.smx));
	return res;
}
void dfs(int u,int fa)
{
	sort(e[u].begin(),e[u].end());
	if(u!=1)e[u].erase(lower_bound(e[u].begin(),e[u].end(),fa));
	if(e[u].size()==0)
	{
		mx[u]=a[u];
		t[u].fmx=a[u];
		t[u].smx=0;
		return;
	}
	for(int i=0;i<e[u].size();i++)
	{
		int to=e[u][i];
		if(to!=fa)
		{
			dfs(to,u);
			t[u]=pushup(t[u],node(t[to].fmx,0));
			mx[u]=max(mx[u],mx[to]);
		}
	}
	t[u].fmx+=a[u],t[u].smx+=a[u];
	mx[u]=max(mx[u],t[u].fmx+t[u].smx-a[u]);
}

int ans=0;
void get_dp(int u,int fa)
{
	for(int i=0;i<e[u].size();i++)
	{
		int to=e[u][i];
		get_dp(to,u);
	}

	if(e[u].size()==0) 
	{
		ans=max(ans,mx[u]);
		return;
	}
	if(e[u].size()==1)
	{
		ans=max(ans,mx[u]);
		ans=max(ans,t[u].fmx);
		return;
	}
	
	vector<node>pre,suf,val;
	pre.resize(e[u].size());
	suf.resize(e[u].size());
	val.resize(e[u].size());
	
	pre[0]=node(t[e[u][0]].fmx,0);
	for(int i=1;i<e[u].size();i++)
		pre[i]=pushup(pre[i-1],node(t[e[u][i]].fmx,0));

	suf[e[u].size()-1]=node(t[e[u][e[u].size()-1]].fmx,0);
	for(int i=(int)e[u].size()-2;i>=0;i--)
		suf[i]=pushup(suf[i+1],node(t[e[u][i]].fmx,0));
	
	for(int i=0;i<e[u].size();i++)
	{
		if(i==0) val[i]=suf[1];
		else if(i==e[u].size()-1) val[i]=pre[e[u].size()-2];
		else val[i]=node(suf[i+1].fmx,pre[i-1].fmx);
	}
	
	for(int i=0;i<e[u].size();i++)
		ans=max(ans,mx[e[u][i]]+val[i].fmx+val[i].smx+a[u]);
}
int main()
{
	freopen("attack.in","r",stdin);
	freopen("attack.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0);
	get_dp(1,0);
	printf("%d",ans);
    return 0;
} 
/*
8
1 2 99 4 5 3 2 1
1 2
1 4
1 6
1 3
4 5
6 7
6 8
*/