#include <cstring>
#include <algorithm>
#include <cstdio>

typedef long long ll;
const int N = 200010;
const ll INFLL = 3e18;
int _w;

int n, k, a[N];
ll ans;

int right[N];
void prelude() {
	for( int i = n; i >= 1; --i )
		if( a[i] == 1 )
			right[i] = a[i+1] == 1 ? right[i+1] : i;
}

bool check( ll a, ll b ) {
	return 1.0 * a * b <= INFLL;
}

ll solve( int L ) {
	ll p = 1, s = 0, ans = 0;
	for( int i = L; i <= n; ++i )
		if( a[i] == 1 ) {
			int R = right[i];
			int cnt = R-i+1;
			if( p % k == 0 ) {
				ll tmp = p/k-s;
				if( tmp >= 1 && tmp <= cnt )
					++ans;
			}
			i = R, s += cnt;
		} else {
			if( !check(p, a[i]) ) break;
			p *= a[i], s += a[i];
			if( p % k == 0 && p/k == s )
				++ans;
		}
	return ans;
}

int main() {
		freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);	
	_w = scanf( "%d%d", &n, &k );
	for( int i = 1; i <= n; ++i )
		_w = scanf( "%d", a+i );
	prelude();
	for( int i = 1; i <= n; ++i )
		ans += solve(i);
	printf( "%lld\n", ans );
	return 0;
}
