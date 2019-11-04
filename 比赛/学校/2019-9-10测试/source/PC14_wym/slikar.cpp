#include<bits/stdc++.h>
#define flase false
#define ture true
#define mian main
using namespace std;
char mp[55][55][2500];
struct status
{
	int x,y,now;
};
int n,m,tgtx,tgty,z,ans=0x3f3f3f3f;
queue<status>hw;
queue<status>pos;
inline void spread(status qwq)
{
	int x=qwq.x,y=qwq.y,now=qwq.now;
	if(mp[x+1][y][now]=='.')
	{
		mp[x+1][y][now+1]='*';
		hw.push((status){x+1,y,now+1});
	}
	if(mp[x-1][y][now]=='.')
	{
		mp[x-1][y][now+1]='*';
		hw.push((status){x-1,y,now+1});
	}
	if(mp[x][y+1][now]=='.')
	{
		mp[x][y+1][now+1]='*';
		hw.push((status){x,y+1,now+1});
	}
	if(mp[x][y-1][now]=='.')
	{
		mp[x][y-1][now+1]='*';
		hw.push((status){x,y-1,now+1});
	}
}
inline void move(status qwq)
{
	int x=qwq.x,y=qwq.y,now=qwq.now;
	if(now>z)
		now=z;
	if(mp[x+1][y][now+1]=='.'||mp[x+1][y][now+1]=='D')
	{
		pos.push((status){x+1,y,qwq.now+1});
	}
	if(mp[x-1][y][now+1]=='.'||mp[x-1][y][now+1]=='D')
	{
		pos.push((status){x-1,y,qwq.now+1});
	}
	if(mp[x][y+1][now+1]=='.'||mp[x][y+1][now+1]=='D')
	{
		pos.push((status){x,y+1,qwq.now+1});
	}
	if(mp[x][y-1][now+1]=='.'||mp[x][y-1][now+1]=='D')
	{
		pos.push((status){x,y-1,qwq.now+1});
	}
}
int main()
{
	freopen("slikar.in","r",stdin);
	freopen("slikar.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>mp[i][j][0];
			if(mp[i][j][0]=='D')
			{
				tgtx=i;
				tgty=j;
			}
			if(mp[i][j][0]=='S')
			{
				pos.push((status){i,j,0});
				mp[i][j][0]='.';
			}
			if(mp[i][j][0]=='*')
			{
				hw.push((status){i,j,0});
			}
		}
	}
	while(!hw.empty())
	{
		int siz=hw.size();
		z=hw.front().now;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				mp[i][j][z+1]=mp[i][j][z];
		for(int i=1;i<=siz;i++)
		{
			spread(hw.front());
			hw.pop();
		}
		z++;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			mp[i][j][z+1]=mp[i][j][z];
	while(!pos.empty())
	{
		status qwq=pos.front();
		pos.pop();
		if(qwq.x==tgtx&&qwq.y==tgty)
		{
			ans=qwq.now;
			break;
		}
		move(qwq);
	}
	if(ans==0x3f3f3f3f)
	{
		cout<<"ORZ hzwer!!!";
		return 0;
	}
	cout<<ans;
	return 0;
}
