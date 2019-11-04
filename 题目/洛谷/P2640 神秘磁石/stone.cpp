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
#define maxn 10010

using namespace std;

int n, k, tot, flag;
int p[maxn];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

bool check(int x)
{
	if(x < 2)
		return 0;
	for(rgi i = 2; i * i <= x; ++i)
		if(x % i == 0)
			return 0;
	return 1;
}

int main()
{
	n = read(), k = read();
	for(rgi i = 1; i <= n; ++i)
		if(check(i))
			p[++tot] = i;
	for(rgi i = 1; i <= n; ++i)
		for(rgi j = i + 1; j <= n; ++j)
			if(p[j] - p[i] == k)
			{
				flag = 1;
				printf("%d %d\n", p[i], p[j]);
			}
	if(!flag)
		puts("empty");
	return 0;
}

