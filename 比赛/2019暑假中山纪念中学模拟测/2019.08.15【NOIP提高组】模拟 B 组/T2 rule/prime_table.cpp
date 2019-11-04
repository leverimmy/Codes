#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register int
#define rgl register ll

using namespace std;

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
	for(rgi i = 2; i <= x / i; ++i)
		if(x % i == 0)
			return 0;
	return 1;
}

int main()
{
	int ans = 0;
//	freopen("table.txt", "w", stdout);
	for(rgi i = 1; i<=700001; ++i)
		if(is_prime(i))
		{
			ans++;
		}
		printf("%d",ans);
	return 0;
}

