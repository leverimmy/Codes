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
#define maxn 1000010

using namespace std;

int n, m;
int p[maxn] = {0, 0, 1}, s[maxn] = {0, 0, 1, 1};

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

bool is_prime(int x)
{
	if(x < 2)
		return 0;
	int t = sqrt(x);
	for(rgi i = 2; i <= t; ++i)
		if(x % i == 0)
			return 0;
	return 1;
}

int main()
{
	for(rgi i = 1; i <= 1000010; ++i)
	{
		if(is_prime(i))
		{
			p[i] = 1;
			s[i] = s[i - 1] + 1;
		}
		else
			s[i] = s[i - 1];
	}
	n = read(), m = read();
	for(rgi i = 1; i <= n; ++i)
	{
		int l = read(), r = read();
		if(l < 1 || r > m)
			puts("Crossing the line");
		else
			printf("%d\n", s[r] - s[l - 1]);
	}
	return 0;
}

