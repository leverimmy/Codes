#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int oo = 0x3f3f3f3f;
const double PI = acos(-1);
const int N = 1e7 + 10;

int n, m;
double Cos[N], Sin[N];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

struct complex {
	double a, b;
	il struct complex operator + (const struct complex &rhs)
		const {return complex {a + rhs.a, b + rhs.b};}
	il struct complex operator - (const struct complex &rhs)
		const {return complex {a - rhs.a, b - rhs.b};}
	il struct complex operator * (const struct complex &rhs)
		const {return complex {a * rhs.a - b * rhs.b, a * rhs.b + b * rhs.a};}
	/*struct complex operator / (const struct complex &rhs)
		const {return complex {
			(a * rhs.a + b * rhs.b) / (rhs.a * rhs.a + rhs.b * rhs.b),
			(b * rhs.a - a * rhs.b) / (rhs.a * rhs.a + rhs.b * rhs.b)
		};}*/
} A[N << 1], B[N << 1], F[N << 1], tmp[N << 1];

void DFT(struct complex *f, int len) {
	if(len == 1)	return;
	struct complex *fl = f, *fr = f + (len >> 1);
	for(rgi i = 0; i < len; ++i)	tmp[i] = f[i];
	for(rgi i = 0; i < len >> 1; ++i)	fl[i] = tmp[i << 1], fr[i] = tmp[i << 1 | 1];	
	DFT(fl, len >> 1), DFT(fr, len >> 1);
	
	struct complex root = complex{1, 0};
	struct complex delta = complex{Cos[len], Sin[len]};
	
	for(rgi i = 0; i < len >> 1; ++i) {
		struct complex cur = root * fr[i];
		tmp[i] = fl[i] + cur;
		tmp[i + (len >> 1)] = fl[i] - cur;
		root = root * delta;
	}
	for(rgi i = 0; i < len; ++i)	f[i] = tmp[i];
}

void IDFT(struct complex *f, int len) {
	if(len == 1)	return;
	struct complex *fl = f, *fr = f + (len >> 1);
	for(rgi i = 0; i < len; ++i)	tmp[i] = f[i];
	for(rgi i = 0; i < len >> 1; ++i)	fl[i] = tmp[i << 1], fr[i] = tmp[i << 1 | 1];	
	IDFT(fl, len >> 1), IDFT(fr, len >> 1);
	
	struct complex root = complex{1, 0};
	struct complex delta = complex{Cos[len], -Sin[len]};
	
	for(rgi i = 0; i < len >> 1; ++i) {
		struct complex cur = root * fr[i];
		tmp[i] = fl[i] + cur;
		tmp[i + (len >> 1)] = fl[i] - cur;
		root = root * delta;
	}
	for(rgi i = 0; i < len; ++i)	f[i] = tmp[i];
}

int main() {
	n = read(), m = read();
	
	for(rgi i = 0; i <= n; ++i)	scanf("%lf", &A[i].a);
	for(rgi i = 0; i <= m; ++i)	scanf("%lf", &B[i].a);
	
	for(m += n, n = 1; n <= m; n <<= 1);
	
	for(rgi i = 1; 1 << i - 1 <= n; ++i)	Cos[1 << i] = cos(PI / (1 << i - 1)), Sin[1 << i] = sin(PI / (1 << i - 1));
	
	DFT(A, n), DFT(B, n);
	
	for(rgi i = 0; i < n; ++i)	F[i] = A[i] * B[i];
	
	IDFT(F, n);
	
	for(rgi i = 0; i <= m; ++i)	printf("%d ", (int)(F[i].a / n + 0.5));
	
	return 0;
}

