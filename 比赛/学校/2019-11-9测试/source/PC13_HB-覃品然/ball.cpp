#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
double R[200005];
int n;
struct blublu
{
	int x;
	int r;
}ball[200005];
int read()
{
	int x=0,f=0;
	char ch;
	while(!isdigit(ch=getchar()))
		if(ch=='-')
			f=1;
	while(isdigit(ch))
	{
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	if(f)
		return -x;
	else
		return x;
}
bool cmp(blublu a,blublu b)
{
	return a.x<b.x;
}
double solve(int x,double r)
{
	return x*x/(4*r);
}
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
	{
		R[i]=0x3f3f3f3f;
	}
	for(int i=1;i<=n;i++)
	{
		ball[i].x=read();
		ball[i].r=read();
	}
	sort(ball+1,ball+n+1,cmp);
	R[1]=ball[1].r;
	printf("%.3lf\n",R[1]);
	for(int i=2;i<=n;i++)
	{
		for(int j=i-1;j>=1;j--)
		{
			R[i]=min(solve(ball[i].x-ball[j].x,R[j]),R[i]);
		}
		R[i]=min(R[i],(double)ball[i].r);
		printf("%.3lf\n",R[i]);
	}
	return 0;
}
