#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<iomanip>
#include<ctime>
#include<cstdlib>
#include<queue>
#include<vector>
#include<map>
#define ll long long
using namespace std;
inline ll read()
{
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
		{
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
ll xs,ys,xz,yz,ans;
ll m,n;
struct node
{
	ll x,y,num;
}a[250001];
bool cmp(node x,node y)
{
	return x.num<y.num;
}
ll f[250001];
inline int fa(int x)
{
	if(f[x]!=x)
		f[x]=fa(f[x]);
	return f[x];
}
ll r[1001][1001];
bool b[1001][1001];
void dfs(ll step,ll x)
{
	if(x==(xz-1)*m+yz)
	{
		ans=min(ans,step);
		return;
	}
 	if(r[x][x+1]==1&&b[x][x+1])
	{
		b[x][x+1]=false;
		dfs(step+1,x+1);
		b[x][x+1]=true;
	}
	if(r[x][x-1]==1&&b[x][x-1])
	{
		b[x][x-1]=false;
		dfs(step+1,x-1);
		b[x][x-1]=true;
	}
	if(r[x][x+m]==1&&b[x][x+m])
	{
		b[x][x+m]=false;
		dfs(step+1,x+m);
		b[x][x+m]=true;
	}
	if(r[x][x-m]==1&&b[x][x-m])
	{
		b[x][x-m]=false;
		dfs(step+1,x-m);
		b[x][x-m]=true;
	}
}
int main()
{
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	memset(b,true,sizeof(b));
	n=read(),m=read();
	ll sum=0,jiji=0;
	ll judge=1;
	for(ll i=1;i<=n*m;i++)
	{
  		ll x=read(),y=read();
		sum+=x+y;
		x=-x;
		y=-y;
		if(y!=0)
		{
			/*r[i][i+1]=1;
			r[i+1][i]=1;*/
			a[judge].x=i;
			a[judge].y=i+1;
			a[judge].num=y;
			judge++;
		}
		if(x!=0)
		{
			/*r[i][i+m]=1;
			r[i+m][i]=1;*/
			a[judge].x=i;
			a[judge].y=i+m;
			a[judge].num=x;
			judge++;
		}
	}
	sort(a+1,a+1+judge,cmp);
	for(ll i=1;i<=n*m;i++)
	{
		f[i]=i;
	}
	ll j=0;
	for(ll i=1;i<=judge;i++)
	{
		ll q1=fa(a[i].x);
		ll q2=fa(a[i].y);
		if(q1!=q2)
		{
			f[q1]=q2;
			j++;
			jiji+=a[i].num;
			r[a[i].x][a[i].y]=1;
			r[a[i].y][a[i].x]=1;
		}
		if(j==n*m-1)
		{
			break;
		}
	}
	ll q=read();
	for(ll i=1;i<=q;i++)
	{
		memset(b,true,sizeof(true));
		xs=read(),ys=read();
		xz=read(),yz=read();
		ans=0x7ffffff;
		b[xs][ys]=false;
		dfs(0,(xs-1)*m+ys);
		printf("%d\n",ans);
	}
	return 0;
}

