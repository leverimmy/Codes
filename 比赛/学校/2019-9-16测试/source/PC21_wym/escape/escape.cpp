#include<bits/stdc++.h>
using namespace std;
struct status
{
	int px,py,hx,hy;
	int lpx,lpy,lhx,lhy;
	int t;
};
queue<status>q;
int n,m,_px,_py,_hx,_hy;
char dgn[55][55],nh,sh,wh,eh;//north,south,west,east
inline bool judge(status x)
{
	if(x.px==x.hx&&x.py==x.hy)
		return true;
	if(x.px==x.lhx&&x.py==x.lhy&&x.hx==x.lpx&&x.hy==x.lpy)
		return true;
	return false;
}
int main()
{
	freopen("escape.in","r",stdin);
	freopen("escape.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			cin>>dgn[i][j];
			if(dgn[i][j]=='H')
				_hx=i,_hy=j,dgn[i][j]='.';
			if(dgn[i][j]=='P')
				_px=i,_py=j,dgn[i][j]='.';
		}
	cin>>nh>>sh>>wh>>eh;
	/*
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<dgn[i][j];
		}
		cout<<endl;
	}
	*/
	q.push((status){_px,_py,_hx,_hy,-1,-2,-3,-4,0});
	while(!q.empty())
	{
		status now=q.front();
		q.pop();
		if(now.t>255)
			continue;
		if(judge(now))
		{
			cout<<now.t<<endl;
			return 0;
		}
		switch(nh)
		{
			case 'N':
				if(dgn[now.px-1][now.py]=='.'&&dgn[now.hx-1][now.hy]=='.')
					q.push((status){now.px-1,now.py,now.hx-1,now.hy,now.px,now.py,now.hx,now.hy,now.t+1});
				else if(dgn[now.px-1][now.py]=='.'&&dgn[now.hx-1][now.hy]=='#')
					q.push((status){now.px-1,now.py,now.hx,now.hy,now.px,now.py,now.hx,now.hy,now.t+1});
//				else if(dgn[now.px-1][now.py]=='#'&&dgn[now.hx-1][now.hy]=='.')
//					q.push((status){now.px,now.py,now.hx-1,now.hy,now.px,now.py,now.hx,now.hy,now.t+1});
				break;
			case 'S':
				if(dgn[now.px-1][now.py]=='.'&&dgn[now.hx+1][now.hy]=='.')
					q.push((status){now.px-1,now.py,now.hx+1,now.hy,now.px,now.py,now.hx,now.hy,now.t+1});
				else if(dgn[now.px-1][now.py]=='.'&&dgn[now.hx+1][now.hy]=='#')
					q.push((status){now.px-1,now.py,now.hx,now.hy,now.px,now.py,now.hx,now.hy,now.t+1});
//				else if(dgn[now.px-1][now.py]=='#'&&dgn[now.hx+1][now.hy]=='.')
//					q.push((status){now.px,now.py,now.hx+1,now.hy,now.px,now.py,now.hx,now.hy,now.t+1});
				break;
			case 'W':
				if(dgn[now.px-1][now.py]=='.'&&dgn[now.hx][now.hy-1]=='.')
					q.push((status){now.px-1,now.py,now.hx,now.hy-1,now.px,now.py,now.hx,now.hy,now.t+1});
				else if(dgn[now.px-1][now.py]=='.'&&dgn[now.hx][now.hy-1]=='#')
					q.push((status){now.px-1,now.py,now.hx,now.hy,now.px,now.py,now.hx,now.hy,now.t+1});
//				else if(dgn[now.px-1][now.py]=='#'&&dgn[now.hx][now.hy-1]=='.')
//					q.push((status){now.px,now.py,now.hx,now.hy-1,now.px,now.py,now.hx,now.hy,now.t+1});
				break;
			case 'E':
				if(dgn[now.px-1][now.py]=='.'&&dgn[now.hx][now.hy+1]=='.')
					q.push((status){now.px-1,now.py,now.hx,now.hy+1,now.px,now.py,now.hx,now.hy,now.t+1});
				else if(dgn[now.px-1][now.py]=='.'&&dgn[now.hx][now.hy+1]=='#')
					q.push((status){now.px-1,now.py,now.hx,now.hy,now.px,now.py,now.hx,now.hy,now.t+1});
//				else if(dgn[now.px-1][now.py]=='#'&&dgn[now.hx][now.hy+1]=='.')
//					q.push((status){now.px,now.py,now.hx,now.hy+1,now.px,now.py,now.hx,now.hy,now.t+1});
				break;
		}
		switch(sh)
		{
			case 'N':
				if(dgn[now.px+1][now.py]=='.'&&dgn[now.hx-1][now.hy]=='.')
					q.push((status){now.px+1,now.py,now.hx-1,now.hy,now.px,now.py,now.hx,now.hy,now.t+1});
				else if(dgn[now.px+1][now.py]=='.'&&dgn[now.hx-1][now.hy]=='#')
					q.push((status){now.px+1,now.py,now.hx,now.hy,now.px,now.py,now.hx,now.hy,now.t+1});
//				else if(dgn[now.px+1][now.py]=='#'&&dgn[now.hx-1][now.hy]=='.')
//					q.push((status){now.px,now.py,now.hx-1,now.hy,now.px,now.py,now.hx,now.hy,now.t+1});
				break;
			case 'S':
				if(dgn[now.px+1][now.py]=='.'&&dgn[now.hx+1][now.hy]=='.')
					q.push((status){now.px+1,now.py,now.hx+1,now.hy,now.px,now.py,now.hx,now.hy,now.t+1});
				else if(dgn[now.px+1][now.py]=='.'&&dgn[now.hx+1][now.hy]=='#')
					q.push((status){now.px+1,now.py,now.hx,now.hy,now.px,now.py,now.hx,now.hy,now.t+1});
//				else if(dgn[now.px+1][now.py]=='#'&&dgn[now.hx+1][now.hy]=='.')
//					q.push((status){now.px,now.py,now.hx+1,now.hy,now.px,now.py,now.hx,now.hy,now.t+1});
				break;
			case 'W':
				if(dgn[now.px+1][now.py]=='.'&&dgn[now.hx][now.hy-1]=='.')
					q.push((status){now.px+1,now.py,now.hx,now.hy-1,now.px,now.py,now.hx,now.hy,now.t+1});
				else if(dgn[now.px+1][now.py]=='.'&&dgn[now.hx][now.hy-1]=='#')
					q.push((status){now.px+1,now.py,now.hx,now.hy,now.px,now.py,now.hx,now.hy,now.t+1});
//				else if(dgn[now.px+1][now.py]=='#'&&dgn[now.hx][now.hy-1]=='.')
//					q.push((status){now.px,now.py,now.hx,now.hy-1,now.px,now.py,now.hx,now.hy,now.t+1});
				break;
			case 'E':
				if(dgn[now.px+1][now.py]=='.'&&dgn[now.hx][now.hy+1]=='.')
					q.push((status){now.px+1,now.py,now.hx,now.hy+1,now.px,now.py,now.hx,now.hy,now.t+1});
				else if(dgn[now.px+1][now.py]=='.'&&dgn[now.hx][now.hy+1]=='#')
					q.push((status){now.px+1,now.py,now.hx,now.hy,now.px,now.py,now.hx,now.hy,now.t+1});
//				else if(dgn[now.px+1][now.py]=='#'&&dgn[now.hx][now.hy+1]=='.')
//					q.push((status){now.px,now.py,now.hx,now.hy+1,now.px,now.py,now.hx,now.hy,now.t+1});
				break;
		}
		switch(wh)
		{
			case 'N':
				if(dgn[now.px][now.py-1]=='.'&&dgn[now.hx-1][now.hy]=='.')
					q.push((status){now.px,now.py-1,now.hx-1,now.hy,now.px,now.py,now.hx,now.hy,now.t+1});
				else if(dgn[now.px][now.py-1]=='.'&&dgn[now.hx-1][now.hy]=='#')
					q.push((status){now.px,now.py-1,now.hx,now.hy,now.px,now.py,now.hx,now.hy,now.t+1});
//				else if(dgn[now.px][now.py-1]=='#'&&dgn[now.hx-1][now.hy]=='.')
//					q.push((status){now.px,now.py,now.hx-1,now.hy,now.px,now.py,now.hx,now.hy,now.t+1});
				break;
			case 'S':
				if(dgn[now.px][now.py-1]=='.'&&dgn[now.hx+1][now.hy]=='.')
					q.push((status){now.px,now.py-1,now.hx+1,now.hy,now.px,now.py,now.hx,now.hy,now.t+1});
				else if(dgn[now.px][now.py-1]=='.'&&dgn[now.hx+1][now.hy]=='#')
					q.push((status){now.px,now.py-1,now.hx,now.hy,now.px,now.py,now.hx,now.hy,now.t+1});
//				else if(dgn[now.px][now.py-1]=='#'&&dgn[now.hx+1][now.hy]=='.')
//					q.push((status){now.px,now.py,now.hx+1,now.hy,now.px,now.py,now.hx,now.hy,now.t+1});
				break;
			case 'W':
				if(dgn[now.px][now.py-1]=='.'&&dgn[now.hx][now.hy-1]=='.')
					q.push((status){now.px,now.py-1,now.hx,now.hy-1,now.px,now.py,now.hx,now.hy,now.t+1});
				else if(dgn[now.px][now.py-1]=='.'&&dgn[now.hx][now.hy-1]=='#')
					q.push((status){now.px,now.py-1,now.hx,now.hy,now.px,now.py,now.hx,now.hy,now.t+1});
//				else if(dgn[now.px][now.py-1]=='#'&&dgn[now.hx][now.hy-1]=='.')
//					q.push((status){now.px,now.py,now.hx,now.hy-1,now.px,now.py,now.hx,now.hy,now.t+1});
				break;
			case 'E':
				if(dgn[now.px][now.py-1]=='.'&&dgn[now.hx][now.hy+1]=='.')
					q.push((status){now.px,now.py-1,now.hx,now.hy+1,now.px,now.py,now.hx,now.hy,now.t+1});
				else if(dgn[now.px][now.py-1]=='.'&&dgn[now.hx][now.hy+1]=='#')
					q.push((status){now.px,now.py-1,now.hx,now.hy,now.px,now.py,now.hx,now.hy,now.t+1});
//				else if(dgn[now.px][now.py-1]=='#'&&dgn[now.hx][now.hy+1]=='.')
//					q.push((status){now.px,now.py,now.hx,now.hy+1,now.px,now.py,now.hx,now.hy,now.t+1});
				break;
		}
		switch(eh)
		{
			case 'N':
				if(dgn[now.px][now.py+1]=='.'&&dgn[now.hx-1][now.hy]=='.')
					q.push((status){now.px,now.py+1,now.hx-1,now.hy,now.px,now.py,now.hx,now.hy,now.t+1});
				else if(dgn[now.px][now.py+1]=='.'&&dgn[now.hx-1][now.hy]=='#')
					q.push((status){now.px,now.py+1,now.hx,now.hy,now.px,now.py,now.hx,now.hy,now.t+1});
//				else if(dgn[now.px][now.py+1]=='#'&&dgn[now.hx-1][now.hy]=='.')
//					q.push((status){now.px,now.py,now.hx-1,now.hy,now.px,now.py,now.hx,now.hy,now.t+1});
				break;
			case 'S':
				if(dgn[now.px][now.py+1]=='.'&&dgn[now.hx+1][now.hy]=='.')
					q.push((status){now.px,now.py+1,now.hx+1,now.hy,now.px,now.py,now.hx,now.hy,now.t+1});
				else if(dgn[now.px][now.py+1]=='.'&&dgn[now.hx+1][now.hy]=='#')
					q.push((status){now.px,now.py+1,now.hx,now.hy,now.px,now.py,now.hx,now.hy,now.t+1});
//				else if(dgn[now.px][now.py+1]=='#'&&dgn[now.hx+1][now.hy]=='.')
//					q.push((status){now.px,now.py,now.hx+1,now.hy,now.px,now.py,now.hx,now.hy,now.t+1});
				break;
			case 'W':
				if(dgn[now.px][now.py+1]=='.'&&dgn[now.hx][now.hy-1]=='.')
					q.push((status){now.px,now.py+1,now.hx,now.hy-1,now.px,now.py,now.hx,now.hy,now.t+1});
				else if(dgn[now.px][now.py+1]=='.'&&dgn[now.hx][now.hy-1]=='#')
					q.push((status){now.px,now.py+1,now.hx,now.hy,now.px,now.py,now.hx,now.hy,now.t+1});
//				else if(dgn[now.px][now.py+1]=='#'&&dgn[now.hx][now.hy-1]=='.')
//					q.push((status){now.px,now.py,now.hx,now.hy-1,now.px,now.py,now.hx,now.hy,now.t+1});
				break;
			case 'E':
				if(dgn[now.px][now.py+1]=='.'&&dgn[now.hx][now.hy+1]=='.')
					q.push((status){now.px,now.py+1,now.hx,now.hy+1,now.px,now.py,now.hx,now.hy,now.t+1});
				else if(dgn[now.px][now.py+1]=='.'&&dgn[now.hx][now.hy+1]=='#')
					q.push((status){now.px,now.py+1,now.hx,now.hy,now.px,now.py,now.hx,now.hy,now.t+1});
//				else if(dgn[now.px][now.py+1]=='#'&&dgn[now.hx][now.hy+1]=='.')
//					q.push((status){now.px,now.py,now.hx,now.hy+1,now.px,now.py,now.hx,now.hy,now.t+1});
				break;
		}
	}
	cout<<"Impossible"<<endl;
	return 0;
}
