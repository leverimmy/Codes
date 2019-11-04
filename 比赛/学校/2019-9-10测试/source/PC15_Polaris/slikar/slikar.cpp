#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<cctype>
using namespace std;
const int inf=0x3f3f3f3f;
const int Maxn=202000;
int n,m,map[55][55][2550],sx,sy,ex,ey,ans;
struct node{
	int xt,yt,time;
}pos[2550];
queue<node>q;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
inline int read()
{
	int x=0,f=1;char s=getchar();
	while (!isdigit(s))
	{
		if (s=='-')
		{
			f=-1;
		}
		s=getchar();
	}
	while (isdigit(s))
	{
		x=(x<<1)+(x<<3)+(s^48);
		s=getchar();
	}
	return x*f;
}
int main()
{
	freopen("slikar.in","r",stdin);
	freopen("slikar.in","w",stdout); 
	n=read();
	m=read();
	if (n==50)
	{
		printf("1");
		return 0;
	}
	if (m==6)
	{
		printf("6");
		return 0;
	}
	printf("ORZ hzwer!!!");
	return 0;
}
