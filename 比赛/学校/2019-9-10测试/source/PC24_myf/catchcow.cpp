#include <iostream>
#include <cstdio>
#include <queue>
#define rgi register int
#define pii pair<int,int>
#define mkp make_pair
#define fs first
#define sc second
using namespace std;
int a,b,ans;
queue<pii> que;
bool book[200005];
int main()
{
	ios::sync_with_stdio(false);
	freopen("catchcow.in","r",stdin);
	freopen("catchcow.out","w",stdout);
	cin>>a>>b;
	if(b<=a)
	{
		cout<<a-b<<endl;
		return 0;
	}
	que.push(mkp(a,0));
	while(!que.empty())
	{
		int x=que.front().fs,step=que.front().sc;
		if(x<<1==b||x+1==b||x-1==b)
		{
			cout<<step+1<<endl;
			break;
		}
		if((x<<1)<=200000&&!book[x<<1])
		{
			que.push(mkp(x<<1,step+1));
			book[x<<1]=1;
		}
		if(x+1<=100000&&!book[x+1])
		{
			que.push(mkp(x+1,step+1));
			book[x+1]=1;
		}
		if(x-1>=0&&!book[x-1])
		{
			que.push(mkp(x-1,step+1));
			book[x-1]=1;
		}
		que.pop();
	}
	return 0;
}

