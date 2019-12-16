#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int DIGIT = 10;

int n, m, digit[DIGIT], f[DIGIT][DIGIT];

void Init() {
	f[0][0] = 1;
	for(rgi i = 1; i <= 8; ++i) // len
		for(rgi j = 0; j <= 9; ++j) { // this digit
			if(j == 4) continue;
			for(rgi k = 0; k <= 9; ++k) f[i][j] += f[i - 1][k];
			f[i][j] -= (j == 6) * f[i - 1][2];
		}
}

int Query(int x) {
	int tot(0), res(0);
	while(x) {digit[++tot] = x % 10; x /= 10;} digit[tot + 1] = 0;
	for(rgi i = tot; i >= 1; --i) { // len
		for(rgi j = 0; j < digit[i]; ++j) { // this digit
			if(j == 4) continue;
			if(j == 2 && digit[i + 1] == 6) continue;
			res += f[i][j];
		}
		if(digit[i] == 4) break;
		if(digit[i] == 2 && digit[i + 1] == 6) break;
	} return res;
}

int main() {
	Init();
	while(scanf("%d %d", &n, &m) && (n || m)) {
		printf("%d\n", Query(m + 1) - Query(n));
	}
	return 0;
}

