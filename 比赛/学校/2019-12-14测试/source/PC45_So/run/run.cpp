#include <bits/stdc++.h>
using namespace std;
const int MAXN=600005;
struct TREE
{
	int from,to,w;
};
TREE tree[MAXN];
struct EDGE
{
	int _next,to,w;
};
EDGE edge[MAXN];
int _count,head[MAXN],fa[100005][30],ans[100005][30];
void Add_Line(const int &a,const int &b,const int &c)
{
	_count++;
	edge[_count]._next=head[a];
	edge[_count].to=b;
	edge[_count].w=c;
	head[a]=_count;
}
bool operator <(const TREE &a,const TREE &b)
{
	return a.w<b.w;
}
int father[MAXN];
int Find(int x)
{
	return x==father[x]?x:father[x]=Find(father[x]);
}
void Merge(int x,int y)
{
	int r1=Find(x);
	int r2=Find(y);
	if(r1==r2)
	{
		return;
	}
	father[r1]=r2;
}
int depth[MAXN];
void _Init(int NowNode,int f)
{
	depth[NowNode]=depth[f]+1;
	fa[NowNode][0]=f;
	for(int i=1;(1<<i)<=depth[NowNode];i++)
	{
		fa[NowNode][i]=fa[fa[NowNode][i-1]][i-1];
		ans[NowNode][i]=max(ans[NowNode][i-1],ans[fa[NowNode][i-1]][i-1]);
	}
	for(int i=head[NowNode];i;i=edge[i]._next)
	{
		int NextNode=edge[i].to;
		if(NextNode==f)
		{
			continue;
		}
		ans[NextNode][0]=edge[i].w;
		_Init(NextNode,NowNode);
	}
}
int LCA(int x,int y)
{
	int res=0;
	if(depth[x]<depth[y])
	{
		swap(x,y);
	}
	for(int i=25;i>=0;i--)
	{
		if(depth[x]-(1<<i)>=depth[y])
		{
			res=max(res,ans[x][i]);
			x=fa[x][i];
		}
	}
	if(x==y)
	{
		return res;
	}
	for(int i=25;i>=0;i--)
	{
		if(fa[x][i]==fa[y][i])
		{
			continue;
		}
		res=max(res,ans[x][i]);
		res=max(res,ans[y][i]);
		x=fa[x][i];
		y=fa[y][i];
	}
	return max(max(res,ans[x][0]),ans[y][0]);
}
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int N,M;
	scanf("%d%d",&N,&M);
	for(int i=1;i<=M;i++)
	{
		scanf("%d%d%d",&tree[i].from,&tree[i].to,&tree[i].w);
	}
	sort(tree+1,tree+1+M);
	for(int i=1;i<=N;i++)
	{
		father[i]=i;
	}
	int book=0;
	for(int i=1;i<=N;i++)
	{
		int x=tree[i].from,y=tree[i].to;
		int r1=Find(x),r2=Find(y);
		if(r1==r2)
		{
			continue;
		}
		else
		{
			Merge(x,y);
			Add_Line(x,y,tree[i].w);
			Add_Line(y,x,tree[i].w);
			book++;
		}
		if(book==N-1)
		{
			break;
		}
	}
	_Init(1,0);
	int Q;
	scanf("%d",&Q);
	while(Q--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		printf("%d\n",LCA(a,b));
	}
	return 0;
}
