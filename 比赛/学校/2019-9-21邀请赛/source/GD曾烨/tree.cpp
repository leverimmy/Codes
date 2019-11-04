#include  <bits/stdc++.h>
using namespace std;
struct edge 
{
	int y,z;
};
vector <edge> a[100005];
int n,m,x,y,z,len,lenn,maxx,ans,f[100005];
bool c[100005];
void find(int maxx,int k)
{
	if (!f[k]) f[k]=maxx;
		else if (f[k]&&f[k]>maxx) f[k]=maxx;
	if (c[k]) return;
	c[k]=1;
	for (int i=0;i<a[k].size();i++)
	{
		if (!f[a[k][i].y]) find(max(maxx,a[k][i].z),a[k][i].y);
		if (f[a[k][i].y]&&f[a[k][i].y]>max(maxx,a[k][i].z)) find(max(a[k][i].z,maxx),a[k][i].y);
	}
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		edge b;
		b.y=y; b.z=z;
		a[x].push_back(b);
		b.y=x; b.z=z;
		a[y].push_back(b);
	}
	len=a[1].size();
	for (int i=0;i<len;i++)
	{
		find(a[1][i].z,a[1][i].y);
		memset(c,0,sizeof(c));
	}
	for (int i=2;i<=n;i++) { ans+=f[i]; }
	cout<<ans;
	return 0;
}
			
			
			
			
