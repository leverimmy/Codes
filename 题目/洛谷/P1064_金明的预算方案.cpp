#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;
int f[3500];
int w[70][3];
int c[70][3];
int v,n,x,y,p,last;
int main()
{
	scanf("%d %d",&v,&n);
	v=v/10;
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d %d",&x,&y,&p);
		x=x/10;
		y=y*x;
		if(p)
		{
			if(w[p][1]==0)
			{
				w[p][1]=x;
				c[p][1]=y;
			}
			else
			{
				w[p][2]=x;
				c[p][2]=y;
			}
		}
		else
		{
			w[i][0]=x;
			c[i][0]=y;
			last=i;
		}
	}
	for(int i=1;i<=last;i++)
	{
		if(w[i][0]==0)
			continue;
		for(int j=v;j>=w[i][0];j--)
		{
			f[j]=max(f[j],f[j-w[i][0]]+c[i][0]);
			if(j>=w[i][0]+w[i][1])
				f[j]=max(f[j],f[j-w[i][0]-w[i][1]]+c[i][0]+c[i][1]);
			if(j>=w[i][0]+w[i][2])
				f[j]=max(f[j],f[j-w[i][0]-w[i][2]]+c[i][0]+c[i][2]);
			if(j>=w[i][0]+w[i][1]+w[i][2])
				f[j]=max(f[j],f[j-w[i][0]-w[i][1]-w[i][2]]+c[i][0]+c[i][1]+c[i][2]);
		}
	}
	printf("%d",f[v]*10);
	return 0;
}