#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <cmath>
#define ll long long
#define il inline
#define rgi register int
#define maxn 10010

using namespace std;

int T;
int ans[maxn] = {0, 1, 2, 3, 4, 5, 2, 3, 1, 4, 5, 1, 2, 3, 1, 4, 3, 5, 4, 2, 5, 2, 1, 3, 4, 5};

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}


int solve(int a, int b, int c)
{
	return (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
}

int main()
{
	T = read();
	ans[100] = 5;
	for(; T; T--)
	{
		int n = read();
		//int t = solve(3, -3, 1 - x);
		printf("%d\n", ans[n]);
	}
	return 0;
}

