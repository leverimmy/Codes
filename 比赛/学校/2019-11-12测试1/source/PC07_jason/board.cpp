#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
int n,m,k;
int ans,cnt;
int a[11][11],book[11][11];
pair<int,int>rev[101];
vector<pair<int,int> >rem[11];
int prod[11];
struct modified_priority_queue
{
	priority_queue<int,vector<int>,greater<int> >q,del;
	void check(){while(!del.empty()&&q.top()==del.top())q.pop(),del.pop();}
	int top(){check();return q.top();}
	int pop(int x){del.push(x);}
	int push(int x){q.push(x);}
	int empty(){check();return q.empty();}
}q;
int c(int n,int m)
{
	int ans=1;
	for(int i=n;i>=n-m+1;i--)
		ans*=i;
	for(int i=1;i<=m;i++)
		ans/=i;
	return ans;
}
void outer_dfs(int st,int x);
void inner_dfs(int c,int r,int x);
int get_ans(int x)
{
	int tot=0;
	for(int i=1;i<=k;i++)
	{
		if(rem[i].empty())continue;
		int col=a[rem[i][0].first][rem[i][0].second];
		for(int j=1;j<rem[i].size();j++)
			if(col!=a[rem[i][j].first][rem[i][j].second])
				return 0;
		tot++;
	}
	return prod[x-tot]*c(k-tot,x-tot);
}
void inner_dfs(int c,int r,int x)
{
	a[c][r]=x;
	q.pop(book[c][r]);
	if(q.empty()) 
	{
		ans+=get_ans(x);
		ans%=mod;
		a[c][r]=0;
		q.push(book[c][r]);
		return;
	}
	for(int i=1;i<c;i++)
		for(int j=r+1;j<=m;j++)
			if(a[i][j]==0)
				inner_dfs(i,j,x);
	outer_dfs(q.top(),x+1);
	a[c][r]=0;
	q.push(book[c][r]);
}
void outer_dfs(int st,int x)
{
	if(x==k+1) return;
	int atx=rev[st].first,aty=rev[st].second;
	inner_dfs(atx,aty,x);
}
signed main()
{
	//freopen("board.in","r",stdin);
	//freopen("board.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	if(n+m>k+1)
	{
		printf("0");
		return 0;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			int c;
			cin>>c;
			if(c!=0)
				rem[c].push_back(make_pair(i,j));
		}
	prod[0]=1;
	for(int i=1;i<=k;i++)
		prod[i]=prod[i-1]*i;
	for(int p=0;p<n;p++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(!book[i][j]&&(i==m-p||j==1+p))
					book[i][j]=++cnt,rev[cnt]=make_pair(i,j);
	for(int i=1;i<=cnt;i++)
		q.push(i);
	outer_dfs(1,1);
	printf("%d",ans);
	return 0;
}
/*
5 6 10
0 0 0 0 0 0 
0 0 0 0 0 0 
0 0 0 0 0 0 
0 0 0 0 0 0 
0 0 0 0 0 0 
*/