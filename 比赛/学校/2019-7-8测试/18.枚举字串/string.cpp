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
	for(char a = 'A'; a <= 'D'; ++a)
		for(char b = 'A'; b <= 'D'; ++b)
			for(char c = 'A'; c <= 'D'; ++c)
				for(char d = 'A'; d <= 'D'; ++d)
					printf("%c%c%c%c\n", a, b, c, d);
	return 0;
}

