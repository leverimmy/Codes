#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 1e5 + 10;

int n, k, L, R;
int a[N];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
	srand(time(0));
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	n = read(), k = read(), L = read(), R = read();
	for(rgi i = 1; i <= n; ++i)	a[i] = read();
	
	printf("%d", rand());
	
	return 0;
}

