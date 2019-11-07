#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register ll
#define il inline

int k, a[20], e[10][10], ans;

bool check() {
	int hang[5] = {0}, lie[5] = {0};
	for(rgi i = 1; i <= 4; ++i)
		for(rgi j = 1; j <= 4; ++j) {
			hang[i] += e[i][j];
			lie[j] += e[i][j];
		}
	if(hang[1] == hang[2] && hang[1] == hang[3] && hang[1] == hang[4])
		if(lie[1] == lie[2] && lie[1] == lie[3] && lie[1] == lie[4])
			return 1;
	return 0;
}

int main() {
	freopen("20.in", "r", stdin);
	freopen("20.out", "w", stdout);
	std::cin >> k;
	for(rgi i = 1; i <= 16; ++i)	a[i] = i;
	do {
		for(rgi i = 1; i <= 4; ++i)
			for(rgi j = 1; j <= 4; ++j)
				e[i][j] = a[(i - 1) * 4 + j];
		if(check())
			ans++;
		if(ans == k) {
			for(rgi i = 1; i <= 4; ++i) {
				for(rgi j = 1; j <= 4; ++j)
					printf("%d ", e[i][j]);
				puts("");
			}
			break;
		}
	} while(std::next_permutation(a + 1, a + 16 + 1));
	return 0;
}

