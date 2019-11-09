#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
struct ver
{
	double x,y;
	int id;
	ver(double a=0,double b=0){x=a,y=b;}
}q[1000001],p[1000001];
bool cmp(ver a,ver b){return a.x<b.x;}
const double eps=1e-6; 
const double inf=999999999;
double slope(ver a,ver b)
{
	if(fabs(a.x-b.x)<eps) return inf;
	return (a.y-b.y)/(a.x-b.x);
}
double eva(ver a,double x)
{
	return slope(a,ver(x,0));
}
int head=1,tail=0;
double ans[1000001];
signed main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lf%lf",&p[i].x,&p[i].y),p[i].id=i;
	sort(p+1,p+n+1,cmp);
	ans[1]=p[1].y;
	q[++tail]=ver(p[1].x,-sqrt(p[1].y));
	for(int i=2;i<=n;i++)
	{
		while(head<tail&&eva(q[tail],p[i].x)<=eva(q[tail-1],p[i].x)) 
			tail--;
			
		ans[p[i].id]=min(p[i].y,(p[i].x-q[tail].x)*(p[i].x-q[tail].x)/(4*q[tail].y*q[tail].y));
		
		while(head<tail&&slope(q[tail-1],q[tail])>=slope(q[tail],ver(p[i].x,-sqrt(ans[p[i].id]))))
			tail--;
		q[++tail]=ver(p[i].x,-sqrt(ans[i]));
	}
	for(int i=1;i<=n;i++)
		printf("%.20lf\n",ans[i]);
}
/*
3 
0 9 
8 1 
13 7
*/