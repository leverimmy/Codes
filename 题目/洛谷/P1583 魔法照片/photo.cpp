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
#define maxn 20010

using namespace std;

int n, k;
int e[11];

struct node
{
	int id, val;
} p[maxn];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

bool cmp(struct node a, struct node b)
{
	if(a.val == b.val)
		return a.id < b.id;
	else
		return a.val > b.val;
}

int main()
{
	n = read(), k = read();
	for(rgi i = 0; i <= 9; ++i)
		e[i] = read();
	for(rgi i = 0; i < n; ++i)
	{
		p[i].id = i + 1;
		p[i].val = read();
	}
	sort(p, p + n, cmp);
	for(rgi i = 0; i < n; ++i)
		p[i].val += e[i % 10];
	sort(p, p + n, cmp);
	for(rgi i = 0; i < k; ++i)
		printf("%d ", p[i].id);
	return 0;
}

