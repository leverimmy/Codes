#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <cctype>
#define rgi register int
#define il inline
#define ll long long
#define maxn 10

using namespace std;

int n, cnt, len;

deque <int> q;

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
	{
		char first[maxn], second[maxn];
		scanf("%s %s", first, second);
		if(first[0] == 'A')
		{
			if(second[0] == 'L')
				q.push_front(++cnt);
			else if(second[0] == 'R')
				q.push_back(++cnt);
		}
		else if(first[0] == 'D')
		{
			int val = read();
			if(second[0] == 'L')
				while(val--)
					q.pop_front();
			else if(second[0] == 'R')
				while(val--)
					q.pop_back();
		}
	}
	len = q.size();
	for(rgi i = 0; i < len; ++i)
		printf("%d\n", q[i]);
	return 0;
}

