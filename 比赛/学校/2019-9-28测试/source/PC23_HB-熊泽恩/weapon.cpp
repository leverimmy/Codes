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
const int N = 1e5 + 10;

int n, f, cnt;
int p[N];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
	freopen("weapon.in", "r", stdin);
	freopen("weapon.out", "w", stdout);
	n = read(), f = read();
	for(rgi i = 1; i <= n; ++i)	p[i] = read(); 
	for(rgi a = 1; a <= n; ++a)
		for(rgi len = 1; a + len * 2 + f - 1 <= n; ++len)
		{
			int flag = 0;
			for(rgi i = 0; i < len; ++i)
				if(p[a + i] != p[a + len + f + i])
				{
					flag = 1;
					break;
				}
			if(flag)
				continue;
			else
				cnt++;
			/*if(H[a + len - 1] == H[a + len * 2 + f - 1])
				cnt++;*/
		}
	printf("%d", cnt);
	return 0;
}
/*
11 4
1 1 1 4 1 -8 1 1 1 4 1

*/
