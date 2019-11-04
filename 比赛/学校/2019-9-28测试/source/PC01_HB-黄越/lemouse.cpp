#include <queue>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1002, M = 1002;
int f[N][M], a[N][M];
struct E { int x, y; E(int a=0, int b=0): x(a), y(b) {} };
queue<E> q;

bool update(int i, int j) {
	if (       f[i][j]>min(f[i-1][j]+a[i+1][j+1]+a[i+1][j]+a[i+1][j-1],f[i][j-1]+a[i-1][j+1]+a[i][j+1]+a[i+1][j+1]))
		return f[i][j]=min(f[i-1][j]+a[i+1][j+1]+a[i+1][j]+a[i+1][j-1],f[i][j-1]+a[i-1][j+1]+a[i][j+1]+a[i+1][j+1]), 1;
	return 0;
}

int read() {
	int x, c;
	while (!isdigit(c = getchar())); x = c - 48;
	while (isdigit(c = getchar())) x = x * 10 + c - 48;
	return x; 
}

int main() {
	freopen("lemouse.in", "r", stdin);
	freopen("lemouse.out", "w", stdout);
	int n = read(), m = read();
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			a[i][j] = read();
	memset(f, 0x3f, sizeof f); f[1][1] = a[1][1] + a[1][2] + a[2][1] + a[2][2];
	for (q.push(E(1, 1)); q.size();) {
		E x = q.front(); q.pop();
		if (x.x > n || x.y > m) continue;
		if (update(x.x + 1, x.y))
			q.push(E(x.x + 1, x.y));
		if (update(x.x, x.y + 1))
			q.push(E(x.x, x.y + 1));
	}
	printf("%d\n", f[n][m]);
	return 0;
}
