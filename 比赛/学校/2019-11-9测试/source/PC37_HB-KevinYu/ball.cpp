#include<cstdio>
#include<cstring>
#include<cassert>
#include<climits>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<iostream>
#include<map>
#include<stack>
#include<queue>
#include<vector>
#define ll long long
#define INF 0x3f3f3f3f
struct data
{
	double x,r,id;
}v[200020];
struct node
{
	double x,y;
	node(){}
	node(double x,double y):x(x),y(y){}
}que[200020];
bool operator <(data x,data y)
{
	return x.x>y.x;
}
double f(node x,node y)
{
	return (y.y-x.y)/(y.x-x.x);
}
double g(node x,double p)
{
	return f(x,node(p,0));
}
double p(double x)
{
	return x*x;
}
double ans[200020];
int h(1),t(0);
signed main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lf%lf",&v[i].x,&v[i].r);
		v[i].id=i;
	}
	std::sort(v+1,v+n+1);
	ans[1]=v[1].r;
	que[++t]=node(v[1].x,-sqrt(ans[1]));
	for(int i=2;i<=n;i++)
	{
		while(h<t&&g(que[h],v[i].x)>=g(que[h+1],v[i].x))
			h++;
		ans[v[i].id]=std::min(v[i].r,p(v[i].x-que[h].x)/(p(2.0*que[h].y)));
		while(h<t&&f(que[t-1],que[t])<=f(node(v[i].x,-sqrt(ans[i])),que[t]))
			t--;
		que[++t]=node(v[i].x,-sqrt(ans[i]));
	}
	for(int i=1;i<=n;i++)
		printf("%.12lf\n",ans[i]);
	return 0;
}
