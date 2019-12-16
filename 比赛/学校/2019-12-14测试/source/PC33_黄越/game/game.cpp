#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;

int read() {
	int x, c;
	while (!isdigit(c = getchar())); x = c - 48;
	while (isdigit(c = getchar())) x = x * 10 + c - 48;
	return x;
}

int f[8200][2];
int n, s, a[20];

int dfs(int left = s, int now = 1) {
	printf("dfs(%d, %d)\n", left, now);
	if (~f[left][now]) return f[left][now];
	if (left == 1)
		return !(now & 1);
	bool yes = true;
	for (int i = 1; i <= a[now]; ++i)
		if (left - i > 0)
			yes &= dfs(left - i, now + 1 > (n << 1) ? 1 : now + 1);
	return f[left][now & 1] = yes;
}

int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	while (n = read()) {
		s = read();
		for (int i = 1; i <= (n << 1); ++i)
			a[i] = read();
		memset(f, -1, sizeof f);
		printf("%d\n", dfs());
	}
	return 0;
}
