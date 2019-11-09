#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn=2*1e5+1;
const int INF=0x3f3f3f3f;
int n;
struct ballon
{
	float cdn,br,nr;
	//cdn代表这个气球的x坐标
	//br代表这个气球膨胀的最大半径
	//nr代表这个气球现在的半径，同时也是圆心的高度
};
ballon bl[maxn];
inline bool cmp(ballon x, ballon y)
{
	return (x.cdn)<(y.cdn);
}
inline float mins(float x, float y)
{
	return x<y?x:y;
}
//令1s膨胀1cm
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cin>>n;
	for(register int i=1;i<=n;i++)
		cin>>bl[i].cdn>>bl[i].br;
	sort(bl+1,bl+n+1,cmp);
	//从第一个开始膨胀
	for(register int i=1;i<=n;i++)
	{
		if(i==1)
		{
			bl[i].nr=bl[i].br;
			continue;
		}
		float maxr=INF;
		maxr=mins(maxr,bl[i].br);
		for(register int j=i-1;j>=1;j--)
			maxr=mins(maxr,bl[j].nr+(bl[i].cdn-bl[j].cdn)*(bl[i].cdn-bl[j].cdn)/4/bl[i].nr);
		bl[i].nr=maxr;
	}
	for(register int i=1;i<=n;i++)
		printf("%.4f\n",bl[i].nr);
}
/*
3
0 9
8 1
13 7
*/