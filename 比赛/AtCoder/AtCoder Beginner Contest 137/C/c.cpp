#include <cstdio>
#include <cstring>
#include <cctype>
#include <iostream>
#include <map>
#include <string>
#include <set>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register ll

using namespace std;

const int N = 100000 + 10;

ll n, cnt, ans;

set <string> s;

map <string, ll> vis;

il ll read()
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
		string str;
		cin >> str;
		sort(str.begin(), str.end());
		s.insert(str);
		vis[str]++;
	}
	for(set <string> :: iterator it = s.begin(); it != s.end(); ++it)
		ans += vis[*it] * (vis[*it] - 1) / 2;
	printf("%lld", ans);
	return 0;
}
