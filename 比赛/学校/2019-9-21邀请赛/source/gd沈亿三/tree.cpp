#include<bits/stdc++.h>
using namespace std;
const int nx=1e5+5;
struct Edge{
	int x,y,v;
}bbb[nx];
int n,m,fa[nx];
bool cmp(Edge a,Edge b)
{
	return a.v<b.v;
}
int get(int x)
{
	if(fa[x]==x) return x;
	else return fa[x]=get(fa[x]);
}
struct {
	int to,next,val;
}edge[nx];
int head[nx],cnt,f[nx],ans;
void add_line(int f,int t,int v)
{
	cnt++;
	edge[cnt].to=t;
	edge[cnt].val=v;
	edge[cnt].next=head[f];
	head[f]=cnt;
}
queue<int> sc;
bool visit[nx];
void bfs()
{
	visit[1]=true;
	sc.push(1);
	while(!sc.empty())
	{
		int now=sc.front();
		sc.pop();
		for(int i=head[now];i;i=edge[i].next)
		{
			if(!visit[edge[i].to])
			{
				f[edge[i].to]=max(f[now],edge[i].val);
				ans+=f[edge[i].to];
				sc.push(edge[i].to);
				visit[edge[i].to]=true;
			}
		}
	}
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) fa[i]=i;
	for(int i=1;i<=m;++i)scanf("%d%d%d",&bbb[i].x,&bbb[i].y,&bbb[i].v);
	sort(bbb+1,bbb+m+1,cmp);
	cout<<endl<<endl;
	for(int i=1;i<=m;++i)
	{
		int xx=get(bbb[i].x);
		int yy=get(bbb[i].y);
		if(xx==yy) continue;
		fa[xx]=yy;
		add_line(bbb[i].x,bbb[i].y,bbb[i].v);
		add_line(bbb[i].y,bbb[i].x,bbb[i].v);
//		cout<<bbb[i].x<<"->"<<xx<<" "<<bbb[i].y<<"->"<<yy<<" "<<fa[xx]<<endl;
	}
	bfs();
	printf("%d",ans);
	return 0;
}
