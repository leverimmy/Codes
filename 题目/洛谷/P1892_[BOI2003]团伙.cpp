#include <cstdio>
#include <cstring>
#define rgi register int
#define il inline
#define ll long long
#define maxn 1010

using namespace std;

int n, q;
int p[maxn];

il void init(int x)
{
	for(rgi i = 1; i <= x; i++)
		p[i] = i;
}

il int _find(int x)
{
	return x == p[x] ? x : p[x] = find(p[x]);
}

il void _union(int a, int b)
{
	int pa = find(a), pb = find(b);
	if(pa != pb)
		p[pb] = pa;
}

int main()
{
	scanf("%d %d", &n, &q);
	init(n);
	for(rgi i = 1; i <= q; i++)
	{
		char c = ' ';
		while(!isalpha(c))
			c = getchar();
		if(c == 'E')
		{
			int a, b;
			scanf("%d %d", &a, &b);
		}
		else if(c == 'F')
		{
			int a, b;
			scanf("%d%d", &a, &b);
			_union(a, b);
		}
	}
	for(rgi i = 1; i <= n; i++)
		if(p[i] == i)
			cnt++;
	printf("%d", cnt);
	return 0;
}

