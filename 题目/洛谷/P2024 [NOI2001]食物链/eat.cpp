#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 5e4 + 10;

int n, k, cnt;
int p[N * 3];
/*
* p[i] -> p[i].self
* p[i + n] -> p[i].eat
* p[i + n * 2] -> p[i].enemy
*/

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void init()
{
	for(rgi i = 1; i <= n * 3; ++i)
		p[i] = i; 
}

int Find(int x)
{
	return x == p[x] ? x : p[x] = Find(p[x]); 
}

void Union(int a, int b)
{
	int pa = Find(a);
	int pb = Find(b);
	if(pa != pb)
		p[pa]= pb;
}

int main()
{
	n = read(), k = read();
	init();
	for(rgi i = 1; i <= k; ++i)
	{
		int op = read(), x = read(), y = read();
		if(x > n || y > n)
		{
			cnt++;
			continue;
		}
		if(op == 1)
		{
			if(Find(x + n) == Find(y) || Find(x) == Find(y + n))
			{
				cnt++;
				continue;
			}
			Union(x, y);
			Union(x + n, y + n);
			Union(x + n * 2, y + n * 2);
		}
		else if(op == 2)
		{
			if(Find(x) == Find(y) || Find(x) == Find(y + n))
			{
				cnt++;
				continue;
			}
			Union(x, y + 2 * n);
			Union(x + n, y);
			Union(x + 2 * n, y + n);
		}
	}
	printf("%d", cnt);
	return 0;
}

