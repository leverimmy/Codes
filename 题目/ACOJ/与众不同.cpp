#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#define il inline
#define rgi register int
#define maxn 2000050
#define POS 1000010

using namespace std;

int n, m, lg2[maxn];
int s[maxn], last[maxn];
int a[maxn], f[maxn][50];
//f[i][j] -> [i , i+2^{j}-1] max ... a[i]


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

int RMQ(int l, int r)
{
	int len = lg2[r - l + 1];
	return max(f[l][len], f[r - (1 << len) + 1][len]);
}

int Binary_Search(int l, int r)
{
	int left = l, right = r;
	if(l == r)
		return l;
	while(left <= right)
	{
		int mid = (left + right) >> 1;
		if(s[mid] < l)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return left;
}

int main()
{
	n = read(), m = read();
	for(rgi i = 2; i <= n; ++i)
		lg2[i] = lg2[i >> 1] + 1;
	for(rgi i = 1; i <= n; ++i)
	{
		a[i] = read();
		s[i] = max(s[i - 1], last[POS + a[i]] + 1);
		last[POS + a[i]] = i;
		f[i][0] = i - s[i] + 1;
	}
	for(rgi j = 1; j <= lg2[n] + 1; ++j)
		for(rgi i = 1; i + (1 << j) - 1 <= n; ++i)
			f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
	for(rgi i = 1; i <= m; ++i)
	{
		int l = read() + 1, r = read() + 1;
		int pos = Binary_Search(l, r);
		if(s[l] == l)
			write(RMQ(l, r)), putchar('\n');
		else if(s[r] <= l)
			write(r - l + 1), putchar('\n');
		else
			write(max(pos - l, RMQ(pos, r))), putchar('\n');
	}
	return 0;
}
