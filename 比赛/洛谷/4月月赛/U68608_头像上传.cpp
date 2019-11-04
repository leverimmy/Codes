#include <cstdio>
#include <cstring>
#include <cctype>
#define rgi register int
#define il inline
#define ll long long

using namespace std;

int n, L, G;

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

int main()
{
	n = read(), L = read(), G = read();
	for(rgi i = 1; i <= n; ++i)
	{
		int w, h;
		scanf("%d %d", &w, &h);
		while(w > G || h > G)
		{
			w >>= 1;
			h >>= 1;
		}
		if(w < L || h < L)
			puts("Too Young");
		else
		{
			if(w != h)
				puts("Too Simple");
			else if(w == h)
				puts("Sometimes Naive");
		}
	}
	return 0;
}

