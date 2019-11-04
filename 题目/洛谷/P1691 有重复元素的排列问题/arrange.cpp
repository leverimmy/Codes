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
#define maxn 510

using namespace std;

int n, cnt = 1;
char a[maxn], b[maxn];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
	n = read();
	scanf("%s", a);
	sort(a, a + n);
	strcpy(b, a);
	puts(a);
	while(next_permutation(a, a + n))
	{
		if(!strcmp(a, b))
			continue;
		printf("%s\n", a);
		cnt++;
	}
	printf("%d", cnt);
	return 0;
}

