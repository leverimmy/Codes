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

int n, last, ans = -oo, tmp;
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
	cin >> n;
	for(rgi i = 1; i <= n; ++i)
		cin >> h[i];
	for(rgi i = 1; i <= n; ++i)
	{
		if(h[i] <= last)
		{
			last = h[i];
			tmp++;
		}
		else
		{
			last = h[i];
			ans = max(ans, tmp);
			tmp = 1;
		}
	}
	ans = max(ans, tmp);
	cout << ans - 1;
	return 0;
}
