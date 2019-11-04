#include <cstdio>
#include <cctype>
#include <algorithm>
#define long long ll
#define rgi register int
#define il inline

using namespace std;

const int N = 1000 + 10;

int n, suma, sumb;
int a[N];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
// 	freopen("cycle.in", "r", stdin);
// 	freopen("cycle.out", "w", stdout);
	n = read();
	for(rgi i = 1; i <= n; ++i) a[i + n] = a[i] = read();
	for(rgi i = n; i >= 1; --i) if(a[i]) suma++; else break;
	for(rgi i = n + 1; i <= n << 1; ++i) if(a[i])	sumb++; else break;
	if(suma & 1 || sumb & 1) puts("YES");
	else	puts("NO");
	return 0;
}

