#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#define il inline
#define ll long long
#define rgi register ll

using namespace std;

il ll read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
	ll a = read(), b = read();
	printf("%lld", a * b - a - b);
	return 0;
}

