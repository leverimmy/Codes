#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) { return b ? a / b + gcd(b, a % b) : 0; }
int main() {
	freopen("seq.in", "r", stdin);
	freopen("seq.out", "w", stdout);
	ll a, b; scanf("%lld%lld", &a, &b);
	return !printf("%lld\t", 1 + gcd(a, b));
}
