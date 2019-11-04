#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register int

using namespace std;

const int N = 10000 + 10;

int n, k;
int hang[N], lie[N];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int Ceil(int num, int k)
{
	if(num % k == 0)
		return num / k;
	return num / k + 1;
}

int getx(int val)
{
	return Ceil(val, n);
}

int gety(int val)
{
	if(val % n == 0)
		return n;
	return val % n;
}

int main()
{
//	freopen("testdata.in", "r", stdin);
//	freopen("my.out", "w", stdout);
	n = read(), k = read();
	for(rgi i = 1; i <= k; ++i)
	{
		int val = read(), x = read(), y = read();
		int startx = getx(val), starty = gety(val);
		int	cur_y;
		if((starty + hang[startx]) % n == 0)
			cur_y = n;
		else
			cur_y = (starty + hang[startx]) % n;
		int	cur_x;
		if((startx + lie[cur_y]) % n == 0)
			cur_x = n;
		else
			cur_x = (startx + lie[cur_y]) % n;
		int h = (y - cur_y + n) % n;
		int l = (x - cur_x + n) % n;
		hang[cur_x] += (y - cur_y + n) % n;
		lie[y] += (x - cur_x + n) % n;
		printf("%d\n", h + l);
	}
	return 0;
}

