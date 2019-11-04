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

ll _sum, _xor, _and, cnt;

il ll read()
{
	register ll x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
	_sum = read(), _xor = read();
	_and = (_sum - _xor) >> 1;
	if(_xor > _sum || _and & _xor || _sum - _xor != _and << 1)
		puts("0");
	else
	{
		while(_xor)
		{
			cnt += _xor & 1;
			_xor >>= 1;
		}
		ll ans = (ll)1 << cnt;
		if(!_and)
			ans -= 2;
		printf("%lld\n", ans);
	}
	return 0;
}

