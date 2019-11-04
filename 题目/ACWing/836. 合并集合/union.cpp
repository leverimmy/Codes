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
#define maxn 100010

using namespace std;

int n, m;
int p[maxn];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void init()
{
	for(rgi i = 1; i <= n; ++i)
		p[i] = i;
}

int find(int x)
{
	return x == p[x] ? x : p[x] = find(p[x]);
}

void uunion(int a, int b)
{
	int pa = find(a);
	int pb = find(b);
	if(pa != pb)
		p[pa] = pb;
}

int main()
{
	n = read(), m = read();
	init();
	for(rgi i = 1; i <= m; ++i)
	{
		char cmd[5];
		scanf("%s", cmd);
		int a = read(), b = read();
		if(cmd[0] == 'M')
			uunion(a, b);
		else if(cmd[0] == 'Q')
		{
			if(find(a) == find(b))
				puts("Yes");
			else
				puts("No");
		}
	}
	return 0;
}

