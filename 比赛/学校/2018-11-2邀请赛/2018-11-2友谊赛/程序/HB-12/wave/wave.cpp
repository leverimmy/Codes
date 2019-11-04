#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
using namespace std;

bool map[1010][1010];

int main() {
	freopen("wave.in", "r", stdin);
	freopen("wave.out", "w", stdout);
	int n, ans = 0; scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		for (int j = 0; j < x; ++j)
			for (int k = 0; k < y; ++k)
				map[j][k] = false;
		for (int j = 0; j <= y; ++j)
			map[x][j] = true;
		for (int j = 0; j <= x; ++j)
			map[j][y] = true;
	}
	for (int i = 1; i <= 1000; ++i) {
		int j = 1;
		while (j < 1000) {
			int cnt = 0;
			while (!map[i][j++] && j <= 1000); --j;
			while (map[i][j++] && j <= 1000) ++cnt; --cnt; --j;
			ans += (cnt < 0 ? 0 : cnt);
		}
	}
	for (int i = 1; i <= 1000; ++i) {
		int j = 1;
		while (j < 1000) {
			int cnt = 0;
			while (!map[j++][i] && j <= 1000); --j;
			while (map[j++][i] && j <= 1000) ++cnt; --cnt; --j;
			ans += (cnt < 0 ? 0 : cnt);
		}
	}
	printf("%d", ans);
	//system("pause");
	return 0;
}