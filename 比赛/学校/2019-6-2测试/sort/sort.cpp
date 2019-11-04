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
#define maxn 210

using namespace std;

int n, pa, pb;

struct things
{
	int a;
	int b;
	int tot;
} t[maxn];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

il void write(int x)
{
	if(x < 0)    putchar('-'), x = -x;
	if(x > 9)    write(x / 10);
	putchar(x % 10 + 48);
}

bool cmp1(struct things A, struct things B)
{
	return A.b > B.b;
}

bool cmp2(struct things A, struct things B)
{
	return A.tot > B.tot;
}

int main()
{
	n = read();
	for(rgi i = 1; i <= n; ++i)
	{
		t[i].a = read();
		t[i].b = read();
	}
	sort(t + 1, t + n + 1, cmp1);
	for(rgi i = 1; i <= n; ++i)
	{
		if(pa > pb)
		{
			pb += t[i].a;
			t[i].tot += pb + t[i].b;
		}
		else
		{
			pa += t[i].a;
			t[i].tot += pa + t[i].b;
		}
	}
	sort(t + 1, t + n + 1, cmp2);
	write(t[1].tot);
	return 0;
}

