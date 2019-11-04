#include <cstdio>
#include <cctype>
#include <vector>
#include <cstring>
#include <algorithm>
#define do(i, x) for (int i = 1; i <= x; ++i)
#define Do(i, x) for (int i = 0; i < x; ++i)
using namespace std;

int read() {
	int x, c;
	while (!isdigit(c = getchar())); x = c - 48;
	while (isdigit(c = getchar())) x = x * 10 + c - 48;
	return x; 
}

const int N = 1010;
int r[N];
int f[N][N], a[N][N];
vector<int> R[11];

int main() {
	freopen("serves.in", "r", stdin);
	freopen("serves.out", "w", stdout);
	int n = read(), m = read();
	memset(f, 0x3f, sizeof f);
	do (i, n)
		f[i][i] = 0;
	do (i, n)
		r[i] = read(), R[r[i]].push_back(i);
	do (i, m) {
		int x = read(), y = read(), t = read();
		f[x][y] = f[y][x] = t;
	}
	do (k, n)
		do (i, n - 1)
			for (int j = i + 1; j <= n; ++j)
				if (f[i][j] > f[i][k] + f[k][j])
					f[i][j] = f[j][i] = f[i][k] + f[k][j];
	int tot = 0;
	do (i, n) {
		int w = 10, mxdis = 0x3f3f3f3f, kmx = 0;
		Do (j, R[w].size())
			mxdis = min(mxdis, f[i][R[w][j]]), ++tot;
		kmx = mxdis;
		for (; w >= r[i]; --w, kmx = mxdis)
			Do (j, R[w].size())
				if (f[i][R[w][j]] < kmx)
					mxdis = min(f[i][R[w][j]], mxdis), ++tot;
	}
	printf("%d\n", tot);
	return 0;
}

