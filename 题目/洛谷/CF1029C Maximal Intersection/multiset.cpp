#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>
#include <cctype>
#define rgi register int
#define il inline
#define ll long long
#define maxn 300010

using namespace std;

int n, ans;
int l[maxn], r[maxn];

multiset <int> left, right;

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
		l[i] = read();
		r[i] = read();
		left.insert(l[i]);
		right.insert(r[i]);
	}
	for(rgi i = 1; i <= n; ++i)
	{
		left.erase(left.find(l[i]));
		right.erase(right.find(r[i]));
		ans = max(ans, *right.begin() - *left.rbegin());
		left.insert(l[i]);
		right.insert(r[i]);
	}
	printf("%d", ans);
	return 0;
}

