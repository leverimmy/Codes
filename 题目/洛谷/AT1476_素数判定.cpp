#include <cstdio>
#include <cstring>
#include <cctype>
#define rgi register int
#define il inline
#define ll long long

using namespace std;

int n;

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

il void write(int x)
{
	if(x < 0)	putchar('-'), x = -x;
	if(x > 9)	write(x / 10);
	putchar(x % 10 + 48);
}

int is_prime(int x)
{
	if(x < 2)
		return 0;
	for(rgi i = 2; i * i <= x; ++i)
		if(x % i == 0)
			return 0;
	return 1;
}

int is_sim(int x)
{
	if(x == 1 || x % 5 == 0 || x % 2 == 0)
		return 0;
	int tot = 0;
	while(x)
	{
		tot += x % 10;
		x /= 10;
	}
	if(tot % 3 == 0)
		return 0;
	return 1;
}

int main()
{
	n = read();
	if(is_prime(n) || is_sim(n))
		puts("Prime");
	else
		puts("Not Prime");
	return 0;
}

