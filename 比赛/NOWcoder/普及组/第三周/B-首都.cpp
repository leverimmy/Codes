#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int minn=2144444444,maxx=-2144444444,maxy=-2144444444;
int dis=2144444444,minx=2144444444,miny=2144444444;
int tdis,cnt,n;
int x[100010],y[100010];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&x[i],&y[i]);
		if(maxx<x[i])    maxx=x[i];
		if(minx>x[i])    minx=x[i];
		if(maxy<y[i])    maxy=y[i];
		if(miny>y[i])    miny=y[i];
	}
	for(int i=minx;i<=maxx;i++)
		for(int j=miny;j<=maxy;j++)
		{
			for(int k=1;k<=n;k++)
				tdis+=abs(x[k]-i)+abs(y[k]-j);
			if(tdis<dis)	dis=tdis;
			tdis=0;
		}
	for(int i=minx;i<=maxx;i++)
		for(int j=miny;j<=maxy;j++)
		{
			for(int k=1;k<=n;k++)
				tdis+=abs(x[k]-i)+abs(y[k]-j);
			if(tdis==dis)	cnt++;
			tdis=0;
		}
	printf("%d\n",dis);
	printf("%d",cnt);
	return 0;
}