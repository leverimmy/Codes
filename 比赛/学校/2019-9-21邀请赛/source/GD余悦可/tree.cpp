#include<bits/stdc++.h>
#define N 500001

using namespace std;
int h[N],n,m,cnt,dis[N],q[N*2],v[N],ans,f[N],ch[N],c;

struct edge{
	int to,fr,w;
}a[N];
edge tree[N];
int find(int x)
{
	if(f[x]==x)return x;
	else return find(f[x]);
}
void add(int x,int y,int z)
{
	cnt++;
	a[cnt].to=y;
	a[cnt].w=z;
	a[cnt].fr=x;
}
void ad(int x)
{
	c++;
	tree[c].to=a[x].to;
	tree[c].w=a[x].w;
	tree[c].fr=a[x].fr;
}
bool comp(edge x,edge y)
{
	if(x.w<y.w)return true;
	else return false;
}
bool comp1(edge x,edge y)
{
	if(x.fr<y.fr)return true;
	else if(x.fr==y.fr)
	{
		if(x.to==y.to)return true;
		else return false;
	}
	else return false;
}
void dfs(int k)
{
	//cout<<k<<endl;
	if(k>n || k<1)return;
	v[k]=1;
	for(int i=1;i<=c;i++)
	{
		int t=tree[i].to;
		if(t<=n && t>=1 && tree[i].fr==k)
		{
			
			dis[t]=min(dis[t], max(dis[k],tree[i].w));
			//cout<<k<<" "<<t<<" "<<dis[t]<<endl;
			if(!v[t])dfs(t);
			
		}
		if(t<=n && t>=1 && tree[i].to==k)
		{
			t=tree[i].fr;
			dis[t]=min(dis[t], max(dis[k],tree[i].w));
			//cout<<k<<" "<<t<<" "<<dis[t]<<endl;
			if(!v[t])dfs(t);
			
		}
	}
	return;
	
}

int main()
{
	
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);//*/
	cin>>n>>m;
	memset(h,0,sizeof(h));
	memset(dis,1,sizeof(dis));dis[1]=0;
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
	}
	sort(a+1,a+m+1,comp);
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++)
	{
		int x=find(a[i].fr),y=find(a[i].to);
		if(x!=y)
		{
			f[y]=x;
			ad(i);
		}
	}
	//cout<<c<<endl;
	sort(tree+1,tree+c+1,comp1);
	/*
	for(int i=1;i<=c;i++)
	{
		if(h[tree[i].fr]>i)h[tree[i].fr]=i;
		cout<<tree[i].fr<<" "<<tree[i].to<<endl;
	}
	h[n+1]=0;//*/
	dfs(1);
	for(int i=2;i<=n;i++)
	{
		ans+=dis[i];
		//cout<<dis[i]<<" ";
	}
	//cout<<endl;
	cout<<ans<<endl;
	
	return 0;
}



/* 

5 4
1 2 3
1 3 4
3 4 4 
3 5 7

18

4 4
1 4 1
1 3 4 
1 2 5
2 3 3

9

4 5
3 4 2
1 4 1
1 3 4 
1 2 5
2 3 3

6

3 3 
1 2 1 
2 3 1 
1 3 2

2

3 3 
1 2 5 
2 3 1 
3 1 2

4

*/











