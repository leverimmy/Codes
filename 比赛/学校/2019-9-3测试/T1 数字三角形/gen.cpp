#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <vector>
#include <iostream>
#define rgi register int
#define il inline
#define ll long long

using namespace std;

const int oo = 0x3f3f3f3f;

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

ll random(ll l, ll r)
{
	if(l == r)
		return l;
	return rand() * rand() % (r - l) + l; 
}

int main()
{
	freopen("testdata.in", "w", stdout);
	ll T = random(1LL, 10LL);
	cout << T << endl;
	while(T--)
	{
		ll n = random(1LL, 100LL);
		cout << n << endl;
	}
	return 0;
}

