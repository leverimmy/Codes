#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register int

using namespace std;

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int n, ans;

int check(int x)
{
	int res = 0;
	while(x)
	{
		x /= 10;
		res++;
	}
	return res;
}

int main()
{
	n = read();
	for(rgi i = 1; i <= n; ++i)
	{
		int cnt = check(i);
		if(cnt & 1)
			ans++;
	}
	printf("%d", ans);
	return 0;
}

