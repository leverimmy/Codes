#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int oo = 0x3f3f3f3f;
const double PI = acos(-1);
const int N = 2e5 + 10;

int n, m, a[N];
char stra[N], strb[N];

struct complex {
	double a, b;
	struct complex operator + (const struct complex &rhs)
		const {return complex {a + rhs.a, b + rhs.b};}
	struct complex operator - (const struct complex &rhs)
		const {return complex {a - rhs.a, b - rhs.b};}
	struct complex operator * (const struct complex &rhs)
		const {return complex {a * rhs.a - b * rhs.b, a * rhs.b + b * rhs.a};}
} A[N << 1], B[N << 1], F[N << 1], tmp[N << 1];

void DFT(struct complex *f, int len) {
	if(len == 1)	return;
	struct complex *fl = f, *fr = f + len / 2;
	for(rgi i = 0; i < len; ++i)	tmp[i] = f[i];
	for(rgi i = 0; i < len / 2; ++i) {
		fl[i] = tmp[i << 1];
		fr[i] = tmp[i << 1 | 1];	
	}
	DFT(fl, len >> 1), DFT(fr, len >> 1);
	
	struct complex root = complex{1, 0};
	struct complex delta = complex{cos(2 * PI / len), 
								   sin(2 * PI / len)};
	
	for(rgi i = 0; i < len / 2; ++i) {
		tmp[i] = fl[i] + root * fr[i];
		tmp[i + len / 2] = fl[i] - root * fr[i];
		root = root * delta;
	}
	for(rgi i = 0; i < len; ++i)	f[i] = tmp[i];
}

void IDFT(struct complex *f, int len) {
	if(len == 1)	return;
	struct complex *fl = f, *fr = f + len / 2;
	for(rgi i = 0; i < len; ++i)	tmp[i] = f[i];
	for(rgi i = 0; i < len / 2; ++i) {
		fl[i] = tmp[i << 1];
		fr[i] = tmp[i << 1 | 1];	
	}
	IDFT(fl, len >> 1), IDFT(fr, len >> 1);
	
	struct complex root = complex{1, 0};
	struct complex delta = complex{cos(2 * PI / len), -sin(2 * PI / len)};
	
	for(rgi i = 0; i < len / 2; ++i) {
		tmp[i] = fl[i] + root * fr[i];
		tmp[i + len / 2] = fl[i] - root * fr[i];
		root = root * delta;
	}
	
	for(rgi i = 0; i < len; ++i)	f[i] = tmp[i];
}

int main() {
	scanf("%d", &n); m = n - 1, n = m;
	scanf("%s", stra);
	scanf("%s", strb);
	for(rgi i = 0; i <= n; ++i)	A[i].a = stra[i] - '0';
	for(rgi i = 0; i <= m; ++i)	B[i].a = strb[i] - '0';
	
	for(m += n, n = 1; n <= m; n <<= 1);
	
	DFT(A, n), DFT(B, n);
	
	for(rgi i = 0; i < n; ++i)	F[i] = A[i] * B[i];
	
	IDFT(F, n);
	
	while(!F[m - 1].a && m > 1)	m--;
	
	for(rgi i = 0; i <= m; ++i)	a[i] = (int)(F[i].a / n + 0.5);
	
	for(rgi i = m; i >= 1; --i)	if(a[i] >= 10) {
		a[i - 1] += a[i] / 10;
		a[i] %= 10;
	}
	
	for(rgi i = 0, flag = 0; i <= m; ++i)	{
		if(a[i])	flag = 1;
		if(flag)	printf("%d", a[i]);
	}
	
	return 0;
}

