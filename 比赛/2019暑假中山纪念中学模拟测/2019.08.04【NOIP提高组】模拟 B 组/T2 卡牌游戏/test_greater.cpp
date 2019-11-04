#include <cstdio>
#include <iostream>
#include <cstring>
#include <cctype>
#include <algorithm>
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
	int a[16];
	for(rgi i = 1; i <= 15; ++i)
		a[i] = -i;
	sort(a + 1, a + 15 + 1);
	for(rgi i = 1; i <= 15; ++i)
		printf("%d ", a[i]);
	return 0;
}

