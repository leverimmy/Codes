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
#define maxn 40010

using namespace std;

int n, tot, ans;
int e[maxn], is[100010], p[maxn];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void init()
{
	e[1] = 1;
	for(rgi i = 1; i <= n; ++i)
		is[i] = 1;
	for(rgi i = 2; i <= n; ++i)
	{
		if(is[i])
		{
			p[++tot] = i;
			e[i] = i - 1;
		}
		for(rgi j = 1; j <= tot && i * p[j] <= n; ++j)
		{
			is[i * p[j]] = 0;
			if(i % p[j] == 0) //p[j] is a prime number so currently they are not huzhi
			{
				e[i * p[j]] = e[i] * p[j];
				break;
			}
			else//now they are huzhi
				e[i * p[j]] = e[i] * e[p[j]];//jixing hanshu
		}
	}
}

int main()
{
	n = read();
	init();
	for(rgi i = 2; i <= n - 1; ++i)
		ans += e[i];
	if(n == 1)
		puts("0");
	else
		printf("%d", 2 * ans + 3);
	return 0;
}

