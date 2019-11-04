#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 1e5 + 10;

int n;

struct PEO
{
	int id, val;
} p[N];

bool cmp(struct PEO a, struct PEO b)
{
	return a.val < b.val;
}

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
	for(rgi i = 1; i <= n; ++i)
	{
		p[i].val = read();
		p[i].id = i;
	}
	sort(p + 1, p + n + 1, cmp);
	for(rgi i = 1; i <= n; ++i)
		printf("%d ", p[i].id);
	return 0;
}

