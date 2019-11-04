#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register int

using namespace std;

const int N = 100000 + 10;

int len, ans[N], close[N], cur_l, cur_r;
char str[N];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
	scanf("%s", str + 1);
	len = strlen(str + 1);
	for(rgi i = 1; i <= len; ++i)
	{
		if(str[i] == 'R')
			cur_r = i;
		if(str[i] == 'L')
			close[i] = cur_r;
	}
	for(rgi i = len; i >= 1; --i)
	{
		if(str[i] == 'L')
			cur_l = i;
		if(str[i] == 'R')
			close[i] = cur_l;
	}
	for(rgi i = 1; i <= len; ++i)
	{
		if(str[i] == 'R')
		{
			int pos = close[i];
			int times = pos - i;
			if(times & 1)
				ans[pos - 1]++;
			else
				ans[pos]++;
		}
		else if(str[i] == 'L')
		{
			int pos = close[i];
			int times = i - pos;
			if(times & 1)
				ans[pos + 1]++;
			else
				ans[pos]++;
		}
	}
	for(rgi i = 1; i <= len; ++i)
		printf("%d ", ans[i]);
	return 0;
}

