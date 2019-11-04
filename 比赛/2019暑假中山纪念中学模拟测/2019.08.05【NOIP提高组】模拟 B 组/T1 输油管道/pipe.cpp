#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register int

using namespace std;

const int N = 25 + 10;

int n, m, startx, starty, endx, endy, ansx, ansy;
char ans, e[N][N];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

bool have_left(int x, int y)
{
	if(y - 1 >= 1 && (e[x][y - 1] == '-' || e[x][y - 1] == '+' || e[x][y - 1] == '1' || e[x][y - 1] == '2'))
		return 1;
	return 0;
}

bool have_up(int x, int y)
{
	if(x - 1 >= 1 && (e[x - 1][y] == '|' || e[x - 1][y] == '+' || e[x - 1][y] == '1' || e[x - 1][y] == '4'))
		return 1;
	return 0;
}

bool have_down(int x, int y)
{
	if(x + 1 <= n && (e[x + 1][y] == '|' || e[x + 1][y] == '+' || e[x + 1][y] == '2' || e[x + 1][y] == '3'))
		return 1;
	return 0;
}

bool have_right(int x, int y)
{
	if(y + 1 <= m && (e[x][y + 1] == '-' || e[x][y + 1] == '+' || e[x][y + 1] == '3' || e[x][y + 1] == '4'))
		return 1;
	return 0;
}

void dfs(int x, int y, int d, char last)
{
	//d: 1, from up; 2, down; 3, left; 4, right
	if(e[x][y] == 'M')
	{
		if(have_right(x, y))
			dfs(x, y + 1, 3, 'M');
		else if(have_left(x, y))
			dfs(x, y - 1, 4, 'M');
		else if(have_down(x, y))
			dfs(x + 1, y, 1, 'M');
		else if(have_up(x, y))
			dfs(x - 1, y, 2, 'M');
	}
	if(e[x][y] == '.')
	{
		if(d == 1)
		{
			if(have_down(x, y))
			{
				if(have_right(x, y) && have_left(x, y))
				{
					ansx = x, ansy = y;
					ans = '+';
					return;
				}
				else
				{
					ansx = x, ansy = y;
					ans = '|';
					return;
				}
			}
			else if(have_left(x, y))
			{
				ansx = x, ansy = y;
				ans = '3';
				return;
			}
			else if(have_right(x, y))
			{
				ansx = x, ansy = y;
				ans = '2';
				return;
			}
		}
		else if(d == 2)
		{
			if(have_up(x, y))
			{
				if(have_left(x, y) && have_right(x, y))
				{
					ansx = x, ansy = y;
					ans = '+';
					return;
				}
				else
				{
					ansx = x, ansy = y;
					ans = '|';
					return;
				}
			}
			else if(have_left(x, y))
			{
				ansx = x, ansy = y;
				ans = '4';
				return;
			}
			else if(have_right(x, y))
			{
				ansx = x, ansy = y;
				ans = '1';
				return;
			}
		}
		else if(d == 3)
		{
			if(have_right(x, y))
			{
				if(have_up(x, y) && have_down(x, y))
				{
					ansx = x, ansy = y;
					ans = '+';
					return;
				}
				else
				{
					ansx = x, ansy = y;
					ans = '-';
					return;
				}
			}
			else if(have_up(x, y))
			{
				ansx = x, ansy = y;
				ans = '3';
				return;
			}
			else if(have_down(x, y))
			{
				ansx = x, ansy = y;
				ans = '4';
				return;
			}
		}
		else if(d == 4)
		{
			if(have_left(x, y))
			{
				if(have_up(x, y) && have_down(x, y))
				{
					ansx = x, ansy = y;
					ans = '+';
					return;
				}
				else
				{
					ansx = x, ansy = y;
					ans = '-';
					return;
				}
			}
			else if(have_up(x, y))
			{
				ansx = x, ansy = y;
				ans = '2';
				return;
			}
			else if(have_down(x, y))
			{
				ansx = x, ansy = y;
				ans = '1';
				return;
			}
		}
	}
	else if(e[x][y] == '|')
	{
		if(d == 1)
			dfs(x + 1, y, 1, '|');
		else if(d == 2)
			dfs(x - 1, y, 2, '|');
	}
	else if(e[x][y] == '-')
	{
		if(d == 3)
			dfs(x, y + 1, 3, '-');
		else if(d == 4)
			dfs(x, y - 1, 4, '-');
	}
	else if(e[x][y] == '+')
	{
		if(d == 1)
			dfs(x + 1, y, 1, '+');
		else if(d == 2)
			dfs(x - 1, y, 2, '+');
		else if(d == 3)
			dfs(x, y + 1, 3, '+');
		else if(d == 4)
			dfs(x, y - 1, 4, '+');
	}
	else if(e[x][y] == '1')
	{
		if(d == 2)
			dfs(x, y + 1, 3, '1');
		else if(d == 4)
			dfs(x + 1, y, 1, '1');
	}
	else if(e[x][y] == '2')
	{
		if(d == 1)
			dfs(x, y + 1, 3, '2');
		else if(d == 4)
			dfs(x - 1, y, 2, '2');
	}
	else if(e[x][y] == '3')
	{
		if(d == 1)
			dfs(x, y - 1, 4, '3');
		else if(d == 3)
			dfs(x - 1, y, 2, '3');
	}
	else if(e[x][y] == '4')
	{
		if(d == 2)
			dfs(x, y - 1, 4, '4');
		else if(d == 3)
			dfs(x + 1, y, 1, '4');
	}
}

int main()
{
	n = read(), m = read();
	for(rgi i = 1; i <= n; ++i)
		scanf("%s", e[i] + 1);
	for(rgi i = 1; i <= n; ++i)
		for(rgi j = 1; j <= m; ++j)
		{
			if(e[i][j] == 'M')
			{
				startx = i;
				starty = j;
			}
			if(e[i][j] == 'Z')
			{
				endx = i;
				endy = j;
			}
		}
	dfs(startx, starty, 0, ' ');
	printf("%d %d %c", ansx, ansy, ans);
	return 0;
}

