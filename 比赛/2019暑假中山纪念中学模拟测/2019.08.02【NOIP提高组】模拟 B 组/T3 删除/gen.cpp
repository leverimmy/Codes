#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <cctype>
#define ll long long
#define il inline
#define rgi register int

using namespace std;

int a[100010];

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
	int n = 100000;
	printf("%d\n", n);
	for(rgi i = 1; i <= n; ++i)
		a[i] = i;
	random_shuffle(a + 1, a + n + 1);
	for(rgi i = 1; i <= n; ++i)
		printf("%d " , a[i]);
	puts("");
	for(rgi i = 1; i <= n; ++i)
		printf("%d ", a[i]);
	puts("");
	for(rgi i = 1; i <= n; ++i)
		printf("%d ", a[i]);
	puts("");
	return 0;
}

