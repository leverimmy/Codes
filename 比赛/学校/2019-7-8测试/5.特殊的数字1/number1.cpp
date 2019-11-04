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
	for(rgi i = 1; i <= 9; ++i)
		for(rgi j = 0; j <= 9; ++j)
			for(rgi k = 0; k <= 9; ++k)
				if(i * i * i + j * j * j + k * k * k == 100 * i + 10 * j + k)
					printf("%d\n", 100 * i + 10 * j + k);
	return 0;
}

