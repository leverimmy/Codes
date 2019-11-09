#include <bits/stdc++.h>
using namespace std;

int read()
{
	int res=0,p=1;char ch=getchar();
	while(!isdigit(ch)) {if(ch=='-')p=-1; ch=getchar();}
	while(isdigit(ch)) res=res*10+ch-'0',ch=getchar();
	return res*p;
}

int n,m;
double r[200010];
double maxr;

struct note
{
	int x;
	double r;
}ball[200010];

bool cmp(note a,note b)
{
	return a.x<b.x;
}

int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
	{
		ball[i].x=read(),ball[i].r=read();
	}
	sort(ball+1,ball+1+n,cmp);
	r[1]=ball[1].r;
	maxr=ball[1].x+ball[1].r;
	for(int i=2;i<=n;i++)
	{
		r[i]=ball[i].r;
		if(ball[i].x-r[i]>maxr)
		{
			maxr=ball[i].x+r[i];
			continue;
		}
		for(int j=i-1;j>=1;j--)
		{
			double k=(ball[i].x-ball[j].x)*(ball[i].x-ball[j].x)*1.0/4/r[j];
			r[i]=min(r[i],k);
		}
		maxr=max(maxr,ball[i].x+r[i]);
	}
	for(int i=1;i<=n;i++) printf("%.3lf\n",r[i]);
	return 0;
}
