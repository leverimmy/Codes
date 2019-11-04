#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <cctype>
#define rgi register int
#define il inline
#define ll long long
#define maxn 20

using namespace std;

int n, cnt;
double maxx = -99999, minx = 99999, maxy = -99999, miny = 99999;
double x1[maxn], x2[maxn], __y1[maxn], y2[maxn];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

il void write(int x)
{
	if(x < 0)    putchar('-'), x = -x;
	if(x > 9)    write(x / 10);
	putchar(x % 10 + 48);
}

int main()
{
	n = read();
	for(rgi i = 1; i <= n; ++i)
	{
		x1[i] = read();
		__y1[i] = read();
		x2[i] = read();
		y2[i] = read();
		/*
		maxx = max(maxx, (int)x2[i]);
		minx = min(minx, (int)x1[i]);
		maxy = max(maxy, (int)__y1[i]);
		miny = min(miny, (int)y2[i]);
		*/
		maxx = max((int)maxx, (int)x2[i]);
		minx = min((int)minx, (int)x1[i]);
		maxy = max((int)maxy, (int)__y1[i]);
		miny = min((int)miny, (int)y2[i]);
		/*
		x1[i] -= 0.5;
		__y1[i] += 0.5;
		x2[i] += 0.5;
		y2[i] -= 0.5;
		*/
	}
	for(register double i = minx + 0.5; i <= maxx - 0.5; i++)
		for(register double j = miny + 0.5; j <= maxy - 0.5; j++)
		{
			int flag = 0;
			for(rgi k = 1; k <= n; ++k)
				if(x1[k] <= i && i <= x2[k] && __y1[k] >= j && j >= y2[k])
					flag = 1;
			if(flag)
				cnt++;
		}
	write(cnt);
	return 0;
}
