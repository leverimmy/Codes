#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<queue>
using namespace std;
const int N=1e5+1;
const int M=5*1e5+1;
int n,m,a,b,c,cnt,sum;
int f[N],ans[N];
struct edge1
{
	int from;
	int to;
	int val;
}g[M];
struct dge
{
	int to;
	int val;
};
vector<dge> ed[N];


void dfs(int fa,int now)
{
	for(int i=0; i<ed[now].size(); i++)
	{
		dge tmp=ed[now][i];
		int son=tmp.to, val=tmp.val;
		if(son==fa) continue;
		ans[son]=max(ans[now],val);
	    //tr[son]=tr[now]+val;
		sum+=ans[son];
		dfs(now,son);
	}
}
void add(int a,int b,int c)
{
	cnt++;
	g[cnt].from=a;
	g[cnt].to=b;
	g[cnt].val=c;
}

void add1(int a,int b,int c)
{
	dge tmp;
	tmp.to=b; tmp.val=c;
	ed[a].push_back(tmp);
	tmp.to=a; 
	ed[b].push_back(tmp);
}
bool cmp(edge1 a,edge1 b)
{
	return a.val<b.val;
}

int get(int x)
{
	if(x==f[x]) return x;
	return f[x]=get(f[x]);
}
void merge(int a,int b)
{
	int tmp1=get(a);
	int tmp2=get(b);
	f[tmp2]=f[tmp1];
}


int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=m; i++)
	{
		cin>>a>>b>>c;
		add(a,b,c);		
	}
	for(int i=1; i<=n; i++)
	f[i]=i;
	sort(g+1,g+1+n,cmp);
	cnt=0;
	
	for(int i=1; i<=m; i++)
	{
		int val=g[i].val;
		int from=g[i].from,to=g[i].to;
		if(!(get(from)==get(to))) 
		{
			merge(from,to);
			cnt++;
			add1(from,to,val);
		}
		if(cnt==n-1) break;
	}
	dfs(0,1);
	/*for(int i=1; i<=n; i++)
	{
		cout<<i<<':'<<ans[i]<<"||"<<tr[i]<<endl;
	}*/
	cout<<sum;
	return 0;
}
