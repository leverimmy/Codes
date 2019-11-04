#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register int

using namespace std;

const int N = 100000 + 10;

int n, flag;
int h[N];

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
		h[i] = read();
	for(rgi i = n; i >= 2; --i)
	{
		if(h[i] < h[i - 1])
			h[i - 1]--;
	}
	for(rgi i = 1; i <= n - 1; ++i)
		if(h[i + 1] < h[i])
		{
			flag = 1;
			break;
		}
	if(flag)
		printf("No");
	else
		printf("Yes");
	return 0;
}

