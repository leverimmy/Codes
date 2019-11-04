#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cctype>
#define rgi register int
#define il inline
#define ll long long
#define maxn 50

using namespace std;

int TASKS, n, ans, len1, len2, s1, s2;
int belong[3][maxn];
double T;

const double k = 0.997;
const int inf = 0x3f3f3f3f;

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

il int calc()
{
	return abs(s1 - s2);
}

il void my_swap(int a, int b)
{
	s1 -= belong[1][a];
	s2 -= belong[2][b];
	s1 += belong[2][b];
	s2 += belong[1][a];
	swap(belong[1][a], belong[2][b]);
}

il void SA()
{
	T = 5000;
	int cur_ans = ans;
	while(T > 1e-10)
	{
		int x = rand() % len1 + 1;
		int y = rand() % len2 + 1;
		my_swap(x, y);
		int temp = calc();
		int delta = temp - cur_ans;
		if(delta < 0)
		{
			cur_ans = temp;
			if(ans > cur_ans)
				ans = cur_ans;
		}
		else if(exp(-delta / T)*RAND_MAX > rand())
			cur_ans = temp;
		else
			my_swap(x, y);
		T *= k;
	}
}

int main()
{
	srand(20040301);
	TASKS = read();
	while(TASKS--)
	{
		s1 = s2 = 0;
		memset(belong, 0, sizeof(belong));
		n = read();
		len1 = n >> 1;
		len2 = n - len1;
		for(rgi i = 1; i <= len1; ++i)
		{
			belong[1][i] = read();
			s1 += belong[1][i];
		}
		for(rgi i = len1 + 1; i <= n; ++i)
		{
			belong[2][i - len1] = read();
			s2 += belong[2][i - len1];
		}
		ans = calc();
		if(n == 1)
		{
			write(ans);
			putchar('\n');
			continue;
		}
		for(rgi i = 1; i <= 20; ++i)
			SA();
		write(ans);
		putchar('\n');
	}
	return 0;
}

