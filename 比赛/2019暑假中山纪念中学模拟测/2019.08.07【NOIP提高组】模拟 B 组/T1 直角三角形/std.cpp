#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register int

using namespace std;

const int N = 1500 + 10;

int n, cnt;
ll x[N], y[N];

struct node
{
	ll x, y;
	int quad;
} tmp[N];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

bool cmp(struct node a, struct node b)
{
	return a.x * b.y > a.y * b.x;
}

void Rotate(int p)
{
	swap(tmp[p].x, tmp[p].y);
	tmp[p].y = -tmp[p].y;
	tmp[p].quad = (tmp[p].quad + 1) % 4;
}

int main()
{
	n = read();
	for(rgi i = 1; i <= n; ++i)
	{
		x[i] = read();
		y[i] = read();
	}
	for(rgi i = 1; i <= n; ++i)//枚举直角顶点
	{
		for(rgi j = 1; j <= n; ++j)//移动平面直角坐标系
		{
			tmp[j].x = x[j] - x[i];
			tmp[j].y = y[j] - y[i];
			tmp[j].quad = 0;
			if(i == j)//强行给原点定一个坐标
			{
				tmp[j].x = tmp[1].x;
				tmp[j].y = tmp[1].y;
				tmp[j].quad = tmp[1].quad;
			}
			else
				while(tmp[j].x <= 0 || tmp[j].y < 0)//旋转到第一象限
					Rotate(j);
		}
		sort(tmp + 2, tmp + n + 1, cmp);//按照角度排序
		int j = 2;
		while(j <= n)//统计答案
		{
			int ans[4] = {0};
			int k = j;
			while(k <= n && tmp[j].x * tmp[k].y == tmp[j].y * tmp[k].x)//在同一直线上 
				ans[tmp[k].quad]++, k++;
			for(rgi l = 0; l <= 3; ++l)//相邻象限才能构成直角 
				cnt += ans[l] * ans[(l + 1) % 4];
			j = k;
		}
	}
	printf("%d", cnt);
	return 0;
}

