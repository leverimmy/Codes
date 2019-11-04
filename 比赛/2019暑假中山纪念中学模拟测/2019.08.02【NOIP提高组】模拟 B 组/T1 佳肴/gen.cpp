#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cctype>
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

int random(int l, int r)
{
	if(l == r)
		return l;
	return rand() * rand() % (r - l) + l;
}

int main()
{
	srand(time(0));
	freopen("testdata.in", "w", stdout);
	int n = 10;
	printf("%d\n", n);
	for(rgi i = 1; i <= n; ++i)
	{
		int a = random(-9, 9);
		printf("%d ", a);
		int b = random(-9, 9);
		while(a == b)
			b = random(-9, 9);
		printf("%d\n", b);
	}
	return 0;
}

