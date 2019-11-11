#include <bits/stdc++.h>
#define rgi register int
#define pii pair<int,int>
#define mkp make_pair
#define fi first
#define se second
using namespace std;
const int maxn=505;
int n,m,b[maxn][maxn],stx,sty,edx,edy;
string a[maxn];
bool book[maxn][maxn];
const int dx[]={0,-1,0,1};
const int dy[]={1,0,-1,0};
struct sta
{
	int x,y,val;
	inline bool operator <(const sta &rhs)const
	{
		return val>rhs.val;
	}
}
void bfs(int sx,int sy)
{
	queue<sta> q;
	q.push(sta{sx,sy,0});
	book[sx][sy]=1;
	while(!q.empty())
	{
		int tx=q.front().x,ty=q.front().y,val=q.front().val;
		b[tx][ty]=min(b[tx][ty],val);
		q.pop();
		for(rgi i=0;i<4;++i)
		{
			int ttx=tx+dx[i],tty=ty+dy[i];
			if(book[ttx][tty]||ttx<0||ttx>=n||tty<0||tty>=m)
				continue;
			book[ttx][tty]=1;
			q.push(sta{ttx,tty,val+1});
		}
	}
}
int spfa()
{
	priority_queue<sta> que;
	que.push(sta{stx,sty,b[stx][sty]});
	while(!que.empty())
	{
		
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("escape.in","r",stdin);
	freopen("escape.out","w",stdout);
	memset(b,0x3f,sizeof(b));
	cin>>n;
	for(rgi i=0;i<n;++i)
		cin>>a[i];
	for(rgi i=0;i<n;++i)
		for(rgi j=0;j<m;++j)
		{
			if(a[i][j]=='+')
			{
				memset(book,0,sizeof(book));
				bfs(i,j);
			}
			else if(a[i][j]=='V')
				stx=i,sty=j;
			else if(a[i][j]=='J')
				edx=i,edy=j;
		}
	cout<<spfa()<<endl;
	return 0;
}

