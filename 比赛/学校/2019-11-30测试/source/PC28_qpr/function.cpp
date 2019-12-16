#include<cstdio>
#include<iostream>
#include<algorithm>
//#include<cstring>
using namespace std;
int n,ans;
//int f[1005][1005];
struct blublu
{
	int x;
	int y;
}p[1005];
int _(int a,int b,int num,int la,int lb)
{
	if(num==n+1)
	{
		return 0;
	}
	if(a>la&&b>lb)
	{
		return max(_(p[num+1].x,p[num+1].y,num+1,a,b)+1,_(p[num+1].x,p[num+1].y,num+1,la,lb));
	}
	else
	{
		return _(p[num+1].x,p[num+1].y,num+1,la,lb);
	}
}
int main()
{
	freopen("function.in","r",stdin);
	freopen("function.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i].x>>p[i].y;
	}
//	memset(f,-1,sizeof(-1));
	cout<<_(p[1].x,p[1].y,1,-0x3f3f3f3f,-0x3f3f3f3f);
	return 0;
}
/*
8
1 3
3 2
1 1
4 5
6 3
9 9
8 7
7 6
*/
