#include<bits/stdc++.h>
using namespace std;
int n,m;
int dis[1001][1001];
queue<pair<int,int> >q;
int gx[4]={0,1,-1,0},gy[4]={1,0,0,-1};
void bfs()
{
	while(!q.empty())
	{
		pair<int,int> u=q.front();
		q.pop();
		for(int i=0;i<4;i++)
		{
			int tox=gx[i]+u.first,toy=gy[i]+u.second;
			if(dis[tox][toy]==-1&&tox>0&&tox<=n&&toy>0&&toy<=m)
			{
				dis[tox][toy]=dis[u.first][u.second]+1;
				q.push(make_pair(tox,toy));
			}
		}
	}
}
int stx,sty,edx,edy;
int a[1001][1001];
bool judge(int x)
{
	memset(a,0,sizeof(a));
	if(dis[stx][sty]<x) return false;
	a[stx][sty]=1;
	q.push(make_pair(stx,sty));
	while(!q.empty())
	{
		pair<int,int> u=q.front();
		q.pop();
		for(int i=0;i<4;i++)
		{
			int tox=gx[i]+u.first,toy=gy[i]+u.second;
			if(dis[tox][toy]>=x&&a[tox][toy]==0)
			{
				a[tox][toy]=1;
				q.push(make_pair(tox,toy));
			}
		}
	}
	return a[edx][edy];
}
char c[1001][1001];
signed main()
{
	freopen("escape.in","r",stdin);
	freopen("escape.out","w",stdout);
	memset(dis,-1,sizeof(dis));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			cin>>c[i][j];
			if(c[i][j]=='+')
			{
				q.push(make_pair(i,j));
				dis[i][j]=0;
			}
			if(c[i][j]=='V')
				stx=i,sty=j;
			if(c[i][j]=='J')
				edx=i,edy=j;
		}
	bfs();
	int l=-1,r=501;
	while(l+1<r)
	{
		int mid=(l+r)/2;
		if(judge(mid))
			l=mid;
		else
			r=mid;
	}
	printf("%d",l);
	return 0;
}
