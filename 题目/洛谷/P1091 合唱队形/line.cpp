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
#define maxn 110

using namespace std;

int n, ans;
int t[maxn], f1[maxn], f2[maxn];

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
		t[i] = read();
	for(rgi i = 1; i <= n; ++i)
		for(rgi j = 0; j < i; ++j)
			if(t[i] > t[j])
				f1[i] = max(f1[i], f1[j] + 1);
	for(rgi i = n; i >= 0; --i)
		for(rgi j = n + 1; j > i; --j)
			if(t[i] > t[j])
				f2[i] = max(f2[i], f2[j] + 1);
	for(rgi i = 1; i <= n; ++i)
		ans = max(ans, f1[i] + f2[i] - 1);
	printf("%d", n - ans);
	return 0;
}

