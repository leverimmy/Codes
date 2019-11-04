#include <cstdio>
#include <cstring>
#include <cctype>
#define rgi register int
#define il inline
#define ll long long
#define maxn 50

using namespace std;

int n, ans;
int vis[maxn], a[maxn][2];

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

void dfs(int step)
{
	if(step == n + 1)
	{
		ans++;
		return;
	}
	for(rgi i = 1; i <= n; ++i)
		for(rgi j = 0; j <= 1; ++j)
		{
			if((a[step][j] == i) && (!vis[i]))
			{
				vis[i] = 1;
				dfs(step + 1);
				vis[i] = 0;
			}
		}
}

int main()
{
	n = read();
	for(rgi i = 1; i <= n; ++i)
	{
		a[i][0] = read();
		a[i][1] = read();
	}
	dfs(1);
	if(n == 0)
		putchar('0');
	else
		write(ans);
	return 0;
}

