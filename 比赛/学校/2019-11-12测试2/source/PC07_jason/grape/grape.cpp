#include<bits/stdc++.h>
using namespace std;
struct node
{
	int fa,v,mn;
	node(){mn=999999999;}
	int ch[2];
	bool mark;
}t[600001];
int mn[600001];
void update(int x)
{
	t[x].v=t[t[x].ch[0]].v+t[t[x].ch[1]].v+1;
	t[x].mn=min(mn[x],min(t[t[x].ch[0]].mn,t[t[x].ch[1]].mn));
}
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
	if(!isroot(y)) connect(x,mroot,mson);
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

struct edge
{
	int u,v,st,ed,id;
}e[600001];
bool cmp(edge a,edge b){return a.st<b.st;}

vector<pair<int,int> >v;
int ans[600001];

int find(int x,int v)
{
	if(mn[x]==v)
		return x;
	if(t[t[x].ch[0]].mn==v) 
		return find(t[x].ch[0],v);
	if(t[t[x].ch[1]].mn==v)
		return find(t[x].ch[1],v);
}

struct modified_priority_queue
{
	struct cmp
	{
		bool operator()(int a,int b)
		{
			if(e[a].ed!=e[b].ed)return e[a].ed>e[b].ed;
			return e[a].id>e[b].id;
		}
	};
	priority_queue<int,vector<int>,cmp>q,del;
	void check(){while(!del.empty()&&q.top()==del.top())q.pop(),del.pop();}
	int top(){check();return q.top();}
	bool empty(){check();return q.empty();}
	void push(int x){q.push(x);}
	void pop(int x){del.push(x);}
}q;
signed main()
{
	freopen("grape.in","r",stdin);
	freopen("grape.out","w",stdout);
	int n,m,T;
	scanf("%d%d%d",&n,&m,&T);
	memset(mn,0x3f,sizeof(mn));
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d%d",&e[i].u,&e[i].v,&e[i].st,&e[i].ed);
		e[i].st++;e[i].id=i;
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		while(!q.empty()&&e[q.top()].ed<e[i].st)
		{
			int x=q.top();
			cut(x+n,e[x].u);
			cut(x+n,e[x].v);
			q.pop(x);
		}
		split(e[i].u,e[i].v);
		mn[i+n]=e[i].ed;
		if(findroot(e[i].v)!=e[i].u)
		{
			link(e[i].u,i+n);
			link(e[i].v,i+n);
			q.push(i);
		}
		else if(e[i].u!=e[i].v)
		{
			int far=t[e[i].v].mn;
			if(((t[e[i].v].v+1)/2)%2==1)
				v.push_back(make_pair(e[i].st,min(far,e[i].ed)));
			if(e[i].ed>far)
			{
				int x=find(e[i].v,far);
				cut(x,e[x-n].u);
				cut(x,e[x-n].v);
				q.pop(x-n);
				
				link(e[i].u,i+n);
				link(e[i].v,i+n);
				q.push(i);
			}
		}
		else
			v.push_back(make_pair(e[i].st,e[i].ed));
	}
	int far=0;
	for(int i=0;i<v.size();i++)
	{
		for(int j=max(far+1,v[i].first);j<=v[i].second;j++)
			ans[j]=1;
		far=max(far,v[i].second);
	}
	for(int i=1;i<=T;i++)
		if(ans[i]==0)
			printf("Yes\n");
		else
			printf("No\n");
    return 0;
} 
/*

3 3 3
1 2 0 2
2 3 0 3
1 3 1 3

*/