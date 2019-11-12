#include<bits/stdc++.h>
using namespace std;

const long long inf=1e19;
struct edge
{
	int u,v,a,b;
}e[100001];
bool cmp(edge a,edge b){return a.a<b.a;}

struct node
{
	int fa,v;
	int ch[2];
	bool mark;
}t[100001];
int v[100001];
void update(int x){t[x].v=max(v[x],max(t[t[x].ch[0]].v,t[t[x].ch[1]].v));}
int identify(int x){return t[t[x].fa].ch[1]==x;}
void connect(int x,int fa,int son){t[x].fa=fa,t[fa].ch[son]=x;}
bool isroot(int x){return t[t[x].fa].ch[0]!=x&&t[t[x].fa].ch[1]!=x;}
void rotate(int x)
{
	int y=t[x].fa;
	int mroot=t[y].fa;
	int yson=identify(x);
	int mson=identify(y);
	int z=t[x].ch[yson^1];
	t[x].fa=mroot;
	if(!isroot(y))connect(x,mroot,mson);
	connect(y,x,yson^1);
	connect(z,y,yson);
	update(y),update(x);
}
void pushdown(int x)
{
	if(t[x].mark)
	{
		swap(t[x].ch[0],t[x].ch[1]);
		t[t[x].ch[0]].mark^=1;
		t[t[x].ch[1]].mark^=1;
		t[x].mark=0;
	}
}
stack<int>st;
void splay(int x)
{
	int y=x;st.push(y);
	while(!isroot(y)) y=t[y].fa,st.push(y);
	while(!st.empty()) pushdown(st.top()),st.pop();
	while(!isroot(x)) rotate(x);
}

void access(int x)
{
	for(int y=0;x;x=t[(y=x)].fa)
		splay(x),t[x].ch[1]=y,update(x);
}
void makeroot(int x)
{
	access(x);
	splay(x);
	t[x].mark^=1;
}
void split(int x,int y)
{
	makeroot(x);
	access(y);
	splay(y);
}
int findroot(int x)
{
	access(x);
	splay(x);
	pushdown(x);
	while(t[x].ch[0])
		pushdown(x=t[x].ch[0]);
	return x;
}
void link(int x,int y)
{
	makeroot(x);
	if(findroot(y)!=x)
		t[x].fa=y;
}
void cut(int x,int y)
{
	split(x,y);
	if(t[y].ch[0]==x&&t[x].ch[1]==0)
		t[x].fa=t[y].ch[0]=0,update(y);
}
int get(int u,int w)
{
	if(v[u]==w) return u;
	if(t[t[u].ch[0]].v==w) return get(t[u].ch[0],w);
	else return get(t[u].ch[1],w);
}

struct modified_priority_queue
{
	priority_queue<int>q,del;
	void push(int x){q.push(x);}
	void pop(int x){del.push(x);}
	void check(){while(!del.empty()&&q.top()==del.top())q.pop(),del.pop();}
	int top(){check();return q.top();}
	bool empty(){check();return q.empty();}
}q;

int n,m,va,vb;
signed main()
{
	freopen("pay.in","r",stdin);
	freopen("pay.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%d%d",&va,&vb);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d%d",&e[i].u,&e[i].v,&e[i].a,&e[i].b);
	sort(e+1,e+m+1,cmp);
	int ver_cnt=1;
	long long ans=inf;
	for(int i=1;i<=m;i++)
	{
		v[i+n]=e[i].b;
		int u=e[i].u,v=e[i].v;
		split(u,v);
		if(findroot(v)!=u)
		{
			q.push(e[i].b);
			link(e[i].u,i+n);
			link(e[i].v,i+n);
			ver_cnt++;
		}
		else
		{
			int mx=t[v].v;
			if(mx>e[i].b)
			{
				int x=get(v,mx);
				cut(e[x-n].u,x);
				cut(e[x-n].v,x);
				q.pop(e[x-n].b);
				q.push(e[i].b);
				link(e[i].u,i+n);
				link(e[i].v,i+n);
			}
		}
		if(ver_cnt==n)
			ans=min(ans,1ll*e[i].a*va+1ll*q.top()*vb);
	}
	if(ans!=inf) printf("%lld",ans);
	else printf("-1");
	return 0;
}
/*
5 10
8 8
1 4 5 7
3 5 8 6
3 4 8 6
4 3 6 10
3 2 5 9
1 3 7 4
1 5 7 7
4 2 6 4
2 1 10 4
4 3 7 5
*/