#include<bits/stdc++.h>
using namespace std;
struct node
{
	int x[2];
}t[1000001];
int n;
int fa[1000001];
int vis[1000001];
int find(int x){return (fa[x]==x)?fa[x]:fa[x]=find(fa[x]);}
void join(int x,int y)
{
	int f1=find(x),f2=find(y);
	if(f1!=f2)
		fa[f1]=f2;
}
vector<pair<int,int> >p[1000001];
vector<int>v;
bool judge(int x)
{
	queue<pair<int,int> >q;
	for(int i=0;i<=2*n;i++)
		fa[i]=i,vis[i]=0;
	for(int i=x+1;i<v.size();i++)
	{
		vis[i]=1;
		for(int j=0;j<p[i].size();j++)
		{
			pair<int,int> cur=p[i][j];
			cur.second^=1;
			q.push(cur);
		}
	}
	while(!q.empty())
	{
		pair<int,int> u=q.front();
		int at=u.second;
		int pos=t[u.first].x[at];
		if(u.first>x) return false;
		if(vis[pos]==1) return false;
		q.pop();
		vis[pos]=1;
		for(int i=0;i<p[pos].size();i++)
			if(p[pos][i].first!=u.first)
			{
				int x=p[pos][i].first;
				q.push(make_pair(x,p[pos][i].second^1));
				
				join(x+(p[pos][i].second^1)*n,0);
			}
	}
	for(int i=1;i<=n;i++)
		if(find(i)==find(0)&&find(i+n)==find(0))
			return false;
	return true;
}
map<int,int>mp;
signed main()
{
	freopen("exam.in","r",stdin);
	freopen("exam.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&t[i].x[0],&t[i].x[1]);
		v.push_back(t[i].x[0]);
		v.push_back(t[i].x[1]);
	}
	v.push_back(0);
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	for(int i=1;i<=n;i++)
	{
		t[i].x[0]=lower_bound(v.begin(),v.end(),t[i].x[0])-v.begin();
		t[i].x[1]=lower_bound(v.begin(),v.end(),t[i].x[1])-v.begin();
		p[t[i].x[0]].push_back(make_pair(i,0));
		p[t[i].x[1]].push_back(make_pair(i,1));
	}
	int l=0,r=v.size();
	while(l+1<r)
	{
		int mid=(l+r)/2;
		if(judge(mid))
			r=mid;
		else
			l=mid;
	}
	printf("%d",v[r]);
	return 0;
}