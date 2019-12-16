#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cmath>
//#include<bits/stdc++.h>
#define mod 998244353
#define N 500050
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,head[N],pos;
struct edge{int to,next;}e[N<<1];
void add(int a,int b)
{pos++;e[pos].to=b,e[pos].next=head[a],head[a]=pos;}
void insert(int a,int b){add(a,b),add(b,a);}
int f[N],size[N],fac[N];
void dfs(int u,int fa)
{
	f[u]=1;int k=0;
	for(int i=head[u];i;i=e[i].next)
	{
		int v=e[i].to;
		if(v==fa)continue;
		dfs(v,u);
		f[u]=1ll*f[u]*f[v]%mod;
		k++;
	}
	f[u]=1ll*f[u]*fac[k+(u!=1)]%mod;
}
void init()
{
	fac[0]=1;
	for(int i=1;i<N;i++)fac[i]=1ll*fac[i-1]*i%mod;
}
int main()
{  freopen("tree.in","r",stdin);
  freopen("tree.out","w",stdout);
	n=read();init();
	for(int i=2;i<=n;i++)
	{
		int x=read(),y=read();
		insert(x,y);
	}
	dfs(1,0);
	printf("%d\n",1ll*n*f[1]%mod);
}
