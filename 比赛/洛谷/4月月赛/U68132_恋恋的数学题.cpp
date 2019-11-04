#include <cstdio>
#include <cstring>
#include <cctype>
#define rgi register int
#define il inline
#define ll long long

using namespace std;

int T, k;

il ll read()
{
	register ll x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

il void write(ll x)
{
	if(x < 0)	putchar('-'), x = -x;
	if(x > 9)	write(x / 10);
	putchar(x % 10 + 48);
}

int main()
{
	T = read(), k = read();
	while(T--)
	{
		if(k == 2)
		{
			ll GCD, LCM;
			GCD = read();
			LCM = read();
			write(GCD);
			putchar(' ');
			write(LCM);
			putchar('\n');
		}
	}
	return 0;
}

