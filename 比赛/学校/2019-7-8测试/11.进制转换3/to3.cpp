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

int n, p;

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

const char out[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void print(int x)
{
	if(x <= p - 1)
		printf("%c", out[x]);
	else
	{
		print(x / p);
		printf("%c", out[x % p]);
	}
}

int main()
{
	n = read(), p = read();
	print(n);
	return 0;
}

