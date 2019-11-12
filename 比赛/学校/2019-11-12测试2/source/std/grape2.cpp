#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

const int mn = 200005;
const int maxn = 400005;

int read()
{
	int x=0;
	char ch=getchar();
	while(ch>'9' || ch<'0') ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return x;
}

vector<int> ve[mn*4];
struct edge{
	int u,v;
};
edge e[maxn];
void add(int l,int r,int cur,int L,int R,int z)
{
	if(l>=L && r<=R)
	{
		ve[cur].push_back(z);
		return ;
	}
	if(l>R || r<L) return ;
	int mid=l+r>>1;
	add(l,mid,cur<<1,L,R,z);
	add(mid+1,r,cur<<1|1,L,R,z);
}
int n,m,T,fa[mn],siz[mn],dep,sum[mn],deep[mn];
int _find(int x)
{
	dep=0;
	while(x!=fa[x])
	{
		dep=(dep+deep[x])%2;
		x=fa[x];
	}
	return x;
}
struct node{
	int fx,fy,id;
}st[maxn];
int top;
void del(int trs)
{
	int xx,yy;
	while(top>trs)
	{
		xx = st[top].fx;
		yy = st[top].fy;
		top--;
		if(siz[xx]>siz[yy])
		{
			siz[xx]-=siz[yy];
			fa[yy]=yy;
			deep[yy]=0;
		}
		else {
			siz[yy]-=siz[xx];
			fa[xx]=xx;
			deep[xx]=0;
		}
	}
}
void dfs(int l,int r,int cur)
{
	int tmp = ve[cur].size();
	int xx,yy,res1,res2;
	int trs = top;
	//cout<<l<<" "<<r<<endl;
	for(int i=0;i<tmp;i++)
	{
		xx = _find(e[ve[cur][i]].u);
		res1 = dep;
		yy = _find(e[ve[cur][i]].v);
		res2 = dep;
	//	cout<<xx<<" "<<yy<<endl;
		if(xx==yy)
		{
			if((res1 % 2) == (res2%2))
			{
				del(trs);
				sum[l]++,sum[r+1]--;
				return ;
			}
		}
		else {
			/*if(l<=3 && 3<=r)
				cout<<"add "<<e[ve[cur][i]].u<<" "<<e[ve[cur][i]].v<<endl;
			*/
			if(siz[xx]>siz[yy])
				fa[yy]=xx,siz[xx]+=siz[yy],deep[yy] = (res1+res2+1)%2;
			else fa[xx]=yy,siz[yy]+=siz[xx],deep[xx] = (res1+res2+1)%2;
			st[++top].id = ve[cur][i];
			st[top].fx=xx,st[top].fy=yy;
		}
	}
	if(l!=r)
	{
		int mid=l+r>>1;
		dfs(l,mid,cur<<1);
		dfs(mid+1,r,cur<<1|1);
	}
	del(trs);
}
int main()
{
	int x,y;
	freopen("grape.in","r",stdin);
	freopen("grape.out","w",stdout);
	n=read(),m=read(),T=read();
	for(int i=1;i<=m;i++)
	{
		e[i].u=read(),e[i].v=read();
		x=read(),y=read();
		x++;
		if(e[i].u==e[i].v)
		{
			//cout<<x<<" "<<y<<endl;
			sum[x]++,sum[y+1]--;
			continue;
		}
		add(1,T,1,x,y,i);
	}
	for(int i=1;i<=n;i++)
		fa[i]=i,siz[i]=1;
	dfs(1,T,1);
	for(int i=1;i<=T;i++)
		sum[i] += sum[i-1];
	for(int i=1;i<=T;i++)
		if(sum[i]>0) puts("No");
		else puts("Yes");
	return 0;
}
/*
3 3 3
1 2 0 2
2 3 0 3
1 3 2 3
*/


