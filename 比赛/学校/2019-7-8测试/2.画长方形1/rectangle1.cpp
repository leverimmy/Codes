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

const char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main()
{
	int n = 25, m = 18;
	for(rgi i = 1; i <= n; ++i)
	{
		for(rgi j = 1; j <= m; ++j)
		{
			if(j >= i)
			{
				printf("%c", alpha[j - i]);
			}
			else
				printf("%c", alpha[i - j]);
		}
		puts("");
	}
	return 0;
}

