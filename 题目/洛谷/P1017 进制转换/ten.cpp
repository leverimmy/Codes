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

using namespace std;

const char mod[] = "0123456789ABCDEFGHIJ";

int n, r;

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

//余数的负号与被除数相同
void solve(int n, int r)
{
	if(n == 0)
		return;
	int m = n % r;
	if(m < 0)
	{
		m -= r;
		n += r;
	}
	solve(n / r, r);
	printf("%c", mod[m]);
}

int main()
{
	n = read();
	r = read();
	printf("%d=", n);
	solve(n, r);
	printf("(base%d)", r);
	return 0;
}

