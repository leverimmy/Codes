#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

using namespace std;

const int oo = 0x3f3f3f3f;

int T;

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

priority_queue <int, vector<int>, greater<int> > h1;
priority_queue <int, vector<int>, less<int> > h2;

int main()
{
	T = read();
	while(T--)
	{
		int id = read(), n = read(), tot = 0;
		while(!h1.empty()) h1.pop();
		while(!h2.empty()) h2.pop();
        printf("%d %d\n", id, n + 1 >> 1);
		for(rgi i = 1; i <= n; ++i)
		{
			int cur = read();
			if(h1.empty())
				h1.push(cur);
			else
			{
				int top1 = h1.top();
				if(cur > top1)
					h1.push(cur);
				else
					h2.push(cur);
				while(h1.size() < h2.size())
					h1.push(h2.top()), h2.pop();
				while(h1.size() > h2.size() + 1)
					h2.push(h1.top()), h1.pop();
			}
			if(i & 1)
			{
				printf("%d ", h1.top()), tot++;
				if(tot % 10 == 0)	puts("");
			}
		}
		puts("");
	}
	return 0;
}

