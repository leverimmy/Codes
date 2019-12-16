#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int N = 1e3 + 10;

int n, ans;
int s[N], f[N];

struct LIGHT {
	int v, k, c, l;
	bool operator < (const struct LIGHT &rhs) const {
		return v < rhs.v;
	}
} light[N];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
	while(n = read()) {
		memset(f, 0x3f, sizeof(f));
		for(rgi i = 1; i <= n; ++i) {
			light[i].v = read();
			light[i].k = read();
			light[i].c = read();
			light[i].l = read();
		}
		std::sort(light + 1, light + n + 1);
		for(rgi i = 1; i <= n; ++i) s[i] = s[i - 1] + light[i].l;
		f[0] = 0;
		for(rgi i = 1; i <= n; ++i)
			for(rgi j = 1; j <= i; ++j)
				f[i] = std::min(f[i], f[j - 1] + (s[i] - s[j - 1]) * light[i].c + light[i].k);
		printf("%d\n", f[n]);
	}
	return 0;
}

