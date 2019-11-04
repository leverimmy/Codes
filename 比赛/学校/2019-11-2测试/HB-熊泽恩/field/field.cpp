#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

using namespace std;

ll n, m, L, X, Y;
ll A, B, C, La, Lb, Ra, Rb;

il ll read() {
	rgl x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

ll exgcd(ll &x, ll &y, ll a, ll b) {
	if(!b) {
		x = 1;
		y = 0;
		return a;
	}
	ll r = exgcd(x, y, b, a % b);
	
	ll tx = x;
	x = y;
	y = tx - a / b * y;
	
	return r;
}

int main() {
//	freopen("field.in", "r", stdin);
//	freopen("field.out", "w", stdout);
	n = read(), m = read(), L = read();
	
	La = 1, Lb = 1;
	Ra = ceil(m / L), Rb = ceil(n / L);
	A = n + L, B = -(m + L), C = m - n;
	
//	printf("%lld %lld %lld\n", A, B, C);
//	printf("%lld %lld %lld %lld", La, Ra, Lb, Rb);
	
	if(A == 0 && B == 0) {
		if(C != 0 || La > Ra || Lb > Rb)
			puts("0");
		else
			printf("%lld", (Ra - La + 1) * (Rb - Lb + 1));
		return 0;
	}
	if(A == 0) {
		if(C % B || La > Ra || Lb > Rb)
			puts("0");
		else
			puts("1");
		return 0;
	}
	if(B == 0) {
		if(C % A || La > Ra || Lb > Rb)
			puts("0");
		else
			puts("1");
		return 0;
	}
	
	ll g = exgcd(X, Y, A, B);
	
	if(C % g || La > Ra || Lb > Rb)
		puts("0");
	else {
		C /= g;
	}
	
	return 0;
}

