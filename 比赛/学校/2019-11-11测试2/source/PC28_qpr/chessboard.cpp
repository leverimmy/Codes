#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int _map[1005][1005],n,k,m,book[1005][1005];
int t[3][2]={{2,0},{0,2},{1,1}},nx,ny;
int cnt,c[100005],x1[100005],y1[100005],x2[100005],y2[100005];
char a[100005][6];
struct blublu
{
	int mean;
	int nxt;
}b[100005];
void paint(int co,int a1,int b1,int a2,int b2)
{
	for(int i=0;i<=2;i++)
	{
		nx=a1;
		ny=b1;
		nx+=t[i][0];
		ny+=t[i][1];
 		if(nx>a2||ny>b2||book[nx][ny]==1)
		{
			continue;
		}
		book[nx][ny]=1;
		_map[nx][ny]=co;
		paint(co,nx,ny,a2,b2);
	}	
	return;
}
void _pass(int x)
{
	int y=0,z=0;
	for(int i=x;i>=1;i--)
	{
		if(b[i].mean>0)
		{
			y=b[i].mean;
			z=i;
			break;
		}
	}
	for(int i=z-1;i>=1;i--)
	{
		if(b[i].mean==0-y)
		{
			b[i].nxt=z;
			_pass(i);
			return;
		}
	}
	return;
}
int main()
{
	freopen("chessboard.in","r",stdin);
	freopen("chessboard.out","w",stdout);
	cin>>n>>k>>m;
	for(int i=0;i<=n-1;i++)
	{
		for(int j=0;j<=n-1;j++)
		{
			_map[i][j]=1;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
		if(a[i][0]=='S')
		{
			cnt++;
			b[i].mean=0-cnt;
			continue;
		}
		if(a[i][0]=='L')
		{
			cin>>b[i].mean;
			continue;
		}
		if(a[i][0]=='P')
		{
			b[i].mean=0;
			cin>>c[i]>>x1[i]>>y1[i]>>x2[i]>>y2[i];
			continue;
		}
	}
	_pass(m);
	for(int i=1;i<=m;i++)
	{
		if(b[i].mean==0)
		{
			book[x1[i]][y1[i]]=1;
			_map[x1[i]][y1[i]]=c[i];		
			paint(c[i],x1[i],y1[i],x2[i],y2[i]);			
			memset(book,0,sizeof(book));
		}
		if(b[i].nxt!=0)
		{
			i=b[i].nxt;
		}
	}
	for(int i=0;i<=n-1;i++)
	{
		for(int j=0;j<=n-1;j++)
		{
			cout<<_map[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
/*
4 3 2
PAINT 2 0 0 3 3
PAINT 3 0 3 3 3
*/
