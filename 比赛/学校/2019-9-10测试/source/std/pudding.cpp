#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m,ans;
int fa[1000005],v[100005];
set<int> t[1000005];
void solve(int a,int b)
{
    for(set<int>::iterator i=t[a].begin();i!=t[a].end();i++)
	{
		if(v[*i-1]==b)ans--;
		if(v[*i+1]==b)ans--;
		t[b].insert(*i);
	}
	for(set<int>::iterator i=t[a].begin();i!=t[a].end();i++)v[*i]=b;
	t[a].clear();
}
int main()
{
	freopen("pudding.in","r",stdin);
	freopen("pudding.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++)v[i]=read();
	for(int i=1;i<=n;i++)
	{
		fa[v[i]]=v[i];
		if(v[i]!=v[i-1])ans++;
		t[v[i]].insert(i);
	}
	for(int i=1;i<=m;i++)
	{
		int f=read(),a,b;
		if(f==2)printf("%d\n",ans);
		else 
		{
			a=read();b=read();
			if(a==b)continue;
			if(t[fa[a]].size()>t[fa[b]].size())
				swap(fa[a],fa[b]);
			a=fa[a];b=fa[b];
			solve(a,b);
		}
	}
	return 0;
}
