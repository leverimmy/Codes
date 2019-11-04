#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <iostream>

using namespace std;

int e[110][110],n,m,color;

struct node
{
	int x;
	int y;
};

queue <struct node> q;

void bfs(int x,int y)
{
	struct node p;
	p.x=x;p.y=y;
	q.push(p);
	e[x][y]=color;
	while(q.empty()==0)
	{
		int tx=q.front().x;
		int ty=q.front().y+1;
		if(e[tx][ty]>0)
		{
			struct node t;
			t.x=tx;t.y=ty;
			q.push(t);
			e[tx][ty]=color;
		}
		tx=q.front().x+1;
		ty=q.front().y;
		if(e[tx][ty]>0)
		{
			struct node t;
			t.x=tx;t.y=ty;
			q.push(t);
			e[tx][ty]=color;
		}
		tx=q.front().x-1;
		ty=q.front().y;
		if(e[tx][ty]>0)
		{
			struct node t;
			t.x=tx;t.y=ty;
			q.push(t);
			e[tx][ty]=color;
		}
		tx=q.front().x;
		ty=q.front().y-1;
		if(e[tx][ty]>0)
		{
			struct node t;
			t.x=tx;t.y=ty;
			q.push(t);
			e[tx][ty]=color;
		}
		q.pop();
	}
	return;
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			scanf("%1d",&e[i][j]);
			if(e[i][j]!=0)
				e[i][j]=1;
		}
	/*struct node p;
	p.x=p.y=1;
	q.push(p);*/
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(e[i][j]>0)
			{
				color--;
				bfs(i,j);
			}
		}
	printf("%d",-color);
	return 0;
}