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

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
	int n, k, ans = 0;
	int h[(int)1e5 + 10];
	n = read(), k = read();
	for(rgi i = 1; i <= n; ++i) h[i] = read();
	for(rgi i = 1; i <= n; ++i) ans += (h[i] >= k);
	printf("%d", ans);
	return 0;
}

