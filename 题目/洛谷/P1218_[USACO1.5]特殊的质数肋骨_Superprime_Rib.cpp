#include <cstdio>
#include <cstring>
#include <cctype>
#define rgi register int
#define il inline
#define ll long long

using namespace std;

int n;

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

il void write(int x)
{
	if(x < 0)	putchar('-'), x = -x;
	if(x > 9)	write(x / 10);
	putchar(x % 10 + 48);
}

il int is_prime(int x)
{
	if(x < 2)
		return 0;
	for(rgi i = 2; i * i <= x; ++i)
		if(x % i == 0)
			return 0;
	return 1;
}

il void dfs(int cur, int step)
{
	if(step == n)
	{
		write(cur);
		putchar('\n');
		return;
	}
	for(rgi i = 1; i <= 9; ++i)
	{
		if(!(i & 1) || i == 5)
			continue;
		int num = (cur << 1) + (cur << 3) + i;
		if(is_prime(num))
			dfs(num, step + 1);
	}
}

int main()
{
	n = read();
	dfs(2, 1);
	dfs(3, 1);
	dfs(5, 1);
	dfs(7, 1);
	return 0;
}

