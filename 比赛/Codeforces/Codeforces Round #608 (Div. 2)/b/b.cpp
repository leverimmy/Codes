#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int N = 200 + 10;

int n, a[N], b[N];
char str[N];

std::vector <int> pos;

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
	n = read();
	scanf("%s", str + 1);
	for(rgi i = 1; i <= n; ++i) a[i] = str[i] == 'B';
	for(rgi i = 1; i <= n; ++i) b[i] = str[i] == 'B';
	for(rgi i = 1; i <= n - 1; ++i) {
		if(a[i] != 1) {
			a[i] ^= 1;
			a[i + 1] ^= 1;
			pos.push_back(i);
		}
	}
	if(a[n] == 1) {
		printf("%d\n", pos.size());
		for(rgi i = 0; i < pos.size(); ++i) printf("%d ", pos[i]);
		return 0;
	}
	pos.clear();
	for(rgi i = 1; i <= n - 1; ++i) {
		if(b[i] != 0) {
			b[i] ^= 1;
			b[i + 1] ^= 1;
			pos.push_back(i);
		}
	}
	if(b[n] == 0) {
		printf("%d\n", pos.size());
		for(rgi i = 0; i < pos.size(); ++i) printf("%d ", pos[i]);
		return 0;
	}
	printf("-1");
	return 0;
}

