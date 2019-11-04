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
#define maxn 1000

using namespace std;

int n, time, cnt = 1;

struct node
{
	int begin, end;
} e[maxn];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

bool cmp(struct node a, struct node b)
{
	return a.end < b.end;
}

int main()
{
	n = read();
	for(rgi i = 1; i <= n; ++i)
	{
		e[i].begin = read();
		e[i].end = read();
	}
	sort(e + 1, e + n + 1, cmp);
	time = e[1].end;
	for(rgi i = 2; i <= n; ++i)
	{
		if(e[i].begin >= time)
		{
			cnt++;
			time = e[i].end;
		}
	}
	printf("%d", cnt);
	return 0;
}

