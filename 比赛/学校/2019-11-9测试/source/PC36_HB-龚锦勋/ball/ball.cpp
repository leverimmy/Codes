#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int read()
{
	int x=0,y=1;char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')y=-1;
		c = getchar();
	}
	while(c>='0'&&c<='9')
		x = x*10+c-'0',c=getchar();
	return (x*y);
}

int n;
struct Ballen{
	int x,r;
	double nr;
} xr[200000];

int cmp(Ballen a,Ballen b)
{
	return (a.x<b.x);
}

double dis(double x1,double y1,double x2,double y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	
	n = read();
	for(int i=0;i<n;i++)
		xr[i].x = read(),xr[i].r = read();	
	
//	sort(xr,xr+n,cmp);
	
	for(int i=0;i<n;i++)
	{
//		//尝试放满
//		int f=1;
//		for(int j=0;j<i;j++)
//		{
//			if(dis(xr[j].x,xr[j].nr,xr[i].x,xr[i].r)>xr[j].nr+xr[i].r)
//			{
//				f=0;
//				break;
//			}
//		}
//		if(f)
//		{
//			xr[i].nr = xr[i].r;	
//		}
//		else//充适当的气体 
//		{
//			//.....
//		}
//		printf("%.3lf\n",(double)xr[i].nr);
		printf("%.3lf\n",(double)xr[i].r);
	}	
	
	return 0;
}

