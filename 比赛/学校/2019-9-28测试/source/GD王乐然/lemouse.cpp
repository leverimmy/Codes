// Leran Wang, 2019/09/27, prepared for scoring 0
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define MAXX 1020
#define INF 0x3f3f3f3f
int n, m, nm[MAXX][MAXX], d[MAXX][MAXX][2];

void dp() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			if (i * j == 1) continue;
			d[i][j][0] = min(d[i][j - 1][0] + nm[i - 1][j], d[i][j - 1][1]) + nm[i + 1][j] + nm[i][j + 1];
			d[i][j][1] = min(d[i - 1][j][1] + nm[i][j - 1], d[i - 1][j][0]) + nm[i + 1][j] + nm[i][j + 1];			
		}
}

int main() {
	freopen("lemouse.in", "r", stdin);
	freopen("lemouse.out", "w", stdout);
	memset(d, INF, sizeof(d));
	cin >> n >> m;
	// x: 0 - m, y: 0 - n
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> nm[i][j];
			
	d[1][1][0] = d[1][1][1] = nm[1][1] + nm[2][1] + nm[1][2];
	dp();
	cout << min(d[n][m][0], d[n][m][1]) << endl;
	return 0;
}

