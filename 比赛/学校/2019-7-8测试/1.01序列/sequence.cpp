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
	for(rgi a = 0; a <= 1; ++a)
		for(rgi b = 0; b <= 1; ++b)
			for(rgi c = 0; c <= 1; ++c)
				for(rgi d = 0; d <= 1; ++d)
					for(rgi e = 0; e <= 1; ++e)
						for(rgi f = 0; f <= 1; ++f)
							printf("%d%d%d%d%d%d\n", a, b, c, d, e, f);
	return 0;
}

