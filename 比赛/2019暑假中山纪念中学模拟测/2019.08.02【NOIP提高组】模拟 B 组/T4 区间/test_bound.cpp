#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cctype>
#define ll long long
#define il inline
#define rgi register int

using namespace std;

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
	int a[11] = {0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
	printf("%d %d\n", upper_bound(a + 1, a + 12, 3, greater <int> ()) - a, upper_bound(a + 1, a + 12, 3) - a);
	printf("%d %d\n", lower_bound(a + 1, a + 12, 3, greater <int> ()) - a, lower_bound(a + 1, a + 12, 3) - a);
	return 0;
}

