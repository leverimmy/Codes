#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register ll
#define il inline

const int oo = 0x3f3f3f3f;
const int N = 100 + 10;

int n, w, sum, u[N];
double p[N], s[N], f[N][N];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
	freopen("pb.in", "r", stdin);
	freopen("pb.out", "w", stdout);
	n = read(), w = read();
	for(rgi i = 1; i <= n; ++i)	u[i] = read(), sum += u[i];
	for(rgi i = 1; i <= n; ++i)	p[i] = u[i] * 1.0 / sum;
	std::sort(p + 1, p + n + 1, std::greater <double> ()); 
	for(rgi i = 1; i <= n; ++i)	s[i] = s[i - 1] + p[i];
	
	for(rgi i = 1; i <= n; ++i)	f[i][1] = i * s[i];
	
	for(rgi i = 2; i <= n; ++i)
		for(rgi j = 2; j <= i; ++j) {
			f[i][j] = oo;
			for(rgi k = j; k <= i; ++k)
				f[i][j] = std::min(f[i][j], f[k - 1][j - 1] + i * (s[i] - s[k - 1])); 
		}
	printf("%.4f", f[n][w]);
	return 0;
}
/*
f[i][j]表示p[1...i]划了j次

枚举前面的上一个挡板的位置k 
f[i][j] = f[i - k][j - 1] + (j - k) * (s[j] - s[k - 1])

5 2
30 5 10 30 25

*/

