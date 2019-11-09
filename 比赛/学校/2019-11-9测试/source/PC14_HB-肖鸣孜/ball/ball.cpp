#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define min(a,b) a<b?a:b
using namespace std;
int n;
struct Ball
{
	double x,r;
} balls[200005];
bool cmp(Ball b1,Ball b2)
{
	return b1.x<b2.x;
}
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		balls[i].x=a*1.0,balls[i].r=b*1.0;
	}
	sort(balls,balls+n,cmp);
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
			balls[i].r=min((balls[i].x-balls[j].x)*(balls[i].x-balls[j].x)/(4.0*balls[j].r),balls[i].r);
	}
	for(int i=0;i<n;i++) printf("%.3f\n",balls[i].r);
	//system("pause");
	return 0;
} 
